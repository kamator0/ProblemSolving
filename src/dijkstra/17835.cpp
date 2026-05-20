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

//#define INF 1e18 // 경우에 따라 다르게
#define INF 0x3f3f3f3f
// long long 1e18

using namespace std;

int n, m, k;
vector<pair<int, int>> adj[100001];
vector<int> city;
// 거리를 n * n 하면 메모리 초과인데 10 ^  5 * 10 ^ 5
long long cnt[100001];

void solution()
{
   
    //long long mincity[100001];

    /*fill(mincity, mincity + n + 1, INF);

    for (int i = 0; i < k; i++)
    {
        mincity[city[i]] = -1;
    }

    // k * m 도 시간초과인데?
    for (int i = 0; i < k; i++)
    {
        fill(cnt, cnt + n + 1, INF);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        cnt[city[i]] = 0;
        pq.push({cnt[city[i]], city[i]});

        while (!pq.empty())
        {
            long long w = pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            if (cnt[cur] != w)
                continue;

            for (auto nx : adj[cur])
            {
                if (cnt[nx.second] <= nx.first + cnt[cur])
                    continue;
                if (mincity[nx.second] == -1)
                {
                    cnt[nx.second] = nx.first + cnt[cur];
                    continue;
                }
                cnt[nx.second] = nx.first + cnt[cur];
                pq.push({cnt[nx.second], nx.second});
            }
        }

        for (int j = 1; j <= n; j++)
        {
            if (mincity[j] == -1 || cnt[j] == INF)
                continue;
            mincity[j] = min(mincity[j], cnt[j]);
        }

        // for(int j = 1; j<=n ; j++)
        // {
        //     if( j == city[i] || cnt[j] == INF)
        //         continue;
        //     if(p.first < cnt[j])
        //     {
        //         p.first = cnt[j];
        //         p.second = j;
        //     }
        //     else if (p.first == cnt[j]){
        //         p.second = min(p.second,j);
        //     }

        // }
        // for(int j= 1 ; j<=n; j++)
        //     cout << cnt[j] <<" ";
        // cout <<"\n";
        // 2번 돌린다면 ? k * m *
    }

    for (int i = 1; i <= n; i++)
    {
        if (mincity[i] == -1)
            continue;
        if (p.first < mincity[i])
        {
            p.first = mincity[i];
            p.second = i;
        }
        else if (p.first == mincity[i])
        {
            p.second = min(p.second, i);
        }
    }*/

    // cout << p.second << "\n";
    // cout << p.first << "\n";

    fill(cnt, cnt + n + 1, INF);


    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;


    for(int i = 0 ;  i<k; i++)
    {
        cnt[city[i]] = 0 ;
        pq.push({cnt[city[i]],city[i]});
    }

    while(!pq.empty())
    {
        long long w = pq.top().first;
        int cur = pq.top().second;

        pq.pop();

        if(cnt[cur] != w)
            continue;
        
        for(auto nx : adj[cur])
        {
            if(cnt[nx.second] <= nx.first + cnt[cur])
                continue;
            cnt[nx.second] = nx.first +cnt[cur];
            pq.push({cnt[nx.second],nx.second});
        }
    }

    //   for(int j= 1 ; j<=n; j++)
    //         cout << cnt[j] <<" ";
    //     cout <<"\n";

     pair<long long, int> p = {0, 0};
       for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
            continue;
        if (p.first < cnt[i])
        {
            p.first = cnt[i];
            p.second = i;
        }
        else if (p.first == cnt[i])
        {
            p.second = min(p.second, i);
        }
    }

    cout << p.second << "\n";
    cout << p.first << "\n";

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
    {
        int u, v ;
        long long c;
        cin >> u >> v >> c;
        adj[v].push_back({c,u});
    }

    
    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        city.push_back(a);
    }

    solution();
}
