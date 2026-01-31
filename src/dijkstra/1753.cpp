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

int v,e ;
int k ;
// int graph[20002][20002]; // 20000 * 20000 * 4 = 16 * 10 ^8 
vector<pair<int,int>> graph[20002]; 
int cnt[20002];

void solution()
{
    cnt[k] = 0;
    priority_queue<pair<int,int>> pq;
    // for(int i = 1;  i<=v; i++)
    // {
    //     if(graph[k].s == 0)
    //         continue;             
    //     pq.push({-graph[k][i], i});
    // }

    for(int i = 0 ; i<graph[k].size(); i++)
    {
        int nx  = graph[k][i].first;
        int d = graph[k][i]. second;
        pq.push({-d,nx});
    }

    while(!pq.empty())
    {
        int d = -pq.top().first;
        int nx = pq.top().second;
        
        pq.pop();

    
        if(cnt[nx] != INF)
            continue;
        
        cnt[nx] = d ;
        cout << nx <<" "<< cnt[nx] <<"\n";
        // for(int i =1; i<=v ; i++)
        // {
        //     if(graph[nx][i] == INF)
        //         continue;
        //     if(cnt[i] != INF)
        //         continue;
        //     pq.push({-(graph[nx][i] + cnt[nx]), i});
        // }
        
        for(int i = 0; i<graph[nx].size(); i++)
        {
            int a = graph[nx][i].first;
            if(cnt[a] != INF)
                continue;
            pq.push({-(graph[nx][i].second + cnt[nx]),a});
        }
    
    
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> v >> e ;
    cin >> k ;
    // for(int i = 1 ; i <=v ;i++)
    // {
    //     for(int j = 1; j<=v ; j++)
    //     {
    //         graph[i][j] = INF;
    //     }
    // }

    for(int i =1 ; i<=v ;i++)
        cnt[i] = INF;

    for(int i = 0 ; i < e;  i++)
    {
        int u,v,w;
        cin >>u >> v >> w;
        // graph[u][v] = min(graph[u][v],w); 
        graph[u].push_back({v,w});
    }
    
    solution();

    for(int i = 1 ; i<=v; i++)
    {
        if(cnt[i] == INF)
        {
            cout << "INF" <<"\n";
            continue;
        }
        else
            cout << cnt[i] <<"\n";
    }


}
