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
#include <sstream>
#include <iomanip>

#define INF 1e18 // 경우에 따라 다르게
// long long 일

using namespace std;

int n, m;

vector<pair<long long, int>> edge[100001];
long long cnt[100001];
int pre[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        edge[a].push_back({w, b});
        edge[b].push_back({w, a});
    }

    fill(cnt, cnt + n + 1, INF);

    cnt[1] = 0;
    pre[1] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({cnt[1], 1});

    while (!pq.empty())
    {
        int cur = pq.top().second;
        long long w = pq.top().first;
        pq.pop();

        if (cnt[cur] != w)
            continue;

        for (auto x : edge[cur])
        {
            int nxt = x.second;
            long long nxt_w = x.first;
            if (cnt[nxt] <= nxt_w + cnt[cur])
                continue;
            cnt[nxt] = nxt_w + cnt[cur];
            pre[nxt] = cur;
            pq.push({cnt[nxt], nxt});
        }
    }

    vector<int> path;

    if (cnt[n] == INF)
    {
        cout << -1 << "\n";
    }
    else
    {
        path.push_back(n);
        int tmp = pre[n];
        while (tmp != 0)
        {
            path.push_back(tmp);
            tmp = pre[tmp];
        }
        reverse(path.begin(), path.end());
        for (auto x : path)
        {
            cout << x << " ";
        }
        cout << "\n";
    }

    // for(int i = 2 ; i<=n ; i++)
    // {
    //     if(cnt[i] == INF)
    //     {
    //         cout << -1 <<" ";
    //     }
    //     else{
    //         cout << cnt[i] <<" ";
    //     }
    // }
    // cout <<"\n";
}
