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
#define MOD 1000000007
// long long 일 1e18

using namespace std;

int n;
vector<int> edge[100001];
int color[100001];
long long dp[100001][2];


void dfs(int v, int parent)
{
    //cout <<  v <<" "<<parent<<"\n";
    if(color[v] == 1)
        dp[v][1] +=1; 
    else
        dp[v][0] +=1;
    
    for(auto c : edge[v])
    {
        if(c==parent)
            continue;
        dfs(c,v);


        // 일차원 dp 가 아니긴 한데 
        // dp[v]
        long long w = dp[v][0];
        long long b = dp[v][1];
    
        // 간선을 자를 때 
        // 자식 쪽에 검은노드 한 개 일때 
        
    
        // 간선을 안 자를 때 
        // v쪽에 검은 노드 있고 없고 , c쪽에 검은 노드 있고 없고
  
        dp[v][0] =  (w * (dp[c][1] + dp[c][0] ) )% MOD; // 간선 자를 때 + 안 자를 때 c에 검은 없는경우
        dp[v][1] = (b * (dp[c][1] + dp[c][0])  + w * dp[c][1] ) % MOD;

    }



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n ;
    for(int i =  1; i<n; i++)
    {
        int p ;
        cin >> p;
        edge[p].push_back(i);
        edge[i].push_back(p);
    }


    for(int i =0 ;i<n; i++)
    {
        int c ;
        cin >> c; 
        color[i] = c; 
    }
    

    dfs(0,-1);

    
    // for(int i = 0; i< 2; i++)
    // {
    //     for(int j =0 ; j< n; j++)
    //     {
    //         cout << dp[j][i] << " ";
    //     }
    //     cout <<"\n";
    // }

    cout << dp[0][1] % MOD<<"\n";

}

