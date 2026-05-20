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

#define INF 0x3f3f3f3f // 경우에 따라 다르게
// long long 일

using namespace std;

string s1, s2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1 >> s2;

    int size1 = s1.size();
    int size2 = s2.size();

    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

    // 1001 * 1001 * 4

    // vector<vector<string>> result(size1+1, vector<string>(size2+1,""));

    // vector의 연산까지 하면 10^9 임으로 시간초과

    for (int i = 1; i <= size1; i++)
    {
        for (int j = 1; j <= size2; j++)
        {
            if (s2[j - 1] == s1[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                // result[i][j] = (result[i-1][j-1] + s2[j-1]) ;
                // s.push_back(s2[j-1]);
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                // if(dp[i-1][j]> dp[i][j-1])
                // {
                //     result[i][j] = result[i-1][j];
                // }
                // else{
                //     result[i][j] = result[i][j-1];

                // }
            }
        }
    }

    string lcs = "";

    int i = size1;
    int j = size2;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs.push_back(s1[i - 1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            i--;

        }
        else{
            j--;

        }

    }

    // for (int i = 1; i <= s1.size(); i++)
    // {
    //     for (int j = 1; j <= s2.size(); j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    reverse(lcs.begin(),lcs.end());

    cout << dp[size1][size2] << "\n";
    cout << lcs <<"\n";
    // cout << result[size1][size2] << "\n";
}
