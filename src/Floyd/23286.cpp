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

int n, m, t;

int graph[303][303];
int nx[303][303];
vector<pair<int, int>> p;

bool solution(int target, int s, int e)
{

    


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (j == k)
                    continue;
                if (nx[j][k] > nx[j][i] + nx[i][k])
                {
                    nx[j][k] = nx[j][i] + nx[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (nx[i][j] == INF)
            {
                cout << 0 << " ";
                continue;
            }
            cout << nx[i][j] << " ";
        }
        cout << "\n";
    }

    // for (auto x : p)
    // {
    //     int s = x.first;
    //     int e = x.second;

    //     if (graph[s][e] == INF)
    //     {
    //         cout << -1 << "\n";
    //         continue;
    //     }
    // }
    cout << nx[s][e] << " " << target << "\n";

    // 좌표중 최솟값이 갱신 되었는지 확인 해야할듯? 

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, h;
        cin >> u >> v >> h;
        graph[u][v] = min(graph[u][v], h);
        // 중복 안 한다는 조건이 없음?
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            nx[i][j] = graph[i][j];
        }
    }

    for (int i = 0; i < t; i++)
    {
        int s, e;
        cin >> s >> e;
        p.push_back({s, e});
    }

    // 이분탐색???
    vector<int> result;

    for (auto x : p)
    {
        int s = x.first;
        int e = x.second;
        // if (graph[s][e] == INF)
        // {
        //     result.push_back(-1);
        //     continue;
        // }
        int st = 1;
        int en = 1000000;
        int mid = (st + en) / 2;
        int idx = INF;
        cout << s << " " << e << "\n";

        while (st <= en)
        {
            if (!solution(mid, s, e))
            {
                // idx = min(mid, idx);
                st = mid + 1;
                mid = (st + en) / 2;
            }
            else
            {
                en = mid - 1;
                idx = min(mid, idx);
                mid = (st + en) / 2;
            }

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (graph[i][j] > mid)
                    {
                        nx[i][j] = INF;
                        continue;
                    }
                    nx[i][j] = graph[i][j];
                }
            }
        }

        result.push_back(idx);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                nx[i][j] = graph[i][j];
            }
        }
    }

    for (int a : result)
    {
        cout << a << "\n";
    }
}
