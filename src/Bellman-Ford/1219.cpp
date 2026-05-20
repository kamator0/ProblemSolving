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

#define INF 1e18 // 경우에 따라 다르게
// long long 일

using namespace std;

int n, s, e, m; // 도시 수 , 시작 ,도착 , 교통 수단
int city[51];   // 0부터 시작하고 도착하면 돈 벌음
vector<tuple<int, int, int>> edge;
vector<tuple<int, int, int>> new_edge;
vector<int> graph[51]; // a->b
long long dist[51];
bool flag = false;

void solution()
{
    dist[s] = -city[s];

    for (int i = 0; i < n - 1; i++)
    {
        for (auto [a, b, c] : new_edge) // 시작 도착 시간
        {
            if (dist[a] == INF)
                continue;
            if (dist[b] > dist[a] + c)
            {
                dist[b] = dist[a] + c;
            }
        }
    }

    // for(auto[a,b,c] : edge){
    //     if(dist[a] == INF)
    // }

    // 만약에 만약에
    // 시작점에서 출발했는데 c로 가는데 cycle이 발생하지 않았지만
    // 어떤 경로에 대해서 cycle이 발생할 수 도 있는 것인가??
    // 만약 시작점에서 출발했는데 c로가는데 cycle이 발생하고
    // 또 어떤 경로는 도착점에 도착하는데 cycle이 발생한다면??
    vector<int> node; // 도착점까지 가는 cycle node의 후보군

    // for (auto [a, b, c] : new_edge)
    // {
    //     if (dist[a] == INF)
    //         continue;
    //     if (dist[b] > dist[a] + c )
    //         flag = true;
    // }

    for (auto [a, b, c] : new_edge)
    {
        if (dist[a] == INF)
            continue;
        if (dist[b] > dist[a] + c)
        {
            node.push_back(a);
        }
    }

    for(int i = 0 ; i< node.size(); i++)
    {
        int x = node[i]; 
        queue<int> q;
        vector<int> visited(n,0);
        visited[x] = 1 ;
        q.push(x);
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            if(cur == e)
            {
                flag = true;
                break;
            }
            for(auto nx : graph[cur])
            {
                if(visited[nx] == 1)
                    continue;
                visited[nx] = 1;
                q.push(nx);
            }

        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s >> e >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back({a, b, c});
        graph[a].push_back(b);
    }

    // for (int i = 0 ; i< n ; i++)
    // {
    //     int a;
    //     cin >> a;

    // }

    for (int i = 0; i < n; i++)
    {
        int money;
        cin >> money;
        city[i] = money;
    }

    for (auto [a, b, c] : edge)
    {
        new_edge.push_back({a, b, c - city[b]});

    }

    fill(dist, dist + n + 1, INF);

    // for(auto [a,b,c]: new_edge)
    // {
    //     cout << a <<" "<<b <<" "<<c <<"\n";
    // }

    solution();

    // for(int i =0 ; i< n; i++)
    // {
    //     if(dist[i] == INF)
    //     {
    //         cout << -1 <<" ";
    //     }
    //     else
    //         cout << dist[i] <<" ";
    // }

    // cout <<"\n";
    if (dist[e] == INF)
    {
        cout << "gg" << "\n";
    }
    else
    {
        if (flag)
        {
            cout << "Gee" << "\n";
        }
        else
            cout << -dist[e] << "\n";
    }
}
