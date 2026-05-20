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
vector<tuple<int, int, int>> edge;
int dist[501];

bool solution()
{
    fill(dist,dist+n+1,0);

    bool cycle = false;
    for (int i = 1; i <= n; i++)
    {
        for (auto [s, e, t] : edge)
        {
            if (dist[e] > dist[s] + t)
            {
                dist[e] = dist[s] + t;
                if (i == n)
                {
                    cycle = true;
                    return cycle;
                }
            }
        }
    }

    return cycle;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        cin >> n >> m >> w;
        //vector<long long> dist(n + 1, INF);

        edge.clear();
        for (int i = 0; i < m; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edge.push_back({s, e, t});
            edge.push_back({e, s, t});
        }

        for (int i = 0; i < w; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edge.push_back({s, e, -t});
        }

        if (solution())
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }

       
    }
}
