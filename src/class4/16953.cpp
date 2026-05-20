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

long long a,b;

//int dp[100000001][2]; // 0 2를 곱함 1 1을 수의 가장 오른쪽 추가 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> a >> b;

    queue<pair<long long ,long long>> q; // 현재 횟수? 
    long long result = 0;

    q.push({a,0});

    while(!q.empty())
    {
        long long cur = q.front().first;
        long long cnt = q.front().second;
        q.pop();

       // cout << cur <<" " <<cnt <<"\n";

        if(cur == b )
        {
            result = cnt + 1 ; 
            break;
        }

        if(cur * 2 <= b) // overflow 발생 해버림 
            q.push({cur*2,cnt+1});
        if(cur * 10 + 1 <=b )
            q.push({cur*10 + 1 , cnt+1});
    }


    if(result == 0)
        cout << -1 <<"\n";
    else 
        cout << result<<"\n";


    // for(int i = a; i<=b ;i ++)
    // {
    //     for(int j = 0 ; j<2 ; j++)
    //     {
    //         dp[i][j] = INF;
    //     }
    // }

    // dp[a][0] = 0;
    // dp[a][1] = 0;


    // for(int i = a ; i<=b; i++)
    // {
    //     // 2를 곱할 때 
    //     if(i * 2 <= b)
    //         dp[i*2][0] = min (dp[i*2][0] ,min(dp[i][0],dp[i][1]) )+ 1 ;
    //     if(i *10 + 1 <=b )
    //         dp[i*10 + 1][1] = min (dp[i*10+1][1] ,min(dp[i][0],dp[i][1]) )+ 1;

    // }

    // int result = min(dp[b][0],dp[b][1]);

    // if(result == INF)
    //     cout << -1 <<"\n";
    // else
    //     cout << result + 1 <<"\n";

    

}

