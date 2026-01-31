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

int n, m, x; // 단방향
vector<pair<int, int>> adj[1002];
int d[1002][1002];
int pre[1002];
int result = 0 ;

void solution()
{

    // 1-> n 번가지 전부 돌려야함?
    // 어떤 집에서 x 까지의
    for (int i = 1; i <= n; i++)
    {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, i});
        d[i][i] = 0 ;
        while(!pq.empty())
        {
            int w = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            if(d[i][cur] != w )
                continue;
            for(auto nx : adj[cur])
            {
                if(d[i][nx.second] <= d[i][cur] + nx.first )
                    continue;
                d[i][nx.second] = d[i][cur] + nx.first;
                pre[nx.second] = cur;
                pq.push({d[i][nx.second],nx.second});
            }
                
        }

    }

    for(int i = 1 ;i <=n ; i++)
    {
        if(i==x)
            continue;
        result = max(result, d[i][x] + d[x][i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x;

    //fill(d, d + n + 1, INF);
    for(int i = 1; i<=n ; i++)
    {
        for(int j =1 ; j<=n; j++)
        {
            d[i][j] =INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }

    solution();

    cout << result <<"\n";
}
