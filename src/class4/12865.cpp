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
int n, k;
// vector<pair<float,pair<int,int>>> bag;
int value[101];
int weight[101];
int dp[101][100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        int w, v;
        cin >> w >> v;
        weight[i] = w;
        value[i] = v;
    }
 

    for(int i = 1 ; i<=n ; i++)
    {
        for(int w = 0 ; w <=k; w++)
        {
            dp[i][w] = dp[i-1][w];
            if(w>=weight[i])
                dp[i][w] = max(dp[i][w] ,dp[i-1][w-weight[i]] + value[i]);
        }
    }
    
    
    cout << dp[n][k]  <<"\n";
    
}
