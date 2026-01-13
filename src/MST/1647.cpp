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

int n,m;

int edge_count = 0;
int p[100005];
vector<pair<int,pair<int,int>>> graph;
long result = 0;

void initialize()
{
    for(int i=1; i<=n; i++)
        p[i] = -1;
}


int find(int x)
{
    if(p[x] < 0)
    {
        return x;
    }
    return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u==v)
        return false;
    if(p[u] < p[v])
        p[v] = u ;
    else if(p[u]==p[v])
    {
        p[v] = u;
        p[u]--;
    }
    else
        p[u] =v ;
    return true;
}


void solution()
{
    for(int i = 0; i< graph.size(); i++)
    {
        if(edge_count == n-2)
            break;
        int w;
        int a;
        int b;
        w =graph[i].first;
        a = graph[i].second.first;
        b = graph[i].second.second;

        
        if(!uni(a,b))
            continue;
        
        result += w;
        edge_count ++;
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    initialize();

    for(int i = 0; i< m; i++)
    {
        int a,b,w;
        cin >> a >>b >> w;
        graph.push_back({w,{a,b}});
    }
    sort(graph.begin(),graph.end());


    solution();

    cout << result <<"\n";
}
