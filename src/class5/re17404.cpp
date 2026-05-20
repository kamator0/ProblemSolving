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
// long long 일

using namespace std;

int n;
int h[1001][4];
int dp[1001][4];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            int a;
            cin >> a;
            h[i][j] = a;
        }
    }

    int result = INF;

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            dp[1][j] = (i == j) ? h[1][i] : INF;
        }

        for (int j = 2; j <= n; j++)
        {
            dp[j][1] = min(dp[j - 1][2], dp[j - 1][3]) + h[j][1];
            dp[j][2] = min(dp[j - 1][1], dp[j - 1][3]) + h[j][2];
            dp[j][3] = min(dp[j - 1][1], dp[j - 1][2]) + h[j][3];
        }

        for (int j = 1; j <= 3; j++)
        {
            if (j != i)
            {
                result = min(dp[n][j], result);
            }
        }

        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= 3; j++)
        //     {

        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
    }

    cout << result << "\n";
}
