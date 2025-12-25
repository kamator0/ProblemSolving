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

using namespace std;

vector<pair<int,pair<int,int>>> graph;
int p [100001];
int result = 0;
int n,m;

void initialize(){
    for(int i = 1 ;i<=n; i++)
        p[i] = -1;
}


int find(int x)
{
    if(p[x] < 0 )
        return x;
    return p[x] = find(p[x]);
}

bool uni(int u,int v)
{
    u = find(u);
    v = find(v);
    if(u==v)
        return false;
    if(p[u] < p[v])
    {
        p[v] = u;
    }
    else if(p[u]== p[v])
    {
        p[v] = u;
        p[u] --;
    }
    else{
        p[u] =v ;
    }
    return true;
}

void solution()
{
    int edge_count = 0;
    for(pair<int, pair<int,int>> p : graph)
    {
        if(edge_count == n-1 )
            return;
        int d = p.first;
        int a = p.second.first;
        int b = p.second.second;
        if(!uni(a,b))
            continue;
        result+=d;
        edge_count++;
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m ;

    initialize();

    for(int i = 0; i< m; i++)
    {
        int a,b,d;
        cin >> a >> b >> d ;
        graph.push_back({d,{a,b}});
    }

    sort(graph.begin(),graph.end());

    // for(pair<int, pair<int,int>> p : graph)
    // {
    //     cout<< p.first <<" "<< p.second.first <<" "<<p.second.second <<"\n";
    // }

    solution();

    cout << result <<"\n";
    
}
