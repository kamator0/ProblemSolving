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

int n, m, k;
vector<pair<int, pair<int, int>>> graph;
int e[1001];
int p[1001];

int find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
    u = find(u);
    v = find(v);

    // 일단 다 연결하고 빼는게 맞는거 같은데??
    if (u == v)
        return false;
    if (p[u] < p[v])
    {
        p[v] = u;
    }
    else if (p[u] == p[v])
    {
        p[v] = u;
        p[u]--;
    }
    else
    {
        p[u] = v;
    }
    return true;
}

void solution()
{
    int edge_cnt = 0;

    int result = 0;

    for (auto x : graph)
    {
        int w = x.first;
        int u = x.second.first;
        int v = x.second.second;
        if (!uni(u, v))
            continue;
        // if(find(u) == find(v))
        edge_cnt++;
        result += w;
        //cout << w << " " << u << " " << v << "\n";
        if (edge_cnt == n) // 가상의 점 1개 추가 후 n + 1 -1 = n 
            break;
    }

    // 다 연결하고 빼는 것?
    // for(int i =1 ; i<=n ; i++)
    // {
    //     cout << p[i] <<" ";
    // }
    // cout <<"\n";

    cout << result << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    fill(p, p + n + 1, -1);

    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        graph.push_back({0,{a,0}});
    }
    for (int i = 0; i < m; i++)
    {

        int u, v, w;
        cin >> u >> v >> w;
        graph.push_back({w, {u, v}});
    }

    sort(graph.begin(), graph.end());

    solution();
}
