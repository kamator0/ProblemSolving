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

using namespace std;

int n, m, k;

int s, d;

vector<pair<int, int>> adj[1004];

// long long cnt[30001][1001]; // 10 ^ 7  // 세금 없이 0 번
// int pre[1001];
int in[30001];
long long cnt[1001][1001] ;  // (n-1)개 

// 세금 인상 없이는 10 ^ 6 이 최대



void solution()
{
    // 세금 더하는 것도 안됌
    /*for (int i = 0; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cnt[i][j] = INF;
        }
    }
    int pp = 0; // 세금 
    for (int i = 0; i <= k; i++) // k가 30000 * m log n ->: 9 * 10 ^ 8 
    {
        cnt[i][s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({cnt[i][s], s});
        pp += in[i];

        while (!pq.empty())
        {
            long long w = pq.top().first;
            int cur = pq.top().second;

            pq.pop();

            if (cnt[i][cur] != w)
                continue;

            for (auto nx : adj[cur])
            {
                if (cnt[i][nx.second] <= cnt[i][cur] + nx.first + pp)
                    continue;

                cnt[i][nx.second] = cnt[i][cur] + nx.first + pp;
                //pre[nx.second] = cur;
                pq.push({cnt[i][nx.second], nx.second});
            }
        }


        // 경로를 탐색해서 
    }

    for(int i = 0; i<=k; i++)
    {
        cout << cnt[i][d] <<"\n";
    }
    */


    // s -> d 까지 모든 거리와 방문한 노드 갯수를 센다 
    // 
    // 15 , 2 / 6, 3 /
     

    // 간선 수 
    for (int i = 0 ; i<=n-1; i++)
    {
        for(int j = 1 ; j<=n ; j++)
        {
            cnt[i][j] = INF;
        }
    }

    priority_queue<pair<long long, pair<int,int>>, vector<pair<long long, pair<int,int>>>, greater<pair<long long, pair<int,int>>>> pq;
 
    cnt[0][s] = 0; // 간선 몇개 썻는지? 
    pq.push({cnt[0][s],{s,0}});  // 거리 , 현재 , 간선 수

    while(!pq.empty())
    {
        long long  w = pq.top().first;
        int cur = pq.top().second.first;
        int edge = pq.top().second.second;
        pq.pop();

        // if(cur == d)
        // {
        //     max_edge = max(max_edge,edge);
        //     continue;
        // }
        if(cnt[edge][cur] != w)
            continue;
        
        for(auto nx : adj[cur])
        {
            // 다시 재방문 하는게 문제 1 -> 2 -> 1 -> 3 
            // 간선 수가 n-1 
            if(edge+ 1 > n-1)
                continue;

            if(cnt[edge+1][nx.second] <= cnt[edge][cur] + nx.first)
                continue;
            
            // if(cnt[edge-1][nx.second] <= cnt[edge][cur] - nx.first)
            //     continue;

            cnt[edge+1][nx.second] = cnt[edge][cur] + nx.first;
            pq.push({cnt[edge+1][nx.second],{nx.second,edge+1}});
        }

    }

    // for(int i = 1; i<=max_edge; i++)
    // {
    //     for(int j= 1; j<=n; j++)
    //     {
    //         cout << cnt[i][j] <<" ";
    //     }
    //     cout <<"\n";
    // }
     

    // for(int i = 1;  i<=max_edge; i++)
    // {
    //     //cout << cnt[i][d] <<"\n";
    // }   


    // 아니 근데 이걸 어떻게 잘 처리하지? 

    // pp 
    // cnt[i][d] + pp * i 
    long long pp = 0 ;
    for(int i= 0; i<=k ; i++)
    {
        pp +=in[i];
        long long  min_path = INF  ;
        for(int j = 1 ; j<=n-1; j++)
        {
            min_path =  min(min_path,cnt[j][d]+ (long long)j*pp);
        }
        cout << min_path <<"\n";
    }


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    cin >> s >> d;

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    for (int i = 1; i <= k; i++)
    {
        int p;
        cin >> p;
        in[i] = p;
    }


    solution();


    // edge 의 최댓값을 어떻게 구하징? 



}
