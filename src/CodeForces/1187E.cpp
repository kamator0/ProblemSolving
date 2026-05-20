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

int n ;
vector<int> edge[200001];
int  sub[200001];
int dp[200001];
int result = 0;

void dfs(int v, int parent)
{
    sub[v] = 1; 
    for(auto c : edge[v])
    {
        if(c==parent)
            continue;
        dfs(c,v);
        sub[v] += sub[c] ;
    }

    dp[1] += sub[v];
}

void cal(int v, int parent)
{

    for(auto c :edge[v])
    {
        if(c == parent)
        {   
            continue;
        }

        dp[c] =  dp[v] - sub[c] + n - sub[c];
       
        cal(c,v);

    }


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n ;

    for(int i = 0 ;  i < n-1; i++)
    {
        int u,v ;
        cin >> u >> v ;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(1,-1);

    cal(1,-1);

    for(int i = 1 ; i <=n; i++)
    {
        cout << dp[i] <<" "; 
    }
    cout <<"\n";
    
    for(int i = 1; i<= n; i++)
    {
        result = max(result , dp[i]);
    }

    cout << result <<"\n";
}

