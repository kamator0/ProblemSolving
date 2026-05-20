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

int t;
int graph[2][100001];
int dp[2][100001]; // 뜯김 안뜯김?
vector<int> result;

void solution(int n)
{

    dp[0][0] = graph[0][0];
    dp[1][0] = graph[1][0];

    dp[0][1] = graph[1][0] + graph[0][1];
    dp[1][1] = graph[1][1] + graph[0][0];

    for (int i = 2; i < n; i++)
    {
        dp[0][i] = graph[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
        dp[1][i] = graph[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
    }


    int s = -1;
    for(int i = 0 ; i< 2 ; i++)
    {
        for(int j = n-3 ; j<n; j++)
        {
            s = max(s,dp[i][j]);
        }
    }

    result.push_back(s);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < n; k++)
            {
                int a;
                cin >> a;
                graph[j][k] = a;
            }
        }

        solution(n);

        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < n; k++)
            {

                graph[j][k] = 0;
                dp[j][k] = 0;
            }
        }
    }

    for(auto x : result)
    {
        cout << x <<"\n";
    }

}
