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

vector<int> cmd;

int result = INF;

int dp[100001][5][5]; // 100MB
// 1 위 2 왼쪽 3 아래 4 오른쪽
// void dfs(int r, int l, int cnt, int idx) // 오 왼 0 , idx
// {
//     if (idx == cmd.size())
//     {
//         result = min(result, cnt);
//         return;
//     }

//     if (cmd[idx] == r)
//     {
//         dfs(r, l, cnt + 1, idx + 1);
//     }
//     else if (cmd[idx] == l)
//     {
//         dfs(r, l, cnt + 1, idx + 1);
//     }
//     else
//     {
//         // 둘다 다름
//         if (r == 0)
//         {
//             // r을 움직일때
//             dfs(cmd[idx], l, cnt + 2, idx + 1);
//             // l을 움직일때
//             if (cmd[idx] % 2 == 0 && l != 0)
//             {
//                 if (l % 2 == 0)
//                 {
//                     dfs(r, cmd[idx], cnt + 4, idx + 1);
//                 }
//                 else
//                 {
//                     dfs(r, cmd[idx], cnt + 3, idx + 1);
//                 }
//             }
//             if (cmd[idx] % 2 == 1 && l != 0)
//             {
//                 if (l % 2 == 1)
//                 {
//                     dfs(r, cmd[idx], cnt + 4, idx + 1);
//                 }
//                 else
//                 {
//                     dfs(r, cmd[idx], cnt + 3, idx + 1);
//                 }
//             }
//         }
//         else if (l == 0)
//         {
//             dfs(r, cmd[idx], cnt + 2, idx + 1);

//             if (cmd[idx] % 2 == 0 && r != 0)
//             {
//                 if (r % 2 == 0)
//                 {
//                     dfs(cmd[idx], l, cnt + 4, idx + 1);
//                 }
//                 else
//                 {
//                     dfs(cmd[idx], l, cnt + 3, idx + 1);
//                 }
//             }

//             if (cmd[idx] % 2 == 1 && r != 0)
//             {
//                 if (r % 2 == 1)
//                 {
//                     dfs(cmd[idx], l, cnt + 4, idx + 1);
//                 }
//                 else
//                 {
//                     dfs(cmd[idx], l, cnt + 3, idx + 1);
//                 }
//             }
//         }
//         else
//         {
//             if (cmd[idx] % 2 == 0)
//             {
//             }
//             else
//             {
//             }
//         }
//     }
// }
int cost(int st, int en)
{
    if (en == st)
        return 1;
    if (st == 0)
        return 2;
    if (abs(en - st) == 2)
        return 4;
    return 3;
}

void solution()
{

    for (int i = 0; i <= cmd.size(); i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            for (int k = 0; k <= 4; k++)
            {
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][0][0] = 0;

    for (int i = 0; i < cmd.size(); i++)
    {
        int next = cmd[i];
        for (int j = 0; j <= 4; j++)
        {
            for (int k = 0; k <= 4; k++)
            {
                if (dp[i][j][k] == INF)
                    continue;
                if (j == k && j != 0)
                    continue;
                // 왼쪽 move
                dp[i + 1][next][k] = min(dp[i + 1][next][k], (dp[i][j][k] + cost(j, next)));

                // 오른쪽 Move
                dp[i + 1][j][next] = min(dp[i + 1][j][next], (dp[i][j][k] + cost(k, next)));
            }
        }
    }
    // i +
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        else
            cmd.push_back(n);
    }

    // for (int i = 0; i <cmd.size() ; i++)
    // {
    //     cout << cmd[i] <<" ";
    // }
    // cout <<"\n";
    solution();

    for (int i = 0; i <= 4; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            result = min(result, dp[cmd.size()][i][j]);
        }
    }

    //cout << cmd.size() <<"\n";
    cout << result << "\n";
}
