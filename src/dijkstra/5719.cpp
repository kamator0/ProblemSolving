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
// long long 일

using namespace std;

int n, m;
int s, d;

vector<int> result;

// m * p 10 ^ 7
void solution(vector<pair<int, int>> adj[])
{
    // 최단 경로 찾고
    // 거의 최단 경로 찾으면 될듯?
    int cnt[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cnt[i][j] = INF;
        }
    }

    int pre[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            pre[i][j] = -1;
        }
    }

    // int pre[n];
    // fill (pre,pre+n,0);

    cnt[s][s] = 0;
    // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    pq.push({cnt[s][s], s, s});

    // 이동경로를 어떻게 처리??
    while (!pq.empty())
    {
        auto [w, cur, before] = pq.top();
        pq.pop();

        if (cnt[before][cur] != w)
            continue;

        for (auto nx : adj[cur])
        {
            if (cnt[cur][nx.second] <= cnt[before][cur] + nx.first)
                continue;
            cnt[cur][nx.second] = cnt[before][cur] + nx.first;
            pre[cur][nx.second] = cur;
            pq.push({cnt[cur][nx.second], nx.second, cur});
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cnt[i][j] == INF)
            {
                cout << 0 << " ";
                continue;
            }
            cout << cnt[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << pre[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";

    // vector<pair<int,int>> []

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> tpq;

    for (int i = 0; i < n; i++)
    {
        if (cnt[i][d] == INF)
            continue;
        tpq.push({cnt[i][d], i});
    }

    // cout << tpq.size() <<"\n";
    vector<int> last;

    // int idx = tpq.top().first;
    int idx = tpq.top().first;
    while (!tpq.empty())
    {
        if (idx != tpq.top().first)
            break;
        last.push_back(tpq.top().second);
        idx = tpq.top().first;
        tpq.pop();
    }

    int visited[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            visited[i][j] = -1;
    }

    queue<int> q;
    for (int i = 0; i < last.size(); i++)
    {
        //cout << last[i] <<" ";
        visited[last[i]][d] = 1;
        q.push(last[i]);
    }
    //cout <<"\n";

    //cout << q.size() <<"\n";

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        //cout << cur <<"\n";
        for (int i = 0; i < n; i++)
        {
            if (pre[i][cur] == -1)
                continue; // -1 은 당연히 스킵하고 
            if (visited[i][cur] == 1)
                continue;
            visited[i][cur] = 1;
            q.push(pre[i][cur]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << visited[i][j] << " ";
        cout <<"\n";
    }

    int lcnt[n];
    fill(lcnt, lcnt + n, INF);

    lcnt[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> lpq;

    lpq.push({lcnt[s], s});

    while (!lpq.empty())
    {
        int w = lpq.top().first;
        int cur = lpq.top().second;
        lpq.pop();

        if (lcnt[cur] != w)
            continue;

        for (auto nx : adj[cur])
        {
            if (lcnt[nx.second] <= lcnt[cur] + nx.first)
                continue;
            if (visited[cur][nx.second] == 1)
                continue;
            lcnt[nx.second] = lcnt[cur] + nx.first;
            lpq.push({lcnt[nx.second], nx.second});
        }
    }

    if (lcnt[d] == INF)
    {
        result.push_back(-1);
    }
    else
        result.push_back(lcnt[d]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        cin >> s >> d;
        vector<pair<int, int>> adj[n]; // 0부터 n-1까지
        // vector<int> cnt(n,0);
        for (int i = 0; i < m; i++)
        {
            int u, v, p;
            cin >> u >> v >> p;
            adj[u].push_back({p, v});
        }

        solution(adj);
    }

    for (int a : result)
    {
        cout << a << "\n";
    }
}
