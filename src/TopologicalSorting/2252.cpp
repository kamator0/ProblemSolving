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

vector<int> graph[32001] ;
int indegree_count[32001];


void solution(){
    queue<int> q ;
    for(int i= 1 ; i <=n ; i++ )
    {
        if(indegree_count[i] == 0 )
            q.push(i);
    }

    vector<int> result;
    while(!q.empty())
    {
        int cur = q.front();
        result.push_back(cur);
        q.pop();

        for(int nx : graph[cur])
        {
            indegree_count[nx]--;
            if(indegree_count[nx] == 0)
                q.push(nx);
        }
        
    }
    for(int x : result)
    {
        cout << x <<" ";
    }
    cout<<"\n";


}





int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0 ; i < m; i++)
    {
        int a, b ;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree_count[b]++;
    }
    
    solution();

}
