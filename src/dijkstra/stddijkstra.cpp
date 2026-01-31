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


int v,e,st;
vector<pair<int,int>> adj[20005];
int d[20005];
int pre[20005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> v >> e ;
    cin >> st; 
    fill (d,d+v+1,INF);
    fill (pre,pre+v+1, INF);


    for(int i = 0 ; i< e; i++)
    {
        int u,v,w ;
        cin >> u >> v >> w ;
        adj[u].push_back({w,v});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> pq;

    d[st] = 0; 
    pre[st] = 0;
    pq.push({d[st],st});
    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if(d[cur.second] != cur.first) continue; 
        for (auto nxt : adj[cur.second]){
            if(d[nxt.second] <= d[cur.second] + nxt.first)
                continue;
            d[nxt.second] = d[cur.second] +nxt.first ;
            pre[nxt.second] = cur.second;
            pq.push({d[nxt.second],nxt.second});
        }
    }
    for(int i = 1; i<=v; i++)
    {
        if(d[i] == INF)
            cout << "INF" <<"\n";
        else 
            cout << d[i] <<"\n";
    } 

    for(int i = 1; i<=v; i++)
    {
        cout << pre[i] <<" ";
    }
    cout <<"\n";


}
