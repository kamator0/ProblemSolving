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

int tc;
int n, m, w;

int graph[501][501];
int wgraph[501][501];
vector<string> ans;

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (j == k)
                    continue;
                if (graph[j][k] > graph[j][i] + graph[i][k])
                {
                    graph[j][k] = graph[j][i] + graph[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (j == k)
                    continue;
                if (wgraph[j][i] == -1 || wgraph[i][k] == -1 )
                    continue;
                if (wgraph[j][k] < wgraph[j][i] + wgraph[i][k])
                {
                    wgraph[j][k] = wgraph[j][i] + wgraph[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] == INF)
            {
                cout << 0 << " ";
                continue;
            }
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
        for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (wgraph[i][j] == -1)
            {
                cout << 0 << " ";
                continue;
            }
            cout << wgraph[i][j] << " ";
        }
        cout << "\n";
    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (wgraph[i][j] == -1)
                continue;

            if (i == j)
            {
                if (wgraph[i][j] != -1)
                {
                    ans.push_back("YES");
                    return;
                }
            }
            if (wgraph[i][j] != -1 && wgraph[j][i] != -1)
            {
                ans.push_back("YES");
                return;
            }

            if (wgraph[i][j] - graph[i][j] > 0)
            {
                ans.push_back("YES");
                return;
            }
        }
    }

    ans.push_back("NO");

    // 1 -> 3 -> 6

    // 웜홀 끼리 이동가능한 경우?
    // 웜홀이 중첩된 경우?

    // for (auto x : wh)
    // {
    //     int t = get<0>(x);
    //     int s = get<1>(x);
    //     int e = get<2>(x);
    //     if (s == e)
    //     {
    //         ans.push_back("YES");
    //         return;
    //     }

    //     if (graph[e][s] == INF)
    //         continue;

    //     if (graph[e][s] - t < 0)
    //     {
    //         ans.push_back("YES");
    //         return;
    //     }
    // }

    // ans.push_back("NO");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        // vector<tuple<int, int, int>> wh;

        cin >> n >> m >> w;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                graph[i][j] = INF;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                wgraph[i][j] = -1;
            }
        }

        for (int j = 0; j < m; j++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            graph[s][e] = min(graph[s][e], t);
            graph[e][s] = min(graph[e][s], t);
        }

        for (int j = 0; j < w; j++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            // wh.push_back({
            //     t,
            //     s,
            //     e,
            // });

            wgraph[s][e] = max(wgraph[s][e], t);

            // int s, e, t ;
            // cin >> s >> e >> t ;
        }

        solution();
    }

    for (auto x : ans)
    {
        cout << x << "\n";
    }
}
