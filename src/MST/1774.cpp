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
// long long 1e15
using namespace std;

int n, m;

int p[1001];
vector<int> connect;
int edge_count;
pair<int, int> loc[1001];

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
    // (n-1) ! 이러면 무조건 시간 초과
    // queue<int> q ;

    // while(!q.empty())
    // {
    //     int cur = q.front();
    //     q.pop();
    //     // 1
    //     for(int i = 1 ; i<= n ; i++)
    //     {
    //         if(!uni(cur,i))
    //             continue;

    //     }

    // }

    // vector<pair<int, pair<int, int>>> all;

    // vector<pair<int, pair<int, int>>> xw;
    // vector<pair<int, pair<int, int>>> yw;

    // for (int i = 0; i < xs.size() - 1; i++)
    // {
    //     xw.push_back({xs[i].first - xs[i + 1].first, {xs[i].second, xs[i + 1].second}});
    // }
    // for (int i = 0; i < ys.size() - 1; i++)
    // {
    //     yw.push_back({ys[i].first - ys[i + 1].first, {ys[i].second, ys[i + 1].second}});
    // }

    // for (int i = 0; i < xw.size(); i++)
    // {
    //     all.push_back({xw[i].first, {xw[i].second.first, xw[i].second.second}});
    // }
    // for (int i = 0; i < yw.size(); i++)
    // {
    //     all.push_back({yw[i].first, {yw[i].second.first, yw[i].second.second}});
    // }

    // sort(all.begin(), all.end());

    // vector<pair<double, pair<int, int>>> cal;

    // for (int i = 0; i < all.size(); i++)
    // {
    //     int a = all[i].second.first;
    //     int b = all[i].second.second;
    //     cal.push_back({sqrt(pow((loc[a].first - loc[b].first), 2) + pow((loc[a].second - loc[b].second), 2)), {a, b}});
    // }

    // sort(cal.begin(), cal.end());

    vector<pair<double, pair<int, int>>> edges;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            double d = sqrt(pow(loc[i].first - loc[j].first, 2) +
                            pow(loc[i].second - loc[j].second, 2));
            edges.push_back({d, {i, j}});
        }
    }

    sort(edges.begin(),edges.end());

  
    double result = 0.00;
    for (int i = 0; i < edges.size(); i++)
    {
        double w = edges[i].first;
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        // cout << w <<" " << a << " " << b <<"\n";
        if (!uni(a, b))
            continue;
        result += w;
        edge_count++;
        if (edge_count == n - 1)
            break;
    }
    printf("%.2f\n", result);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    fill(p, p + n + 1, -1);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        // xs.push_back({x, i+1});
        // ys.push_back({y, i+1});
        loc[i + 1].first = x;
        loc[i + 1].second = y;
    }

    // sort(xs.begin(), xs.end());
    // sort(ys.begin(), ys.end());

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if(!uni(a, b))
            edge_count++;

    }

    if(edge_count >= n-1)
    {
        cout << 0.00<<"\n";
        return;
    }
 

    solution();
}
