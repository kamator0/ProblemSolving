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

int n, m;
int s, d;

void solution(vector<pair<int, int>> adj[], vector<pair<int, int>> badj[])
{
    vector<int> cnt(n, INF); // 0-n
    cnt[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({cnt[s], s});

    while (!pq.empty())
    {
        int w = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (cnt[cur] != w)
            continue;

        for (auto nx : adj[cur])
        {
            if (cnt[nx.second] <= nx.first + cnt[cur])
                continue;
            cnt[nx.second] = nx.first + cnt[cur];
            pq.push({cnt[nx.second], nx.second});
        }
    }

    int remove[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            remove[i][j] = 0;
        }
    }
    // 0 1 5 6
    // 0 2 6

    // s ,
    queue<int> q;
    vector<int> visited(n, 0);
    q.push(d);
    visited[d] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto nx : badj[cur])
        {
            // 중복 된게 있음
            if (cnt[cur] == cnt[nx.second] + nx.first)
            {
                if (visited[nx.second] != 1)
                {
                    q.push(nx.second);
                    visited[nx.second] = 1;
                }
                remove[nx.second][cur] = 1;
            }
        }
    }

    // for(int i = 0 ; i < n; i++)
    // {
    //     for(int j = 0; j<n; j++)
    //     {
    //         cout << remove[i][j] <<" ";
    //     }
    //     cout <<"\n";
    // }

    vector<int> lcnt(n, INF); // 0-n 
    lcnt[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> lpq;
    lpq.push({lcnt[s], s});

    while (!lpq.empty())
    {
        int w = lpq.top().first;
        int cur = lpq.top().second;
        lpq.pop();
        if (lcnt[cur] != w)
            continue;
        for (auto nx : adj[cur])
        {
            if (lcnt[nx.second] <= lcnt[cur] + nx.first)
                continue;
            if (remove[cur][nx.second] == 1)
                continue;
            lcnt[nx.second] = lcnt[cur] + nx.first;
            lpq.push({lcnt[nx.second], nx.second});
        }
    }

    // for(int i = 0 ; i < n; i ++)
    //     cout << lcnt[i] << " ";

    // cout <<"\n";

    if (lcnt[d] == INF)
    {
        cout << -1 << "\n";
    }
    else
        cout << lcnt[d] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        cin >> s >> d;
        vector<pair<int, int>> adj[n];
        vector<pair<int, int>> badj[n];
        for (int i = 0; i < m; i++)
        {
            int u, v, p;
            cin >> u >> v >> p;
            adj[u].push_back({p, v});
            badj[v].push_back({p, u});
        }

        solution(adj, badj);
    }
}
