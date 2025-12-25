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

int visit [100001];
vector<int> graph [100001];
int indegree_count [100001];

int n,m; // node , edge 


void topological_sort()
{
    queue<int> q ;
    for (int i= 1 ; i<n; i++)
    {
        if(graph[i].size()==0)
        {
            q.push(i);
            visit[i] = 1;
        }
    }

    while(!q.empty())
    {
        int cur = q.front();

        cout << cur << " ";
        q.pop();

        for(int i = 1 ; i <=n ; i++)
        {
            for(int j= 0; j< graph[i].size(); j++)
            {
                if(graph[i][j] == cur)
                {
                    indegree_count[i] -=1;
                }
            }
        }
        for(int i =1 ; i<=n; i++)
        {
            if(visit[i] == 1)
                continue;

            if(indegree_count[i] == 0)
            {
                q.push(i);
                visit[i] = 1 ; 
            }    
        }
 
 
    }


}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m ;


    for(int i= 0; i< m; i++)
    {
        int a,b;
        cin >> a >> b ; // a 에서 b로 연결 
        graph[b].push_back(a); 
        indegree_count[b]++;
    }
    
    topological_sort();


}
