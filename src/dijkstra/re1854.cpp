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

#define INF 1e18 // 경우에 따라 다르게
// long long 일

using namespace std;

long long cnt[101][1001];
vector<pair<int,int>> adj[1001];
int n,m, k;

void solution()
{
    for(int i = 1; i<=k ; i++)
    {
        for(int j = 1; j<=n;j ++)
            cnt[i][j] = INF;
    }

    cnt[1][1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq[k+1];
   
    pq[1].push({cnt[1][1],1});

    while(pq[k+1].size() !=  n)
    {
        
    }


    

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k ;

    for(int i = 0 ;  i < m ; i ++)
    {
        int a,b,c ;
        cin >> a >> b >> c ;
        adj[a].push_back({c,b});

    }

    solution();
    
}

