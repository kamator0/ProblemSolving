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

#define INF 0x3f3f3f3f

using namespace std;

int n , m ; 
float graph[202][202];
//vector<pair<int,int>> adj[200];
vector<tuple<int,int,float>> adj;

void solution()
{
    for(int i = 1; i<=n ;i++)
    {
        for(int j = 1; j<=n; j++)
        {
            for(int k = 1; k<=n; k++)
            {
                if(j==k)
                    continue;
                if(graph[j][k] > graph[j][i] + graph[i][k])
                {
                    graph[j][k] = graph[j][i] + graph[i][k];
                    // 경로 j k = j i 
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m ;

    for(int i = 1; i<= n ;i++)
    {
        for(int j =1 ;j <=n ;j ++)
        {
            if(i==j)
            {
                graph[i][j] = 0;
                continue;
            }
            graph[i][j] = INF;
        }
    }

    for(int i = 0; i< m; i++)
    {
        int s,e;
        float l;
        cin >> s >> e >> l ;
        graph[s][e] = min (graph[s][e] ,l);
        graph[e][s] = min (graph[e][s] , l );
        //adj[s].push_back({l,e});
        //adj[e].push_back({l,s});
        adj.push_back({s,e,l});
       // adj.push_back({e,s,l});
    }
    
    solution();

    float result = INF; 
    // 전체
    for(int i= 1 ;  i<=n ; i++)
    {
        float cnt = -1.0 ; 
        for(int j= 0; j<adj.size(); j++)
        {
            int a =  get<0>(adj[j]);
            int b = get<1>(adj[j]);
            float w  =get<2> (adj[j]);
            //cout << i <<" " << a <<" "<< b <<" " << w << " "<< cnt << "\n";
            // cnt = max(cnt, graph[i][a],graph[i][b],(graph[i][a] + graph[i][b] + w )/2)
            //out << graph[i][a] <<" "<<graph[i][b] <<"\n";
            cnt = max (cnt , (graph[i][a] + graph[i][b] + w )/ 2);
        }
        result = min(result,cnt);
    }

    printf("%0.1f\n",result);

}
