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

int node[100001];


vector<pair<int,int>> graph [100001]; // u, v, d

//vector<tuple<int,int,int>> grpah[10001];

priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>> > q ;

int n,m;
int result = 0;
int edge_count = 0 ;

void solution(int x)
{

    //node.push_back(x);
    node[x] =1; 
    for(pair<int,int> p : graph[x])
    {

        q.push({p.second,x,p.first});
        // tie(p.second,x,p.first)
    }

    while(!q.empty())
    {
        tuple<int,int,int> cur = q.top();
        q.pop();
        if(node[get<2>(cur)] == 1 )
            continue;
        cout << get<0>(cur) <<" " <<get<1>(cur)<<" "  <<get<2>(cur) <<"\n";
        int nx = get<2>(cur);
        edge_count+=1;
        result += get<0>(cur);
        node[nx] = 1;

        if(edge_count == n-1)
            return;

        for(pair<int,int> p : graph[nx])
        {
            if(node[p.first] == 1)
                continue;
            q.push({p.second,nx,p.first});
            // 연결 할 노드가 연결되어있는지? 
        }

        // if(node[get<2>(cur)] == 1)
        //     continue;

        // edge_count+=1;
        // if(edge_count == n-1)
        //     return;
        // int nx = get<2>(cur);
        // node[get<1>(cur)] = 1; 
        // result += get<0>(cur);
        // for(pair<int,int> p : graph[nx] )
        // {
        //     if(node[p.first] == 1)
        //         continue;
        //     q.push({p.second,nx,p.first});
        // }


    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m ;
    for(int i = 0 ;  i < m ; i++)
    {
        int d,a,b;
        cin >> a>>b >> d;
        graph[a].push_back({b,d});
        graph[b].push_back({a,d});
    }

    int cur = 3;
    solution(cur);
    

    cout << result <<"\n";
}
