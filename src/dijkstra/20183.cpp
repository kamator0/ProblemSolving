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

#define INF 1e15 // 경우에 따라 다르게
// long long 일

using namespace std;

int n, m, a, b;
long long c;
// 교차로 개수 N, 골목 개수 M, 시작 교차로 번호 A, 도착 교차로 번호 B, 가진 돈 C

long long cnt[100001];
//long long max_edge[100001];
vector<pair<long long, int>> adj[100001];

bool canReach(long long maxEdge){
    fill(cnt,cnt+n+1,INF);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
    cnt[a] = 0 ;
    pq.push({cnt[a],a});
    while (!pq.empty())
    {
        long long w = pq.top().first;
        int cur = pq.top().second;

        pq.pop();

        if (cnt[cur] != w)
            continue;

        for(auto nx : adj[cur])
        {
            if(nx.first > maxEdge)
                continue;
            if(cnt[nx.second] <= cnt[cur] + nx.first)
                continue;
            cnt[nx.second] = cnt[cur] + nx.first;
            pq.push({cnt[nx.second],nx.second});
        }
    
    }

    if(cnt[b] > c) 
        return false;
    else 
        return true;

}



void solution()
{

    // 10 ^ 10 * long long // 2차원 배열은 무리 
    // fill(cnt,cnt+n+1,INF);
    // //fill(max_edge,max_edge+n+1,INF);

    // priority_queue<pair<long long, pair<long long,int>>, vector<pair<long long ,pair<long long ,int>>>, greater<pair<long long, pair<long long,int>>>> pq;
    // cnt[a] = 0;
    // max_edge[a] = 0;
    // pq.push({cnt[a], { 0,a}});  // cnt[a] , max_edge m, cur


    // while (!pq.empty())
    // {
    //     long long w = pq.top().first;
    //     int cur = pq.top().second.second;
    //     long long edge = pq.top().second.first;
    //     pq.pop();

    //     if (cnt[cur] != w)
    //         continue;

    //     for (auto nx : adj[cur])
    //     {
    //         if (cnt[cur] + nx.first <= c)
    //         {
    //             edge = max(edge,nx.first);
    //             if(max_edge[nx.second] > edge)
    //             {
    //                 cnt[nx.second] = cnt[cur] +nx.first;
    //                 max_edge[nx.second] = edge;
    //                 pq.push({cnt[nx.second],{max_edge[nx.second],nx.second}});
    //             }
    //         }
            
    //     }
    // }

    // // for(int i = 1 ; i<=n; i++)
    // //     cout << cnt[i] <<" ";
    // // cout <<"\n";

    // if(cnt[b] > c )
    // {
    //     cout << -1 <<"\n";
    //     return ;
    // }


    // cout << max_edge[b] <<"\n";

    long long lo = 0, hi = 1e9 , ans = -1 ;
    while(lo<=hi){
        long long mid = (lo+hi) / 2;
        if(canReach(mid))
        {
            ans = mid ;
            hi = mid - 1; 
        }
        else{
            lo = mid + 1;
        }
    }

    cout << ans <<"\n";

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> a >> b >> c;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long p;
        cin >> u >> v >> p;
        adj[u].push_back({p, v});
        adj[v].push_back({p,u});
    }

    solution();

    
}
