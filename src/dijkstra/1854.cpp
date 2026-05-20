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

#define INF 0x3f3f3f3f // 경우에 따라 다르게

using namespace std;
int n, m, k;
vector<pair<int, int>> adj[1002];
int d[102][1002]; // n번째로 빠른거를 ?
pair<int,int> pre[102][1002]; 

// bool path(pair<int,int> p1, pair<int,int> p2) // p1 이 비교? 
// {
//     if(pre[p1.first][p1.second] == pre[p2.first][p2.second])
//     {

//     }   
// }

void solution()
{
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = INF;
        }
    }
    /*for (int i = 1; i <= n; i++)
    { // 1번째 보다 크게 되야 하는건데
        d[i][i] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({d[i][i], i});

        while (!pq.empty())
        {
            int w = pq.top().first;
            int cur = pq.top().second;

            pq.pop();

            if (d[i][cur] != w)
                continue;

            for (auto nx : adj[cur])
            {
                //int idx = d[i][nx.second];
                //bool flag = false;

                if (d[i][nx.second] <= nx.first + d[i][cur])
                    continue;

                // if (d[i-1][nx.second] <= nx.first + d[i][cur])
                // {
                //     //if(d[i][nx.second] < nx.first + d[i][cur])
                //     // INF아님
                //     pq.push({d[i-1][nx.second], nx.second});
                //     continue;
                // }
                // for(int j = 1 ; j<= i ; j++)
                // {
                //     if(pre[j][nx.second] == cur)
                //     {
                //         flag = true ;
                //         break;
                //     }
                // }
                // if(flag)
                //     continue;

                d[i][nx.second] = nx.first + d[i][cur];
                pre[i][nx.second] = cur ;
                // if (d[i - 1][nx.second] >= d[i][nx.second])
                // {
                //     d[i][nx.second] = idx;
                //     continue;
                // }
                pq.push({d[i][nx.second], nx.second});
            }
        }
    }*/

    //

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for (int i = 1; i <= k; i++)
    {
        if (i == 1)
        {
            d[i][1] = 0;
            pq.push({d[i][1], {i, 1}});
        }
        for (int j = 1; j < i; j++)
        {
            for (int x = 1; x <= n; x++)
            {
                if (d[j][x] == INF)
                    continue;
                //cout << j << " " << x << "\n";
                pq.push({d[j][x], {j, x}});
            }
        }
        while (!pq.empty())
        {
            int w = pq.top().first;
            int idx = pq.top().second.first;
            int cur = pq.top().second.second;

            pq.pop();

            // cout << w <<" " << idx <<" " <<cur <<"\n";
            if (d[idx][cur] != w)
                continue;
            for (auto nx : adj[cur])
            {
                //cout << w <<" " << idx <<" " <<cur <<" " << nx.first <<" "<< nx.second <<"\n";
                if (d[i][nx.second] <= d[idx][cur] + nx.first)
                    continue;
                // d[i-1][nx.second] 와 d[idx][cur] + nx.first 가 같더라도  경로가 다른 경우?
                if (d[i - 1][nx.second] > d[idx][cur] + nx.first)
                    continue;
                else if(d[i - 1][nx.second]  == d[idx][cur] + nx.first)
                {
                    // if (!path(pre[i-1][nx.second],{idx,cur}))
                    //     continue;
                    if(pre[i-1][nx.second].first == idx && pre[i-1][nx.second].second == cur)
                        continue;
                    
                }
                
                d[i][nx.second] = d[idx][cur] + nx.first;
                pre[i][nx.second].first = idx ;
                pre[i][nx.second].second = cur;
                pq.push({d[i][nx.second], {i, nx.second}});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c; // a -> b ,  c시간
        adj[a].push_back({c, b});
    }

    solution();

    // for (int i = 1; i <= k; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if (d[i][j] == INF)
    //         {
    //             cout << -1 << " ";
    //             continue;
    //         }
    //         cout << d[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int j = 1; j <= n; j++)
    {
        if(d[k][j] == INF)
        {
            cout << -1 <<"\n";
            continue;
        }
        cout << d[k][j]  <<"\n";
    }
}
