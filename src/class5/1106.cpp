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

int c, n; // 고객 도시 갯수
int cost[21];
int value[21];

int dp[100001];
int result = INF;
void dfs(int cur_c, int cur_v) // 현재 비용과 고객
{
    if (cur_v >= c)
    {
        result = min(result, cur_c);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (result <= cur_c + cost[i])
            continue;
        dfs(cur_c + cost[i], cur_v + value[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c >> n;
    for (int i = 1; i <= n; i++)
    {
        int c, v;
        cin >> c >> v;
        cost[i] = c;
        value[i] = v;
    }

    // dfs(0,0);

    // for(int i = 1; i<=n ; i++)
    // {
    //     for(int w= 0 ; w<=c ; w++)
    //     {
    //         dp[i][w] = dp[i-1][w];
    //         if(w<=cost[i])
    //         {

    //         }
    //     }
    // }

    // dp[i] i에 cost넣고 dp[i] 값에  고객수?
    for(int i = 1; i<=n ; i++)
    {
        dp[cost[i]] = max(dp[cost[i]], value[i]) ;
    }


    for (int i = 1; i <= 100000; i++) 
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - cost[j] < 1)
                continue;
            if (dp[i] <= dp[i - cost[j]] + value[j])
            {
                dp[i] = dp[i-cost[j]] + value[j];
            }
        }
    }

    //cout << dp[8] <<"\n";

    // for(int i = 1; i<= 181 ;i++)
    // {
    //     cout << dp[i] <<" ";
    // }
    // cout <<"\n";


    for(int i = 1; i<= 100000; i++)
    {
        if(dp[i] >= c)
        {
            cout << i <<"\n";
            break;
        }
    }

    // cout << result <<"\n";
}
