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

int n, k;

int graph[12][12];
int nx[12][12];
vector<int> dst[12][12]; // s-> t 까지 가는데 필요한 경로
int result = INF;

void solution()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (k == j)
                    continue;
                if (graph[j][k] > graph[j][i] + graph[i][k])
                {
                    graph[j][k] = graph[j][i] + graph[i][k];
                    nx[j][k] = nx[j][i];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int idx = i;
            while (j != idx)
            {
                dst[i][j].push_back(idx);
                idx = nx[idx][j];
            }
            dst[i][j].push_back(j);
        }
    }
}

void dfs(int visitcnt, int cnt, int cur, vector<int> &visited)
{
    if (visitcnt == 0)
    {

        //cout << result <<" " << cnt <<"\n";
        result = min(result, cnt);
        
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (cur == i)
            continue;
        if (visited[i] == 1)
            continue;
        int idx = visitcnt;
        vector<int> v = visited;
        for (int d : dst[cur][i])
        {
            if (v[d] != 1)
            {
                idx--;
                v[d] = 1;
            }
        }
        dfs(idx, cnt + graph[cur][i] , i, v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >> t;
            graph[i][j] = t;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            nx[i][j] = j;
            nx[j][i] = i;
        }
    }

    solution();


    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << nx[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // 일단 단방향으로 전부 이어져 있긴 함
    // for (int i = 0; i < n; i++)
    // {
    //     if (i == k)
    //         continue;
    //     for (int a : dst[k][i])
    //     {
    //         cout << a << " ";
    //     }
    //     cout << "\n";
    // }
    vector<int> visited(n, 0);
    visited[k] = 1;

    dfs(n-1, 0, k, visited);


    cout << result <<"\n";
    // graph[k][i] + graph[i][a] + grpah[a][n] ? 모두 방문?
}
