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
long long value[200001];
vector<int> edge[200001];
long long dp[200001];    
long long result = -1;
long long sub[200001];
//int dist[200001];
long long nodesum = 0;

// 2차원 dp로 가는거는 말 안되고 
void dfs(int v , int parent,int cnt)
{
    sub[v] = value[v];
    dp[1] +=  cnt * value[v];
    for(auto c : edge[v])
    {
        if(c==parent)
            continue;
        
        dfs(c,v,cnt+1);

        sub[v] += sub[c];
    }
}
void cal(int v, int parent)
{
    for(auto c : edge[v])
    {
        if(c == parent)
            continue;
        dp[c] = dp[v] - sub[c] + (nodesum - sub[c]); // 부모노드에서 자식노드 아래 배치하고 빼주고 전체 노드 중에 서 자식 서브셋 합 
        cal(c,v);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n ;
    for(int i = 1 ; i<= n; i++)
    {
        int v;
        cin>> v ;
        value[i] = v ;
    }
    

    for(int i  = 0 ; i< n-1 ; i++)
    {
        int u,v ; 
        cin >> u >> v ;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }


    /// 누구를 root로 골라야하는가?
    // 모든 node를 root로 골라서 한번씩 돌리면 n * n-1 인데 이러면 무조건 시간초과 
    // n * log n-1 ? 이런 식으로 줄이는 방법? 
    dfs(1,-1,0);

    // for(int i =1 ; i<=n ; i++)
    // {
    //     cout << sub[i] <<" ";
    // }
    // cout <<"\n";


    for(int i =1; i<=n; i++)
    {
        nodesum +=value[i];
    }

    // 일단 1 
    // 1을 root 했을 때를 재활용해서 구하기? 
    // for(int i =1 ; i <=n; i++)
    // {
    //     // 길이는 dist[]

    // } 


    cal(1,-1);

    for(int i = 1 ; i<=n ; i++)
    {
        result = max(result,dp[i]);
    }

    cout << result <<"\n";
}
 
