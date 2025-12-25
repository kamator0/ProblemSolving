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
vector<int> graph[100001];
int visit[100001];


int n,m ; 
int result = 0;


void iscycle(int cur)
{
    //cout << cur <<" "<<before <<"\n";
    if(visit[cur] == 1) 
        return; 
    visit[cur] = 1;
    for(int nx : graph[cur])
        iscycle(nx);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0 ; i< m; i++)
    {
        int a, b ;
        cin >> a >> b ;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int group_count = 0;
    for(int i = 1; i <= n; i++)
    {
        if(visit[i] == 1)
            continue;
        iscycle(i);
        group_count ++;
    }
    result = (group_count-1) + (m+group_count-1)-(n-1); // 일단 다 연결 시키고 전체 간선에서 트리 성질을 이용한 n-1
    cout << result<<"\n";

}
