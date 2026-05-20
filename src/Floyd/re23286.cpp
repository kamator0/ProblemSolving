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

#define INF 0x3f3f3f3f // 경우에 따라 다르게
// long long 일

using namespace std;

int n,m,t; 
int graph[303][303];
vector<pair<int,int>> p; 

void solution()
{
    for(int i =1 ; i<=n ; i++)
    {
        for(int j =1 ; j<=n ; j++)
        {
            for(int k =1 ; k<=n ; k++)
            {
                if(j==k)
                    continue;
                graph[j][k] = min(graph[j][k], max(graph[j][i],graph[i][k]));
            }
        }
    }

    for(auto x : p )
    {
        int s = x.first;
        int e = x.second;
        if(graph[s][e] == INF)
        {
            cout << - 1<<"\n";
            continue;
        }
        cout << graph[s][e] <<"\n";

    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m >>t ;

    for(int i = 1; i<=n ; i++)
    {
        for(int j =1 ; j<=n ; j++)
        {
            graph[i][j] = INF;
        }
    }



    for(int i = 0 ; i< m; i++)
    {
        int u,v,h ;
        cin >> u >> v >> h ;
        graph[u][v] = h;
    }



    for(int i =0; i<t; i++)
    {
        int s , e ;
        cin >> s >> e ;
        p.push_back({s,e});
    }

    solution();
    
}

