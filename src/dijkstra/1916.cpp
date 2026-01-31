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

#define INF 0x3f3f3f3f

using namespace std;

int n, m;
int st, ed; // 출발점 도착점
vector<pair<int, int>> adj[1002];
int d[1002];

void solution()
{
    d[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[st],st});

    while(!pq.empty())
    {
        int w = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(d[cur] != w)
            continue;

        for(auto nx : adj[cur])
        {
            if(d[nx.second] <= d[cur] + nx.first)
                continue;
            d[nx.second] = d[cur] + nx.first;
            pq.push({d[nx.second], nx.second});
        }


    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> m;

    fill(d, d + n + 1, INF);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    cin >> st >> ed;

    solution();

    // 시간 제한 0.5초 대략 5 10 ^7 
    // 1000 n * m 
    cout << d[ed] <<"\n";
}
