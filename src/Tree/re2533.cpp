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

int n;
vector<int> graph[1000001];
int dp[1000001][2];
vector<int> order;
int visited[1000001];
int p [1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        order.push_back(cur);
        for(int x : graph[cur]){
            if(visited[x] !=1)
            {
                visited[x] = 1 ;
                p [x] = cur;
                q.push(x);
            }
        }
    }

    for (int i = order.size()-1; i >= 0; i--)
    {
        int cur = order[i];
        dp[cur][0] = 0;
        dp[cur][1] = 1 ;
        for (int x : graph[cur])
        {
            if(x == visited[cur])
                continue;
            dp[cur][0] += dp[x][1];
            dp[cur][1] += min(dp[x][0], dp[x][1]);
        }
    }

    cout << min(dp[1][0] , dp[1][1]) << "\n";
}
