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
// vector<pair<int,int>> graph[1001];  // 길 a b
vector<pair<int, pair<int, int>>> graph;
int p[1001];

int first_edge = 0;

void initialize()
{
    for (int i= 0; i <= n; i++)
        p[i] = -1;
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
        p[u]--;
        p[v] = u;
    }
    else
    {
        p[u] = v;
    }
    return true;
}

void solution()
{
    int wedge_cnt = 1;

    int w_edge = first_edge;

    for (auto p : graph)
    {
        int d = p.first;
        int a = p.second.first;
        int b = p.second.second;
        if (!uni(a, b))
            continue;

        wedge_cnt++;
        if(d == 0)
            w_edge++;
        if (wedge_cnt == n )
            break;
    }

    reverse(graph.begin(), graph.end());

    initialize();
    uni(0,1);

    int bedge_cnt = 1;

    int b_edge = first_edge;

    for (auto p : graph)
    {
        int d = p.first;
        int a = p.second.first;
        int b = p.second.second;
        
        if (!uni(a, b))
            continue;

        bedge_cnt++;
        //cout << d << " " << a <<" " << b <<  " " << b_edge << "\n";
        if(d == 0)
            b_edge++;
        if (bedge_cnt == n)
            break;
    }

    //cout << w_edge <<" "<<b_edge<<"\n";
    cout << pow(w_edge, 2) - pow(b_edge, 2) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    initialize();

    // 0 과 1은 무조건 연결
    int a, b, c;
    cin >> a >> b >> c;

    if(c == 0)
        first_edge ++;
    uni(a,b); 

    for (int i = 0; i < m ; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // graph[a].push_back({b,c});
        // graph[b].push_back({a,c});
        graph.push_back({c, {a, b}});
        //graph.push_back({c, {b, a}});
    }

    

    sort(graph.begin(), graph.end()); // 0

    // for(auto x : graph)
    // {
    //     cout << x.first <<" "<< x.second.first <<" "<<x.second.second <<"\n";
    // }

    solution();
}
