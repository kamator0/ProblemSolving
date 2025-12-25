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

bool solution(vector<int> graph[],int cur,int before,vector<int> &visited)
{   

    visited[cur] = 1;
    // 사이클이 만들어지는지 확인
    for(int next :  graph[cur])
    {
        if (next == before)
            continue;
        if (visited[next] ==1)
            return false;
        if(!solution(graph,next,cur,visited))
            return false;
            
    }

    return true;
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int case_num = 1;
    vector<string> result;
    int tree_count = 0 ; 
    while(true)
    {
        int n,m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        vector<int> graph[501];
        vector<int> visited(n+1,0);
        vector<int> whoparnet(n+1,0);

        for(int i = 0 ; i < m; i++)
        {
            int a ,b ;
            cin >> a >> b ;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    

        for(int i = 1; i<=n; i++)
        {
            if(visited[i] == 1)
                continue;

            bool flag = solution(graph,i,0,visited);
            if(flag)
                tree_count++;
        }

        if(tree_count == 1)
        {
            string str = "Case "+ to_string(case_num)+": There is one tree.";
            result.push_back(str);
        }
        else if(tree_count == 0)
        {
            string str = "Case "+ to_string(case_num)+": No trees.";
            result.push_back(str);
        }
        else{
            string str = "Case "+ to_string(case_num)+": A forest of "+to_string(tree_count) +" trees.";
            result.push_back(str);
        }
        case_num++;
        tree_count = 0;
    }

    for(string s : result)
    {
        cout<<s<<"\n";
    }
}
