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
#include <sstream>
#include <iomanip>

#define INF 0x3f3f3f3f // 경우에 따라 다르게
// long long 일 1e18

using namespace std;
int n;
long long g[300001];

vector<pair<long long, int>> edge[300001]; // [u] , w, v

//long long sub[300001];
long long dp[300001];
long long result = 0;

void dfs(int v, int parent) {
    long long best1 = 0, best2 = 0; // v에서 내려가는 1등, 2등 이익
    
    for (auto [w, c] : edge[v]) {
        if (c == parent) continue;
        dfs(c, v);
        
        long long val = max(0LL, dp[c] - w);
        if (val >= best1) { best2 = best1; best1 = val; }
        else if (val > best2) { best2 = val; }
    }
    
    result = max(result, g[v] + best1 + best2);
    dp[v] = g[v] + best1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long w;
        cin >> w;
        g[i] = w;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edge[u].push_back({w, v});
        edge[v].push_back({w, u});
    }


    dfs(1, -1);

  
    cout << result <<"\n";
}
