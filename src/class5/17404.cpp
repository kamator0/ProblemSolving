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
int rgb[1001][4];
int dp[1001][4];
int pre[1001][4];

int result = INF;

void compare(int x, int y) // x 는 2번째 y는 n-1번째
{
    int sum = 0;
    if (x == 1)
    {
        // 2 3
        if (y == 1)
        {
            // 첫번째가 2 n번째는 무조건 3
            // 첫번재가 3 n번재는 무조건 2
            sum = min(rgb[n][2] + rgb[1][3], rgb[n][3] + rgb[1][2]);
            // f = min(rgb[n][2], rgb[n][3]);
            //  2 3
        }
        else if (y == 2)
        {
            // 첫번째가 2  n번재는 1 또는 3
            // 첫번재가 3 n번째는 1
            sum = min(min(rgb[n][1] + rgb[1][2], rgb[1][2] + rgb[n][3]), rgb[n][1] + rgb[1][3]);
        }
        else
        {
            // 첫번째가 2 n번째는 1
            // 첫번째가 3 n번재는 1 2
            sum = min(min(rgb[n][1] + rgb[1][3], rgb[1][3] + rgb[n][2]), rgb[n][1] + rgb[1][2]);

            // f = rgb[n][2];
            //  1 2
        }
    }
    else if (x == 2)
    {
        // 1 3
        // 2 3
        if (y == 1)
        {
            // 첫번재가 1 이면 n번째는 2 3
            //  첫번째가 3 이면
            sum = min(min(rgb[1][1] + rgb[n][2], rgb[1][1] + rgb[n][3]), rgb[1][3] + rgb[n][2]);

            // f = rgb[n][3];
        }
        else if (y == 2)
        {
            sum = min(rgb[1][1] + rgb[n][3], rgb[1][3] + rgb[n][1]);

            // f = min(rgb[n][1], rgb[n][3]);
            //  1 3
        }
        else
        {
            // f = rgb[n][1];
            sum = min(min(rgb[1][3] + rgb[n][2], rgb[1][3] + rgb[n][1]), rgb[1][1] + rgb[n][2]);

            // 1 2
        }
    }
    else
    {
        // 1 2
        // 2 3
        if (y == 1)
        {
            sum = min(min(rgb[1][1] + rgb[n][2], rgb[1][1] + rgb[n][3]), rgb[1][2] + rgb[n][3]);

            // f = rgb[n][2];
        }
        else if (y == 2)
        {
            sum = min(min(rgb[1][2] + rgb[n][1], rgb[1][2] + rgb[n][3]), rgb[1][1] + rgb[n][3]);

            // 1 3
            // f = rgb[n][1];
        }
        else
        {
            sum = min(rgb[1][1] + rgb[n][2], rgb[1][2] + rgb[n][1]);

            // 1 2
            // f = min(rgb[n][1], rgb[n][2]);
        }
    }

    result = min(result, sum + dp[n - 1][y]);
}

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
            rgb[i][j] = a;
        }
    }

    // dp[2][1] = rgb[2][1];
    // dp[2][2] = rgb[2][2];
    // dp[2][3] = rgb[2][3];

    dp[1][1] = rgb[1][1];
    dp[1][2] = rgb[1][2];
    dp[1][3] = rgb[1][3];

    for (int i = 3; i <= n; i++)
    {
        if (i == n)
        {
            int idx1 = 1;
            int t = n - 1;

            while (t > 2)
            {
                idx1 = pre[t][idx1];
                t--;
            }

            int idx2 = 2;
            t = n - 1;

            while (t > 2)
            {
                idx2 = pre[t][idx2];
                t--;
            }

            int idx3 = 3;
            t = n - 1;

            while (t > 2)
            {
                idx3 = pre[t][idx3];
                t--;
            }

            // idx  = 3  첫번째 집이 3
            // n-1  1
            // idx1이 첫번째 집 3 으로 파생
            // idx1 = 3
            // idx2 = 3
            // idx3 = 3
            compare(idx1, 1);
            compare(idx2, 2);
            compare(idx3, 3);
        }
        else
        {
            if (dp[i - 1][2] < dp[i - 1][3])
            {
                dp[i][1] = dp[i - 1][2] + rgb[i][1];
                pre[i][1] = 2;
            }
            else
            {
                dp[i][1] = dp[i - 1][3] + rgb[i][1];
                pre[i][1] = 3;
            }
            if (dp[i - 1][1] < dp[i - 1][3])
            {
                dp[i][2] = dp[i - 1][1] + rgb[i][2];
                pre[i][2] = 1;
            }
            else
            {
                dp[i][2] = dp[i - 1][3] + rgb[i][2];
                pre[i][2] = 3;
            }
            if (dp[i - 1][1] < dp[i - 1][2])
            {
                dp[i][3] = dp[i - 1][1] + rgb[i][3];
                pre[i][3] = 1;
            }
            else
            {
                dp[i][3] = dp[i - 1][2] + rgb[i][3];
                pre[i][3] = 2;
            }
        }
    }

     for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
            cout << pre[i][j] << " ";
        cout << "\n";
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }

    // cout << idx1 << " " << idx2 << " " << idx3 << "\n";

    cout << result << "\n";
}
