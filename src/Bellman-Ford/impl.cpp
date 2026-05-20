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
int n, m;
vector<tuple<int, int, int>> edge;
int dist[501];

bool solution(int start)
{
    fill(dist, dist + n + 1, INF);
    dist[start] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (auto [s, e, t] : edge)
        {
            if (dist[s] == INF)
                continue;
            if (dist[e] > dist[s] + t)
                dist[e] = dist[s] + t;
        }
    }

    for (auto [s, e, t] : edge)
    {
        if (dist[s] == INF)
            continue;
        if (dist[e] > dist[s] + t)
            return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        cin >> n >> m ;
        // vector<long long> dist(n + 1, INF);

        edge.clear();
        for (int i = 0; i < m; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edge.push_back({s, e, t});
            edge.push_back({e, s, t});
        }

  

        if (solution(1))
        {
            cout << "음수 사이클 존재" << "\n";
        }
        else
        {
            if(dist[i] == INF) 
                cout << "INF" <<"\n";
            else 
                cout << dist[i] <<"\n";
        }
    }
}
