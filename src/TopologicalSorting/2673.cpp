/*
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

int n , m;
int result = 0;

vector<pair<int,int>> graph[104] ; // 
//vector<int> graph[104];
int basecnt[104];
int indegree[104] ;

void solution()
{
    queue<int> q;
    for(int i= 1; i<=n ; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        // 기본 부품과 중간 부품 따로 생각? 
        for(pair<int,int> p : graph[cur])
        {
            // x, k 
            int nx = p.first;
            indegree[nx] -= p.second;
            // 
            basecnt[cur] += p.second;

            if(indegree[nx] == 0)
                q.push(nx);
        }
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n ; // n이 완제
    cin >> m;

    for(int i= 0 ;i < 8; i++)
    {
        int x,y,k;
        cin >> x >> y >> k ;
        graph[y].push_back({x,k});
        indegree[x] += k;
    }


    // 출력값 기본 부품의 번호와 소요 개수 출력



}
*/


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

int n , m;
int result = 0;

vector<pair<int,int>> graph[104] ; // 
//vector<int> graph[104];
int basecnt[104];
int indegree[104] ;

void solution()
{
    queue<int> q;
    // for(int i= 1; i<=n ; i++)
    // {
    //     if(indegree[i] == 0)
    //     {
    //         q.push(i);
    //     }
    // }
    q.push(n);
    
    basecnt[n] = 1;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        // 기본 부품과 중간 부품 따로 생각? 
        for(pair<int,int> p : graph[cur])
        {
            // x, k 
            int nx = p.first;

            basecnt[nx] += (basecnt[cur] * p.second);

            indegree[nx] -= p.second;
            // 

            if(indegree[nx] == 0)
                q.push(nx);
        }
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n ; // n이 완제
    cin >> m;

    for(int i= 0 ;i < m; i++)
    {
        int x,y,k;
        cin >> x >> y >> k ;
        graph[x].push_back({y,k});
        indegree[y] += k;
    }


    // 출력값 기본 부품의 번호와 소요 개수 출력
    solution();

    for(int i = 1; i<=n; i++)
    {
        if(graph[i].empty())
        {
            cout << i <<" " << basecnt[i] <<"\n";
        }
    }

}