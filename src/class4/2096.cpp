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

#define INF 1e6 // 경우에 따라 다르게
// long long 일

using namespace std;

// int graph[100000][3]; //

int n;

// int dp[100000][3];
// int dp2[100000][3];

int max_past[3];
int min_past[3];
// int max_cur[3];
// int min_cur[3];
int cur[3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int a;
            cin >> a;
            // graph[i][j] = a;
            //  max_cur[j] = a ;
            //  min_cur[j] = a ;
            cur[j] = a;
        }
        if (i == 0)
        {
            min_past[0] = cur[0];
            min_past[1] = cur[1];
            min_past[2] = cur[2];

            max_past[0] = cur[0];
            max_past[1] = cur[1];
            max_past[2] = cur[2];
        }
        else
        {
            int min_idx0 = min_past[0];
            int min_idx1 = min_past[1];
            int min_idx2 = min_past[2];
            min_past[0] = min(cur[0] + min_idx0, cur[0] + min_idx1);
            min_past[1] = min(cur[1] + min_idx2, min(cur[1] + min_idx0, cur[1] + min_idx1));
            min_past[2] = min(cur[2] + min_idx2, cur[2] + min_idx1);

            int max_idx0 = max_past[0];
            int max_idx1 = max_past[1];
            int max_idx2 = max_past[2];

            max_past[0] = max(cur[0] + max_idx0, cur[0] + max_idx1);
            max_past[1] = max(cur[1] + max_idx2, max(cur[1] + max_idx0, cur[1] + max_idx1));
            max_past[2] = max(cur[2] + max_idx2, cur[2] + max_idx1);
        }
    }


    cout << max(max_past[2], max(max_past[0] , max_past[1])) << " " << min(min_past[2] , min(min_past[0], min_past[1])) <<"\n";

    // dp[0][0] = graph[0][0];
    // dp[0][1] = graph[0][1];
    // dp[0][2] = graph[0][2];

    // for (int i = 1; i < n; i++)
    // {
    //     // for (int j = 0; j < 3; j++)
    //     // {
    //     //     if (j == 0)
    //     //     {
    //     //         dp[i][j] = max(dp[i - 1][j] + graph[i][j], dp[i - 1][j + 1], graph[i][j]);
    //     //     }
    //     //     else if (j == 1)
    //     //     {
    //     //         dp[i][j] = max(dp[i - 1][j] + graph[i][j], dp[i - 1][j + 1], graph[i][j]);
    //     //     }
    //     //     else
    //     //     {
    //     //         dp[i][j] = max(dp[i - 1][j] + graph[i][j], dp[i - 1][j + 1], graph[i][j]);
    //     //     }
    //     // }
    //     dp[i][0] = max(dp[i - 1][0] + graph[i][0], dp[i - 1][1] + graph[i][0]);
    //     dp[i][1] = max( dp[i-1][2] + graph[i][1], max(dp[i - 1][0] + graph[i][1], dp[i - 1][1] + graph[i][1]));
    //     dp[i][2] = max(dp[i - 1][2] + graph[i][2], dp[i - 1][1] + graph[i][2]);

    // }

    // int max_result =  max(dp[n-1][0] , max(dp[n-1][1],dp[n-1][2]));

    // for(int i = 0 ; i<n; i++)
    // {
    //     for(int j = 0 ; j<3; j++)
    //     {
    //         dp[i][j] = INF;
    //     }
    // }

    // dp[0][0] = graph[0][0];
    // dp[0][1] = graph[0][1];
    // dp[0][2] = graph[0][2];

    // for (int i = 1; i < n; i++)
    // {
    //     dp[i][0] = min(dp[i - 1][0] + graph[i][0], dp[i - 1][1] + graph[i][0]);
    //     dp[i][1] = min( dp[i-1][2] + graph[i][1], min(dp[i - 1][0] + graph[i][1], dp[i - 1][1] + graph[i][1]));
    //     dp[i][2] = min(dp[i - 1][2] + graph[i][2], dp[i - 1][1] + graph[i][2]);

    // }

    // int min_result = min(dp[n-1][0] , min(dp[n-1][1],dp[n-1][2]));

    // //cout << max(dp[n-1][0] , max(dp[n-1][1],dp[n-1][2])) << " " << min(dp[n-1][0] , min(dp[n-1][1],dp[n-1][2])) << "\n";

    // cout << max_result << " "<<min_result <<"\n";
}