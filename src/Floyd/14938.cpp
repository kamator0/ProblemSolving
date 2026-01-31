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

int n,m, r ;
int icnt [105]; 
int graph[105][105];

void solution()
{
    for(int i = 1;  i<= n; i++)
    {
        for(int j = 1; j<=n ; j++)
        {
            for(int k  = 1; k<=n; k++)
            {
                if(j==k)
                    continue;
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]); 

            }
        }
    }



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >>  n >> m >> r ;
    for(int i = 1; i<=n; i++)
    {
        int t ;
        cin >> t ;
        icnt[i] = t ;
    }
    for(int i = 1; i <=n ; i++)
    {

        for(int j =1 ; j<=n ; j++)
        {
            graph[i][j] = INF;
        }
    }



    // 양방향 
    for (int i = 0; i<r ; i++)
    {
        int a,b,l;
        cin >> a >> b >> l ; 
        graph[a][b] = l;
        graph[b][a] = l ;
        // 경로를 저장하는 거는 안해도 됨 
    }


    solution();

    // 결과 값을 저장? 
    int result = -1 ;

    for(int i = 1; i <=n ; i++)
    {
        int idx = 0 ;
        for(int j= 1; j<=n ; j++)
        {
            if(graph[i][j] > m && i !=j )
                continue;
            idx += icnt[j];
        }

        result= max(result,idx);

    }
    // for(int i = 1; i <=n ; i++)
    // {

    //     for(int j =1 ; j<=n ; j++)
    //     {
    //         if(graph[i][j] == INF)
    //         {
    //             cout << 0 <<" ";
    //             continue;
    //         }
    //         cout << graph[i][j] <<" ";
    //     }
    //     cout<<"\n";

    // }

    cout << result<<"\n";

}
