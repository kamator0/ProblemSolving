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

#define INF 1e18 // 경우에 따라 다르게


using namespace std;

int n,m;

//int graph[100001][100001];
long long d[100001];
//vector<pair<int,int>> adj;

//pair<int,int> adj[700001];

// 1->4 ;

vector<pair<int,int>> adj[100001];


void solution()
{
    fill(d,d+n+1,INF);

    // 1 을 일단 ㅇ 

    priority_queue<pair<long long,int>, vector<pair<long long,int>> , greater<pair<long long,int>>> pq;

    d[1] = 0 ;
    pq.push({d[1],1});

    while(!pq.empty())
    {
        long long w = pq.top().first;
        int cur = pq.top().second;

        pq.pop();

        if(d[cur] != w)
            continue;

        for(auto nx : adj[cur])
        {
            // nx.first 를 어떻게 처리할래? 
            long long idx = 0  ;
            if(d[cur] % m  > nx.first) // 
            {
                idx =  m * (d[cur] /m  +1) + nx.first ;
            }
            else{
                idx = m *(d[cur]/ m) + nx.first;
            }
            if(d[nx.second] <= idx)
                continue;
            
            d[nx.second] = idx + 1;
            pq.push({d[nx.second], nx.second});

        }

    }


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m ;
    for(int i = 1 ; i <=m ; i++)
    {
        int a, b ;
        cin >> a >> b ;
        //adj[i].first = a ;
        //adj[i].second = b ; 
        adj[a].push_back({i-1,b});
        adj[b].push_back({i-1,a});
    }

    
    solution();
    

    cout << d[n] <<"\n";
}

