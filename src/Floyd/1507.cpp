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

int n;
int graph[22][22];
int org[22][22];
int nx[22][22];

bool dfs(int s, int l, int idx)
{
    int count = 0 ;
    bool flag = false;
    for (int k = 1; k <= n; k++)
    {
        if (s == k || l == k)
            continue;
        if(idx < graph[s][k] + graph[k][l])
            continue;
        flag =true;
    } 
    return flag;
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == i)
                continue;
            int idx = graph[i][j];

            if(!dfs(i,j,idx)) 
            {
                org[i][j] = idx ;
                //nx[i][j] = j;
            }
            // i , j , idx

            // 일단  12 13 14 15
            // if (org[i][j] == INF)
            // {
            //     org[i][j] = graph[i][j];
            // }
            // else
            // {
            //     // 2 ->1 2 -> k -> 1
            //     for (int k = 1; k <= n; k++)
            //     {
            //         if (graph[i][j] < graph[i][k])
            //             continue;
            //     }
            // }
        }
    }

    // for(int i =1 ; i<= n ; i++)
    // {
    //     for(int j = 1; j<=n ; j++)
    //     {
    //         if(j==i)
    //             continue;

    //     }
    // }
}

bool check()
{
    for(int i=1 ; i<=n ; i++)
    {
        for(int j = 1; j<=n; j++ )
        {
            for(int k = 1; k<=n; k++)
            {
                if(k==j)
                    continue;
                if(org[j][k] > org[j][i] + org[i][k])
                    org[j][k] = org[j][i] + org[i][k];
            }
        }
    }

    // for(int i = 1 ; i<=n ; i++)
    // {
    //     for(int j =1 ; j<=n; j++)
    //     {
    //         if(org[i][j] == INF)
    //         {
    //             cout << 0 <<" ";
    //             continue;
    //         }    
    //         cout << org[i][j] <<" ";
    //     }
    //     cout <<"\n";
    // }


  

    for(int i = 1; i<=n ; i++)
    {
        for(int j = 1; j<=n ; j++)
        {
            if(org[i][j] == INF)
                continue;
            if(org[i][j]!= graph[i][j])
                return false;
        }
    }
    return true;

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            graph[i][j] = a;
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         org[i][j] = INF;
    //     }
    // }

    solution();

    // 도로의 갯수가 최솟값일 때, 모든 도로의 시간의 합 구하라

   

    int result = 0 ;

    for(int i = 1 ; i<=n ; i++)
    {
        for(int j =1 ; j<=n ; j++)
        {
            if(j> i) 
                continue;
            if(org[i][j] !=0)
                result+= org[i][j];
        }
    }
    for(int i = 1 ; i<=n ; i++)
    {
        for(int j =1 ; j<=n; j++)
        {
            if(org[i][j] == 0)
                org[i][j] = INF;
        }
    }

    

    if(!check())
        cout << -1 <<"\n";
    else
        cout << result<<"\n";
    // floyd 한번더 돌려서 다른거 있으면 터트리기? 

    //cout << result <<"\n";

}
