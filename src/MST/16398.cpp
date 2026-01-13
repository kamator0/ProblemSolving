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

#define INF 12345678

using namespace std;

int n;

vector<pair<int, pair<int, int>>> graph;

int p[1004];

int edge_count = 0;
long result = 0;

void initialize()
{
    for (int i = 1; i <= n; i++)
    {
        p[i] = -1;
    }
}

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
    for (pair<int, pair<int, int>> p : graph)
    {
        int w = p.first;
        int a = p.second.first;
        int b = p.second.second;
        if (edge_count == n - 1)
            return;
        //cout << w <<" " << a <<" "<<b <<" "<< edge_count << "\n";
        if (!uni(a, b))
            continue;
        edge_count++;
        result += w;

        
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    initialize();
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            int w;
            cin >> w;
            if (i >= j)
                continue;

            graph.push_back({w, {j, i}}); //
        }
    }

    sort(graph.begin(), graph.end());

    // for (pair<int, pair<int, int>> p : graph)
    // {
    //     cout << p.first << " " << p.second.first << " " << p.second.second << "\n";
    // }
    

    solution();

    cout << result << "\n";
}
