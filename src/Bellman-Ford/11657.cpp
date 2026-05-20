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

#define INF 1e18 // 경우에 따라 다르게
// long long 일

using namespace std;

int n, m;
long long dist[501]; // 6000 -10000  
vector<tuple<int, int, int>> edge;

bool solution(int start)
{
    dist[start] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto [s, e, t] : edge)
        {
            if (dist[s] == INF)
                continue;
            if (dist[e] > dist[s] + t)
            {
                dist[e] = dist[s] + t;
            }
        }
    }
    for (auto [s, e, t] : edge)
    {
        if (dist[s] == INF)
            continue;
        if (dist[e] > dist[s] + t)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({a, b, c});
    }

    fill(dist, dist + n + 1, INF);

    if (solution(1))
    {
        cout << -1 << "\n";
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (dist[i] == INF)
            {
                cout << -1 << "\n";
            }
            else
                cout << dist[i] << "\n";
        }
    }
}
