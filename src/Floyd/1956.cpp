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

int v,e ;

int graph[402][402];
int nx[402][402];
vector<int> dst[402][402];

int result = INF ;

void solution()
{
    for(int i = 1 ; i<=v ;i++)
    {
        for(int j = 1 ; j<=v; j++)
        {
            for(int k =1 ; k<=v ;k++)
            {
                if(k==j)
                    continue;
                if(graph[j][k] > graph[j][i] + graph[i][k])
                {
                    graph[j][k] = graph[j][i] + graph[i][k];
                    nx[j][k] = nx[j][i];
                }
            }
        }
    }

    for(int i = 1 ; i<= v ; i++)
    {
        for(int j = 1; j<=v; j++)
        {
            if(graph[i][j] == INF)
                continue;
            int idx = nx[i][j] ;
            while(idx != j )
            {
                dst[i][j].push_back(idx);
                idx = nx[idx][j];
            }
            dst[i][j].push_back(j);
        }
    }

    // a-> b -> a 이런식으로
}
void cycle(int s, int l)
{
    int idx = graph[s][l] + graph[l][s] ;
    result = min(idx,result);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> v >> e ;


    for(int i = 1; i<=v ;i++)
    {
        for(int j = 1; j<=v ; j++)
        {
            graph[i][j] = INF;
        }
    }

    for(int i = 0; i< e; i++ )
    {
        int a,b, c ;
        cin >> a >> b >> c ;
        graph[a][b] = c ;
        nx[a][b] =b ;
    }

    //cout << 1234<<"\n";
    solution();

    // 순열 탐색을 돌려서 재귀적으로 탐색하고? 

    // 1 -> 2 -> 3 -> 1 
    // 2 -> 3 -> 2 
    for(int i = 1 ; i <= v ; i++)
    {
        for(int j = 1 ; j<=v ; j++)
        {
            //
            if(j< i)
                continue;
            if(nx[i][j] == 0 || nx[j][i] == 0) // 경로가 없으면
                continue;
            cycle(i,j);
        }
    }

    if(result == INF)
        cout << -1 <<"\n";
    else
        cout << result <<"\n";


}
