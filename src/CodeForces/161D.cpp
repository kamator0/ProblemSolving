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

int n, k;
vector<int> edge[50001];
long long result = 0;
int p[50001];
long long dp[501][50001];

void dfs(int v , int parent)
{
    dp[0][v] = 1; 
    for(auto c : edge[v])
    {
        if(c== parent)
            continue;
        dfs(c,v);


        for(int i = 0 ; i< k ; i++)
        {
            result += dp[i][v] * dp[k-1-i][c];
        }

        for(int i = 1; i<=k ; i++)
        {
            dp[i][v] += dp[i-1][c];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    fill(p,p+n+1, -1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
        //p[b] = a;
    }

    //int root = 0 ;

    // for(int i =1 ; i <=n; i++)
    // {
    //     if(p[i] == -1)
    //     {
    //         root = i;
    //     }
    // }

    //cout << root <<"\n";

    dfs(1,-1);

    for(int i = 0; i<= k ; i++)
    {
        for(int j= 1; j<=n; j++)
        {
            cout << dp[i][j] <<" ";
        }
        cout <<"\n";
    }

    cout << result<<"\n";
}
