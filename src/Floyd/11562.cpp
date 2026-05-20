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
int graph[251][251];
int k;
int ss = INF;
vector<pair<int, int>> q;

void find(int cur, int e, int cnt, vector<int> &visited)
{
    //cout << cur << " " << e << " " << cnt << "\n";
    if (cur == e)
    {
        // cout << cnt <<"\n";
        ss = min(ss, cnt);
        return;
    }

    // visited[cur] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (cur == i)
            continue;
        if (visited[i] == 1)
            continue;
        if (graph[cur][i] == 1)
        {
            visited[i] = 1;
            find(i, e, cnt, visited);
            visited[i] = 0;
        }
        else
        {
            if (graph[i][cur] == 1)
            {
                visited[i] = 1;
                find(i, e, cnt + 1, visited);
                visited[i] = 0;
            }
        }
    }

    return;
}

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
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }


    for(auto x : q)
    {
        int s = x.first;
        int e = x.second;
        
        if(s==e)
        {
            cout << 0 <<"\n";
            continue;
        }

        cout << graph[s][e] <<"\n";


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

    // s == e 라면 0
    // graph[s][e] != INF 0

    // 한번에 못가면 할 수있는거 연결 했던거 양방향 만들기
    // 1이 아니라면 양방향으로 연결 불가

    // vector<int> result;
    // for (auto x : q)
    // {
    //     int s = x.first;
    //     int e = x.second;
    //     //cout << s << " " << e << "\n";
    //     if (s == e)
    //     {
    //         result.push_back(0);
    //         continue;
    //     }
    //     if (graph[s][e] != INF)
    //     {
    //         result.push_back(0);
    //         continue;
    //     }

    //     // 양방향으로 슥 가능
    //     if (graph[e][s] == 1)
    //     {
    //         result.push_back(1);
    //         continue;
    //     }

    //     vector<int> visited(n + 1, 0);
    //     visited[s] = 1;

    //     // 이제는 탐색?

    //     find(s, e, 0, visited);
    //     // ss = min(ss, find(s,e,0,visited));

    //     result.push_back(ss);

    //     ss = INF;
    // }
    // for (int a : result)
    // {
    //     cout << a << "\n";
    // }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, b;
        cin >> u >> v >> b;
        if (b == 0)
        {
            graph[u][v] = 0;
            graph[v][u] = 1;

        }
        else
        {
            graph[u][v] = 0;
            graph[v][u] = 0;
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int s, e;
        cin >> s >> e;
        q.push_back({s, e});
    }

    solution();
}
