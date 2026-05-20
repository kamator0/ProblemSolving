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

int graph[303][303]; // 10 ^ 5 * 10 ^ 2 *3 int 형 초과 x?
int org[303][303];
int nx[303][303];
int n, q;
vector<tuple<int, int, int, int>> qv;

void solution(int c)
{
    // 10 ^ 5 * 10 ^ 6 초과네 ?

    for (int i = 1; i <= n; i++)
    {
        if (i >= c)
            break;
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (j == k)
                    continue;

                if (graph[j][k] > graph[j][i] + graph[i][k])
                {
                    graph[j][k] = (graph[j][i] + graph[i][k]);
                    nx[j][k] = nx[j][i];
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << nx[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    //
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int d;
            cin >> d;
            if (d == 0)
            {
                graph[i][j] = INF;
            }
            else
            {
                graph[i][j] = d;
                //nx[i][j] = j;
            }
        }
    }

    for (int i = 1; i<=n ; i++)
    {
        for(int j= 1; j<=n; j++)
        {
            if(i==j)
                graph[i][j] = 0;
        }
    }


    for (int i = 0; i < q; i++)
    {
        int c, s, e;
        cin >> c >> s >> e;
        qv.push_back({c, s, e, i});
    }

    sort(qv.begin(), qv.end());

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            org[i][j] = graph[i][j];
        }
    }

    int idx = 1;

    vector<pair<int, int>> result;
    for (auto x : qv)
    {
        int s = get<1>(x);
        int e = get<2>(x);
        int c = get<0>(x);
        int cur = get<3>(x);

        while (idx < c)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == j)
                        continue;
                    if (graph[i][j] > graph[i][idx] + graph[idx][j])
                    {
                        graph[i][j] = graph[i][idx] + graph[idx][j];
                    }
                }
            }

            idx++;
        }

        if (graph[s][e] == INF)
            result.push_back({cur, -1});
        else
            result.push_back({cur, graph[s][e]});

        // if (idx != c)
        // {

        //     for (int i = 1; i <= n; i++)
        //     {
        //         for (int j = 1; j <= n; j++)
        //         {
        //             org[i][j] = graph[i][j];
        //         }
        //     }

        //     solution(c);

        //     idx = c;

        //     if (graph[s][e] == INF)
        //         result.push_back({cur, -1});
        //     else
        //         result.push_back({cur, graph[s][e]});
        // }
        // else
        // {
        //     if (graph[s][e] == INF)
        //         result.push_back({cur, -1});
        //     else
        //         result.push_back({cur, graph[s][e]});
        // }
    }

    // solution();

    sort(result.begin(), result.end());

    for (auto x : result)
    {
        cout << x.second << "\n";
    }
}
