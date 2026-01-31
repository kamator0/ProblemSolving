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

#define INF 1e18

using namespace std;

int n, m, k;
vector<pair<int, int>> adj[10004];
long long  d[21][10004]; // long long? i 번째에서 언재 포장
int pre[10004];

long long  result = INF;

void solution()
{
    /*priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[1] = 0;
    pq.push({d[1],1});
    while (!pq.empty())
    {
        int w = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(d[cur] != w)
            continue;
        for(auto nx : adj[cur])
        {
            if(d[nx.second] <= d[cur] + nx.first)
                continue;
            d[nx.second] = d[cur]+ nx.first;
            pq.push({d[nx.second], nx.second});
        }
    }

    dresult = d[n] ; */
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;
    // 현재 값 ,  다음 노드 ,  포장 가능 수 ?
    d[0][1] = 0; // 포장 0번 사용한 1
    pq.push({d[0][1], {1, 0}});
    while (!pq.empty())
    {
        long long  w = pq.top().first;
        int cur = pq.top().second.first;
        int kcnt = pq.top().second.second;
        pq.pop();

        //cout << w << " " << cur << " " << kcnt << "\n";

        if (d[kcnt][cur] != w)
            continue;

        for (auto nx : adj[cur])
        {
            if (kcnt == k)
            {
                if (d[kcnt][nx.second] <= d[kcnt][cur] + nx.first)
                    continue;
                d[kcnt][nx.second] = d[kcnt][cur] + nx.first;
                pq.push({d[kcnt][nx.second], {nx.second, kcnt}});
                //cout << nx.second << " " << cur << " " << kcnt << "\n";
            }
            else
            {
                if (d[kcnt][nx.second] > d[kcnt][cur] + nx.first)
                {
                    d[kcnt][nx.second] = d[kcnt][cur] + nx.first;
                    pq.push({d[kcnt][nx.second], {nx.second , kcnt}}); 
                    // nx.second + nx.first 라고 씀 ;; 
                    //cout << nx.second << " " << cur << " " << kcnt << "\n";
                }
                if (d[kcnt + 1][nx.second] > d[kcnt][cur])
                {
                    d[kcnt + 1][nx.second] = d[kcnt][cur];
                    pq.push({d[kcnt + 1][nx.second], {nx.second, kcnt + 1}});
                    //cout << nx.second << " " << cur << " " << kcnt +1 << "\n";
                }

                // if(d[kcnt][nx.second] <= d[kcnt][cur] + nx.first)
                // {
                //     d[nx.second] = d[cur] ;
                //     pq.push({d[nx.second],{nx.second,kcnt+1}});
                // }
                // pq.push(d[nx.second],)
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = INF;
        }
    }

    // fill(d, d + n + 1, INF);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w,u});
    }

    solution();

    // for (int i = 0; i <= k; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << d[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // n보다 k가 더 큰 경우가 있어서 d[k][n]이 답이 아닐수도 있다
    for (int i = 0; i <= k; i++)
    {
        result = min(result, d[i][n]);
    }

    cout << result << "\n";
}
