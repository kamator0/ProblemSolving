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

int r, g, b;

vector<int> rv;
vector<int> gv;
vector<int> bv;

int dp[201][201][201];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> g >> b;

    for (int i = 0; i < r; i++)
    {
        int n;
        cin >> n;
        rv.push_back(n);
    }

    for (int i = 0; i < g; i++)
    {
        int n;
        cin >> n;
        gv.push_back(n);
    }

    for (int i = 0; i < b; i++)
    {
        int n;
        cin >> n;
        bv.push_back(n);
    }

    sort(rv.begin(), rv.end(), greater<int>());
    sort(gv.begin(), gv.end(), greater<int>());
    sort(bv.begin(), bv.end(), greater<int>());

    int rs = rv.size();
    int gs = gv.size();
    int bs = bv.size();

    // dp[1][0][1] = rv[0] * bv[0];
    // dp[1][1][0] = rv[0] * gv[0];
    // dp[0][1][1] = gv[0] * bv[0];

    for (int i = 0; i <= rs; i++)
    {
        for (int j = 0; j <= gs; j++)
        {
            for (int k = 0; k <= bs; k++)
            {
                if(i < rs && j <gs)
                    dp[i + 1][j + 1][k] = max(rv[i] * gv[j] + dp[i][j][k], dp[i + 1][j + 1][k]);
                if(i < rs && k <bs)
                    dp[i + 1][j][k + 1] = max(rv[i] * bv[k] + dp[i][j][k], dp[i + 1][j][k + 1]);
                if(j < gs && k < bs)
                    dp[i][j + 1][k + 1] = max(gv[j] * bv[k] + dp[i][j][k], dp[i][j + 1][k + 1]);
            }
        }
    }

    // for(int i = 0 ; i<= rs; i++)
    // {
    //     for(int j = 0 ; j <= gs; j++)
    //     {
    //         for(int k = 0 ; k <= bs; k++)
    //         {
    //             cout << dp[i][j][k] <<" ";
    //         }
    //         cout <<"\n";
    //     }
    //     cout <<"\n";
    // }

    long long ans = 0;
    for (int i = 0; i <= rs; i++)
        for (int j = 0; j <= gs; j++)
            for (int k = 0; k <= bs; k++)
                ans = max(ans, (long long)dp[i][j][k]);

    cout << ans << "\n";
}
