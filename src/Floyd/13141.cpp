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

int n, m;
// 4 2
vector<pair<int, int>> graph[202];
// 202 202 2
int floyd[202][202];
float burncnt[202]; // 다 탔을 때 시간이랑 안 탔을때 시간을 분리하면 되는가?
int isburn[202];

int f_node = 0;

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (j == k)
                    continue;
                if (floyd[j][k] > floyd[j][i] + floyd[i][k])
                {
                    floyd[j][k] = floyd[j][i] + floyd[i][k];
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            floyd[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int s, e, l;
        cin >> s >> e >> l;
        if (s == e)
        {
            graph[s].push_back({l, e});
            graph[e].push_back({l, s});
        }
        else
        {
            graph[s].push_back({l, e});
            graph[e].push_back({l, s});
            floyd[s][e] = min(floyd[s][e], l);
            floyd[e][s] = min(floyd[e][s], l);
        }
    }

    solution();

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << floyd[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // 모드 노드에 불을 붙이는데 걸리는 시간이 가장 적은 노드에 불을 붙여야 빨리 없어지는가?

    // 모든 노드를 방문하는데 ?

    /*vector<pair<int, int>> f_cnt;   // 모든 노드 불 붙이는데 걸리는 시간

    for (int i = 1; i <= n; i++)
    {
        int idx = 0;
        for (int j = 1; j <= n; j++)
        {
            if (floyd[i][j] == INF)
                continue;
            idx = max(idx, floyd[i][j]);
        }
        f_cnt.push_back({idx, i});
    }

    sort(f_cnt.begin(), f_cnt.end());

    f_node = f_cnt[0].second;

    float result = 0.0;

    fill(burncnt, burncnt + n + 1, INF);
    // queue
    // 현재 시각?
    priority_queue<pair<float, int>, vector<pair<float, int>>, greater<pair<float, int>>> pq;
    pq.push({0, f_node});
    burncnt[f_node] = 0;
    isburn[f_node] = 1;

    // 자기 자신을 연결하는 간선은 어떻게해야함>
    while (!pq.empty())
    {
        float l = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        // cout << l <<" " << cur <<"\n" ;

        // if(isburn[cur] == 1)
        // {
        //     cout << burncnt[cur] <<"\n";
        //     burncnt[cur] = burncnt[cur] + (l - burncnt[cur] ) / 2 ;
        //     cout << l << " " << cur << " " << burncnt[cur] <<"\n";
        //     continue;
        // }
        // else{
        //     isburn[cur] = 1;
        // }
        // if(burncnt[cur] < l)
        // {
        //     result =  (l + burncnt[cur]) /2 ;
        //     continue;
        // }
        // else if(burncnt[cur] == l){
        //     result = burncnt[cur] ;
        // }
        // else if(burn[cur] == l)
        // {
        //     result =
        // }

        for (auto nx : graph[cur])
        {
            //cout << cur << " " << nx.second << " "<< nx.first<< " " << burncnt[cur] << " " << burncnt[nx.second] << " \n";

            if (isburn[nx.second] == 1)
            {
                // if (burncnt[cur] > burncnt[nx.second])
                //     continue;
                if (nx.second == cur)
                {
                    result = burncnt[cur] + nx.first / 2;
                    // pq.push({burncnt[nx.second] , nx.second});
                }
                else
                {
                    if (burncnt[nx.second] < burncnt[cur] + nx.first)
                        result = max(result, burncnt[nx.second] + (nx.first + burncnt[cur] - burncnt[nx.second]) / 2);
                    else
                    {
                        burncnt[nx.second] = burncnt[cur] + nx.first;
                        pq.push({burncnt[nx.second], nx.second});
                    }
                }
                continue; // 자기 연결하는걸 못 갖는데?
            }
            burncnt[nx.second] = burncnt[cur] + nx.first;
            isburn[nx.second] = 1;
            pq.push({burncnt[nx.second], nx.second});
        }
    }
    // for(int i = 0 ; i<graph[f_node].size(); i++)
    // {
    //     int l = graph[f_node][i].first;
    //     int nx = graph[f_node][i].second;
    //     pq.push({l,nx})
    // }
    for (int i = 1; i <= n; i++)
    {
        result = max(result, burncnt[i]);
    }*/
  
    //printf("%0.1f\n",result);


    // for(int i = 1 ; i <=n ; i++)
    // {
    //     for(int j = 0 ; j<graph[i].size(); j++)
    //     {
    //         for(int k = j+1 ; k<graph[i].size(); k++)
    //         {
    //             int burntime = (floyd[i][graph[i][j].second] + floyd[k][graph[i][k].second] + )
    //         }
    //     }
    // }





}
