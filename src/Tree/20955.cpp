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

int n, m ;
vector<int> graph[100001];
int startnode[100001];
int visit[100001][100001];

int edge_count = 0;
int node_count = 0 ;

int result = 0;


void solution(int x){

    // queue<int> q; 
    // q.push(x);
    // node_count+=1;
    // visited[x] = 1; 

    // while(!q.empty())
    // {
    //     int cur = q.front() ;
    //     q.pop();
    //     for(int nx : graph[cur])
    //     {
    //         if(visited[nx] == 1)
    //             continue;
    //         edge_count +=1;
    //         node_count += 1;
    //         visited[nx] = 1;
    //         q.push(nx);
    //     }

    // }

    // if(visited[x] == 0)
    // {
    //     visited[x] = 1;
    //     node_count +=1;
    // }
    
    // // if(visited[x] == 0)
    // // {
    // //     node_count+=1;
    // //     visited[x] = 1;
    // // }
    // for(int i = 1; i <=n; i++)
    // {
    //     cout<< visited[i] <<" ";
    // }
    // cout<<"\n";

    // for(int nx : graph[x])
    // {
    //     if(nx == before)
    //         continue;
    //     if(visited[nx] == 0 )
    //     {
    //         node_count += 1;
    //         visited[nx] = 1; 
    //         edge_count +=1;
    //         solution(nx, x);
    //     }

    // }
    if(startnode[x] == 0 )
    {
        startnode[x] = 1;
        node_count++;
    }
    // for(int i = 1; i <=n; i++)
    // {
    //     cout<< startnode[i] <<" ";
    // }
    // cout<<"\n";

    for(int nx : graph[x])
    {
        if(visit[x][nx] == 0 || visit[nx][x] == 0)
        {
            visit[x][nx] = 1;
            visit[nx][x] = 1;
            edge_count++;
            solution(nx);
        }
       
    }


}


int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    cin >> n >> m  ;
    
    for(int i = 0 ; i < m ;i ++)
    {
        int a,b;
        cin >> a >> b ;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    // for(int i = 0 ; i< n; i++)
    // {
    //     for(int x: graph[i])
    //     {
    //         cout << x <<" ";
    //     }
    //     cout <<"\n";
    // }
    //tree 와 tree가 아닌 것 
    
    int graph_count = 0 ;
    for(int i = 1; i<=n; i++)
    {
        if(startnode[i] == 1)
            continue;
        solution(i);
        if(edge_count > node_count-1)
        {
            result += (edge_count-node_count+1);
        }
        //cout<< i << " " <<edge_count<< " " << node_count<< " " << result << "\n";
        edge_count = 0 ;    
        node_count = 0;
        graph_count +=1;
    } 

    result+= (graph_count-1);
    
    cout<<result<<"\n";

}
