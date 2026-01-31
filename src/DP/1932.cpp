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

#define INF 12345678

using namespace std;

int n ; 

int t[502][502];
int dp[502][502];

// 밑에서 부터 위로 가야할꺼 같은데? 

// 위에서부터 아래로 가면 DFS같은 느낌  

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n ; 

    for(int i = 1;  i<=n ; i++ )
    {
        for(int j = 1; j<=i ; j++)
        {
            int a;
            cin >> a ;
            t[i][j] = a ;
        }
    }

    for(int i= 1; i <=n ; i++)
    {
        for(int j = 1; j<=i ; j++)
        {
            dp[i][j] = -1;
        }
    }
    
    for(int i = 1; i<=n; i++)
    {
        dp[n][i] = t[n][i];
    }


    for(int i = n; i>= 2; i --)
    {
        for(int j = 1 ; j<=i; j++)
        {
           dp[i-1][j] = max(dp[i][j] + t[i-1][j], dp[i][j+1] + t[i-1][j]) ;
        }
    }

    cout << dp[1][1] <<"\n";


}
