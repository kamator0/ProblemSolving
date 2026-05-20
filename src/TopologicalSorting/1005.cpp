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

using namespace std;

int t;
int n, k, w;
vector<int> result;

void solution(vector<int> graph[],
              vector<int> &indegree,
              vector<int> &bcnt)
{
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push({i, bcnt[i]});
        }
    }

    vector<int> bcopy = bcnt;

    while (!q.empty())
    {
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();

        if (cur == w)
        {
            result.push_back(bcopy[cur]);
            break;
        }

        for (int nx : graph[cur])
        {
            indegree[nx]--;
            bcopy[nx] = max(bcopy[nx], bcnt[nx] + d);
            if (indegree[nx] == 0)
            {
                q.push({nx, bcopy[nx]});
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << bcopy[i] << " ";
    // }
    // cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;

        vector<int> graph[n + 1];
        vector<int> indegree(n + 1, 0);
        vector<int> bcnt(n + 1, 0);

        for (int j = 1; j <= n; j++)
        {
            int d;
            cin >> d;
            bcnt[j] = d;
        }

        for (int j = 0; j < k; j++)
        {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            indegree[y]++;
        }

        cin >> w;

        // for (int j = 1; j <= n; j++)
        // {
        //     cout << bcnt[j] << " ";
        // }
        // cout << "\n";
        solution(graph, indegree, bcnt);
    }

    for (int a : result)
    {
        cout << a << "\n";
    }
}
