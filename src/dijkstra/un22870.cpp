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

#define INF 1000000000000000LL // 경우에 따라 다르게
// long long 일

using namespace std;

int n, m;
//
int s, e;

vector<pair<long long, int>> adj[200001];

long long se[200001];
long long es[200001]; // ??

int visited[200001];

void solution()
{
    if (s == e) {
        cout << 0 << "\n";
        return;
    }

    fill(se, se + n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> spq;

    se[s] = 0;
    spq.push({se[s], s});

    while (!spq.empty())
    {
        long long w = spq.top().first;
        int cur = spq.top().second;
        spq.pop();

        if (se[cur] != w)
            continue;

        for (auto x : adj[cur])
        {
            if (se[x.second] <= se[cur] + x.first)
                continue;
            se[x.second] = se[cur] + x.first;

            spq.push({se[x.second], x.second});
        }
    }

    //
    queue<int> sq;
    sq.push(s);
    visited[s] = 1;

    // // 1 -> (0~ adj sizee()) 돌아가면 처음 나오는게 무조건 사전 순서가 크지 않을까?
    while (!sq.empty())
    {
        int cur = sq.front();
        sq.pop();

        if(cur == e)
            break;

        for (auto x : adj[cur])
        {
            if(visited[x.second] == 1)
                continue;
            if (se[x.second] == x.first + se[cur])
            {
                // 어떻게 저장?
                sq.push(x.second);
                visited[x.second] = 1;
                break;
            }
        }
    }



    fill(es, es + n + 1, INF);
    visited[s] = 0 ;
    visited[e] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> epq;

    es[e] = 0;
    epq.push({es[e], e});

    while (!epq.empty())
    {
        long long w = epq.top().first;
        int cur = epq.top().second;
        epq.pop();

        if (es[cur] != w)
            continue;

        for (auto x : adj[cur])
        {
            if (visited[x.second] == 1)
                continue;
            if (es[x.second] <= es[cur] + x.first)
                continue;

            es[x.second] = es[cur] + x.first;

            epq.push({es[x.second], x.second});
        }
    }

    // queue<int> eq;
    // eq.push(e);
    // visited[e] = 1;

    // while (!eq.empty())
    // {
    //     int cur = eq.front();
    //     eq.pop();

    //     for (auto x : adj[cur])
    //     {
    //         if (se[x.second] == x.first + se[cur])
    //         {
    //             // 어떻게 저장?
    //             eq.push(x.second);
    //             visited[x.second] = 1;
    //             break;
    //         }
    //     }
    // }
    long long result = se[e] + es[s];

    cout << result << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c ;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    cin >> s >> e;



    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end(), [](auto &a, auto &b)
             { return a.second < b.second; });
    }

    solution();
}
