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

int n,m;
vector<pair<int,int>> graph[1001]; //  node disitance [node] [node] to node distance
vector<int> result;


void solution(int start,int end, int cost, vector<int> &visited)
{
    
    visited[start] = 1; 
    if(start == end)
    {
        result.push_back(cost);
        return;
    }
    
    for(pair<int,int> node: graph[start])
    {
        if(visited[node.first] == 1)
            continue;
        solution(node.first,end,cost+node.second,visited);
    }


}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , m ;
    cin >> n >> m ;

    for(int i = 0; i < n-1; i++)
    {
        int a, b, d ;
        cin >> a >> b >> d;
        graph[a].push_back({b,d});
        graph[b].push_back({a,d});
    }


    vector<pair<int,int>> starttoend;
    for(int i = 0; i < m; i++)
    {
        int s,e;
        cin >> s>> e;
        starttoend.push_back({s,e});
    } 

    for(pair<int,int> p : starttoend)
    {
        vector<int> visited(n+1, 0);
        solution(p.first,p.second,0 ,visited);

    }
   
    for(int c : result)
    {
        cout << c <<"\n";
    }
}
