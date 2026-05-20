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

int n, m, q;
int dog_g[505][505]; // 뭉뭉이 괴롭힘 저장
int dog[505];
int graph[505][505]; // 통로 저장
int nx[505][505];    // 경로 저장

vector<pair<int, int>> qv;

void solution()
{
    // 제일 큰 것 먼저 갱신 하는 방법?
    vector<pair<int, int>> dv;
    for (int i = 1; i <= n; i++)
    {
        dv.push_back({dog[i], i});
    }

    sort(dv.begin(), dv.end());



    for (int i = 0; i < dv.size(); i++)
    {
        int idx = dv[i].second;
        for (int j = 1; j <= n; j++)

        {
            for (int k = 1; k <= n; k++)
            {
                if (j == k)
                    continue;
                if (graph[j][k] + dog_g[j][k] > graph[j][idx] + graph[idx][k] + max(dog_g[j][idx], dog_g[idx][k]))
                {
                    graph[j][k] = graph[j][idx] + graph[idx][k];
                    dog_g[j][k] = max(dog_g[j][k], max(dog_g[j][idx], dog_g[idx][k]));
                }
            }
        }
    }



    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)

    //     {
    //         for (int k = 1; k <= n; k++)
    //         {
    //             if (j == k)
    //                 continue;
    //             if (graph[j][k] + dog_g[j][k] > graph[j][i] + graph[i][k] + max(dog_g[j][i], dog_g[i][k]))
    //             {
    //                 graph[j][k] = graph[j][i] + graph[i][k];
    //                 dog_g[j][k] = max(dog_g[j][k], max(dog_g[j][i], dog_g[i][k]));
    //             }
    //         }
    //     }
    // }



    for (auto x : qv)
    {
        int s = x.first;
        int e = x.second;

        if (graph[s][e] == INF)
            cout << -1 << "\n";
        else
            cout << graph[s][e] + dog_g[s][e] << "\n";
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << dog_g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (graph[i][j] == INF)
    //         {
    //             cout << 0 << " ";
    //             continue;
    //         }
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        dog[i] = a;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a][b] = d;
        graph[b][a] = d;
        nx[a][b] = b;
        nx[b][a] = a;
        dog_g[a][b] = max(dog[a], dog[b]);
        dog_g[b][a] = max(dog[a], dog[b]);
    }

    for (int i = 0; i < q; i++)
    {
        int s, t;
        cin >> s >> t;
        qv.push_back({s, t});
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (graph[i][j] == INF)
    //         {
    //             cout << 0 << " ";
    //             continue;
    //         }
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    solution();

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << nx[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}
