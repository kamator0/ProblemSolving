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

using namespace std;

int n,e;
//vector<pair<int,int>> w; // 논에 우물 팔 때 드는 비용

tuple<int,int,int> edge[100005];
vector<int> p (301, -1);
int edge_count = 0 ;
int result = 0;


int find(int x)
{
    if(p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool uni(int u,int v)
{
    u=find(u);
    v=find(v);
    if(u==v)
        return false;
    
    if(p[u] < p[v])
        p[v] = u;
    else if(p[u] == p[v])
    {
        p[v] = u;
        p[u] --;
    }
    else{
        p[u] =v;
    }
    return true;
}

void solution()
{
    n ++;
    for(int i= 0 ; i< e; i++)
    {
        if(edge_count==n-1)
            return;
        int a,b,d;
        tie(d,a,b) = edge[i];
        if(!uni(a,b))
            continue;
        result+=d;
        edge_count++;
    }



}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;


    for(int i = 1 ;  i <= n; i++)
    {
        int a ;
        cin >> a ;
        edge[e++] = {a,i,n+1};
    }

    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= n; j++)
        {
            int a ; 
            cin >> a ;
            if(i>=j)
                continue;
            edge[e++] = {a,i,j};
        }
    }


    sort(edge,edge+e);
    
    solution();

    cout << result<<"\n";

    
}
