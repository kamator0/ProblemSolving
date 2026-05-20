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

int n, k ;
// vector<pair<int,int>> edge[]; // [u] , w , v 
vector<int> edge[200001]; // [u] , v 
long long dp[200001][5]; // 나머지로 넣어두는 방법고려  
//int sub[200001];
long long result = 0;
long long sub[200001];

void dfs(int v , int parent,int cnt)
{
    //sub[v] = cnt / k + 1; 
    // sub에 root로 부터 길이 저장하고 dp에는 갯수 저장? 
    dp[v][0] = 1;  
    sub[v] = 1;
    for(auto c : edge[v])
    {
        if(c == parent)
            continue;
        dfs(c,v,cnt+1);
        
        // s < t 여야함 
        for(int i = 0 ; i< k ; i++)
        {
            for(int j = 0 ; j<k ; j++)
            {
                int r = (i+j+1) % k ; // 거리의 나머지
                int cc =(k-r) % k ; // 보정값 
                result += (long long)cc * dp[v][i] * dp[c][j]; // 
            }
        }
        
        cout << result <<"\n";
        sub[v] += sub[c];
        for(int i = 0 ; i< k; i++)
        {
            dp[v][(i+1)%k] += dp[c][i];
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k ; 
    for(int i = 0 ; i< n - 1; i++)
    {
        int a, b ;
        cin >> a >> b ;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(1,-1,0);

    for(int i = 1; i <=n ;i++)
    {
        for(int j=0; j<k ; j++)
        {
            cout << dp[i][j] <<" ";
        }
        cout <<"\n";
    }

    long long total = 0;
    for(int i = 1; i<=n; i++)
    {
        total += (sub[i] * (n-sub[i]));
    }

    cout << (result + total)/k <<"\n";

}

