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
#define MOD 1000000007 

using namespace std;

int t, k; 
vector<pair<int,int>> test;

long long dp[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t >> k;

    int MAX = -1;

    for(int i = 0 ;  i< t ;i ++)
    {
        int a, b ;
        cin >> a >> b ;
        MAX =  max(MAX,max(a,b));
        test.push_back({a,b});

    }

    dp[0] = 1; 
    for(int i = 1; i<= MAX; i++)
    {
        if(i < k)
            dp[i] = 1; 
        else{
            dp[i] = (dp[i-1] + dp[i-k] ) % MOD ;
        }

    }




    for(int i = 2 ; i<=MAX; i++)
    {
        dp[i] = (dp[i]+dp[i-1] ) % MOD; 
    }

    
    dp[0] = 0;



    for(auto x : test)
    {
        int st = x.first;
        int en = x.second;

        cout << (dp[en]-dp[st-1] + MOD) % MOD <<"\n";

    }
 


}

