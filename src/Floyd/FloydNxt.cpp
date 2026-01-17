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

int n,  m ; 
int graph [102][102];
int nxt[102][102];

void solution()
{
    for(int i= 1 ; i<=n ; i++)
    {

        // i 번째 거쳐서 갈때? 
        for(int j = 1; j<=n; j++)
        {
            for(int k =1; k<=n; k++)
            {
                if(j==k)
                    continue;
                if(graph[j][k] > graph[j][i] + graph[i][k])
                {
                    graph[j][k]  = (graph[j][i] + graph[i][k]);
                    nxt [j][k] = nxt[j][i] ; 
                }
                //    graph[j][k] = min(graph[j][k],graph[j][i] + graph[i][k]);
                
            }
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n; 

    for(int i = 1 ; i<=n ; i++)
    {
        for(int j = 1;  j <=n; j++)
        {
            if(i==j)
                continue;
            graph[i][j] = INF;
        }
    }


    cin >> m ;



    for(int i = 0 ; i < m; i++)
    {
        int a,b ,c ;
        cin >> a >> b >> c ;
        if (graph[a][b] > c)
        {
            graph[a][b] = c; 
            nxt [a][b] = b; 
        }
      
        
    }

    // for(int i = 1 ; i<=n ; i++)
    // {
    //     for(int j = 1;  j <=n; j++)
    //     {
    //         cout << graph[i][j] <<" ";
    //     }
    //     cout <<"\n";
    // }


    solution();

    for(int i = 1 ; i<=n ; i++)
    {
        for(int j = 1;  j <=n; j++)
        {
            if(graph[i][j] == INF)
            {
                cout << 0 <<" ";
                continue;
            }

            cout << graph[i][j] <<" ";
        }
        cout <<"\n";
    }
    for(int i = 1 ; i<=n ; i++)
    {
        for(int j = 1;  j <=n; j++)
        {
        
            cout << nxt[i][j] <<" ";
        }
        cout <<"\n";
    }
    
}
