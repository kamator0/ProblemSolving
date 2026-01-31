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
vector<pair<int, int>> adj[1001];
int d[1001];
int pre[1001];
vector<int> dst;

int st, ed;

void solution()
{

    d[st] = 0;
    //pre[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[st], st});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if (d[cur.second] != cur.first)
            continue;
        for (auto nxt : adj[cur.second])
        {
            if (d[nxt.second] <= nxt.first + d[cur.second])
                continue;
            d[nxt.second] = nxt.first + d[cur.second];
            pq.push({d[nxt.second], nxt.second});
            pre[nxt.second] = cur.second;
        }
    }

    // st -> ed
    // 일단 최소비용은 d[ed]
    int idx = ed;
    //int cnt = 0 ; 
    while (idx != st)
    {
        dst.push_back(idx);
        idx = pre[idx];
    }
    dst.push_back(st);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> m;

    fill(d, d + n + 1, INF);
    //fill(pre, pre + n + 1, INF);

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
    }
    cin >> st >> ed;

    solution();

    // for(int i = 1; i<=n; i++)
    // {
    //     cout << pre[i] <<" ";
    // }
    // cout <<"\n";
    reverse(dst.begin(),dst.end());

    cout << d[ed] <<"\n";
    cout << dst.size() <<"\n";

   
    for(auto x : dst )
        cout << x <<' ';
    cout << "\n";


}
