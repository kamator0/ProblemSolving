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

string s1,s2;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1 >> s2 ;

    vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1,0));

    // 첫번째 구하기? 
    for(int i = 1 ; i <=s1.size(); i++)
    {
        for(int j = 1; j<=s2.size(); j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                // if(i==0 || j ==0)
                // {
                //     dp[i][j] = 1;
                // }
                // else
                dp[i][j] = dp[i-1][j-1] + 1 ;
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    
    int result = 0 ;

    for(int i = 1; i<=s1.size(); i++)
    {
        for(int j =1 ;j<=s2.size(); j++)
        {
            result =max(result,dp[i][j]);
        }
      
    }
 

    cout << result<<"\n";
}
