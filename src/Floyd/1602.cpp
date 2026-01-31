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

int n, m, q;
int dog_g[505][505]; // 뭉뭉이 괴롭힘 저장
int dog[505];
int graph[505][505]; // 통로 저장
int nx[505][505];    // 경로 저장

void solution()
{
    
    //for(int i = 0 ; i)

    vector<pair<int,int>> dv;
    for(int i = 1; i<=n; i++)
    {
        dv.push_back({dog[i],i});
    }
    sort(dv.begin(), dv.end());


    // 괴롭히는 시간이 가장 큰 것을 거쳐갈때? 
    // for(int i= 1; i<=n ;  i++)
    // {
    //     //int i = dv[a].second;
    //     for(int a =0 ; a<dv.size(); a++ )
    //     {
    //         int j = dv[a].second;
    //         for(int k = 1 ; k<=n; k++)
    //         {
    //             if(j==k)
    //                 continue;
    //             if(graph[j][k] + dog_g[j][k] > graph[j][i] + graph[i][k]  + )
    //             {
    //                 graph[j][k] = graph[j][i] + graph[i][k] + dog[j];
    //                 nx[j][k] = nx[j][i];
    //             }

    //         }
    //     }

    // }


    // for (int i = 1; i <= n; i++)
    // {
    //     for (int a = 0; a < dv.size(); a++)
    //     {
    //         int j = dv[a].second;
    //         for (int k = 1; k <= n; k++)
    //         {
    //             if (j == k)
    //                 continue;

    //             if (graph[j][k] + dog_g[j][k] > graph[j][i] + graph[i][k] + max(dog_g[j][i], dog_g[i][k]))
    //             {
    //                 graph[j][k] = graph[j][i] + graph[i][k];
    //                 nx[j][k] = nx[j][i];

    //                 // 3단으로 사용 
    //                 dog_g[j][k] = max(dog_g[j][k],dog_g[i][k]);
    //                 dog_g[j][k] = max(dog_g[j][k],dog_g[j][i]);
    //             }
    //         }
    //     }
    // }



}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        dog[i] = a;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a][b] = d;
        graph[b][a] = d;
        nx[a][b] = b;
        nx[b][a] = a;
        dog_g[a][b] = max(dog[a], dog[b]);
        dog_g[b][a] = max(dog[a], dog[b]);
    }

    vector<pair<int, int>> qv;

    for (int i = 0; i < q; i++)
    {
        int s, t;
        cin >> s >> t;
        qv.push_back({s, t});
    }

    solution();


    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] == INF)
            {
                cout << 0 << " ";
                continue;
            }
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << nx[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << dog_g[i][j] << " ";
        }
        cout << "\n";
    }
    


    // vector<int> result;

    // for (pair<int, int> p : qv)
    // {
    //     int s = p.first;
    //     int t = p.second;
    //     // s == t 가 같다면 ?
    //     if (nx[s][t] == 0 && s != t)
    //     {
    //         result.push_back(-1);
    //         continue;
    //     }

    //     int idx = s;
    //     int MaxDog = 0;
    //     int cnt = graph[s][t];
    //     while (idx != t)
    //     {
    //         MaxDog = max(MaxDog, dog_g[idx][t]);
    //         //cnt += graph[idx][t];
    //         idx = nx[idx][t];
    //     }
    //    // cout << cnt <<"\n";
    //     MaxDog = max(MaxDog, dog[t]);
    //     result.push_back(cnt + MaxDog);
    // }

    // for (int a : result)
    // {
    //     cout << a << "\n";
    // }

    // for(int i = 0 ; i<result.size(); i++)
    // {

    // }

    // nx 를 이용해서 경로 계산 ?
}
