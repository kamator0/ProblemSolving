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

#define INF 300000000  // 10억이라 3번 더하면 int 형에서 터져버릴듯? 
// INF가 10억이면 3번 더하면 터짐 

using namespace std;

int n, e;
int v1, v2;
vector<pair<int, int>> adj[804];
// 200000 * 1000 2억
int d[804][804];

void solution()
{

    for (int i = 1; i <= n; i++)
    {
        d[i][i] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({d[i][i], i});
        while (!pq.empty())
        {
            int w = pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            if (d[i][cur] != w)
                continue;
            for(auto nx : adj[cur])
            {
                if(d[i][nx.second] <= nx.first + d[i][cur])
                    continue;
                d[i][nx.second] = nx.first + d[i][cur] ;
                pq.push({d[i][nx.second], nx.second});
            }

        }
    }


    // 답을 어떻게 내지? 
    // 1 -> v1 -> v2 -> n 결국에는 마지막에 n에 와야하기 때문에 1 -> v1 -> n -> v2 -> n 상관x
    // 1 -> v2 -> v1 -> n  
    int result = min(d[1][v1] + d[v1][v2] + d[v2][n] , d[1][v2] + d[v2][v1] + d[v1][n]);

    if(result >= INF)
        cout << -1 <<"\n";
    else
        cout << result <<"\n";

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> e;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = INF;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    cin >> v1 >> v2;

    solution();
}
