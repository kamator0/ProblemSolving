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

int n, m;
vector<int> v(2001, 0);

// 팰린드롬 화문 우영우 기러기
vector<pair<int, int>> q;

int dp[2001][2001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        v[i] = a;
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        q.push_back({s, e});
    }

    // 4백만
    // 1부터 시작해서 E 까지
    // dp[1][1] = 1;
    // for (int i = 2; i <= n; i++)
    // {
    //     bool flag = true;
    //     for (int j = 1; j <=i/2; j++)
    //     {
    //         if (v[i - (j-1)] != v[j])
    //         {
    //             flag = false;
    //             break;
    //         }
    //     }
    //     if(flag)
    //     {
    //         dp[1][i] = 1;
    //     }
    // }

    // 길이가 1 일 경우 무조건 화문

    // 길이가 2 일 경우 앞뒤 똑같 화문

    // 길이가 3 이상 일 경우

    // for(int i = 1; i<= n; i++)
    // {
    //     dp[i][i] = 1 ;
    //     dp[i][i+1] = (v[i] == v[i+1]);

    //     for(int len = 3 ; len <=n+1-i; len++)
    //     {
    //         int j = i+len-1;
    //         if( (v[len] == v[j]) && dp[len+1][j-1] == 1 )
    //             dp[len][j] = 1;
    //     }
    // }
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
        dp[i][i + 1] = (v[i] == v[i + 1]);
    }

    for (int len = 3; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            if ((v[i] == v[j]) && dp[i + 1][j - 1] == 1)
                dp[i][j] = 1;
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (auto x : q)
    {
        cout << dp[x.first][x.second] << "\n";
    }
}
