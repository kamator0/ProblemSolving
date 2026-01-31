#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <limits>

#define INF 12345678

using namespace std;
vector<pair<int,int>> adj[20005]; // 가중치 둘째 
bool fix[20005];
int d[20005];
int v= 10;

void navie(int st)
{
    fill(d, d+v+1,INF);
    d[st] = 0;
    while(true)
    {
        int idx = - 1 ;
        for(int i = 1 ; i <=v ; i++)
        {
            if(fix[i]) continue;
            if(idx == -1) idx = i;
            else if(d[i] < d[idx])
                idx = i;
        }
        if(idx == - 1 || d[idx] == INF)
            break;
        fix[idx] = 1 ;
        for (auto nxt : adj[idx]) 
            d[nxt.second] = min(d[nxt.second] , d[idx] + nxt.first);
    }


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
}
