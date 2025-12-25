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

int n,r,q;

vector<int> graph[100001];
int who_parent[100001];
vector<int> query;
vector<int> child[100001];
int countsubNode[100001];

void makeTree(int cur,int parent){
    for (int node : graph[cur])
    {
        if(node != parent)
        {
            // 자식 노드 추가 
            // 부모 노드로 
            child[cur].push_back(node);
            who_parent[node] = cur;
            makeTree(node,cur);
        }
    }
}
void count_subTreeNode(int cur)
{
    countsubNode[cur] =1 ;
    for(int node : child[cur])
    {
        count_subTreeNode(node);
        countsubNode[cur] += countsubNode[node];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r>> q;
    for(int i = 0 ; i< n-1; i++)
    {
        int u, v ;
        cin >> u >> v ;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i= 0; i < q; i++)
    {
        int w ;
        cin >> w;
        query.push_back(w);
    }

    // root를 문제대로 5라고 해버림 ㄷㄷ 
    makeTree(r,-1);
    count_subTreeNode(r);

    for(int x : query)
    {
        cout << countsubNode[x] <<"\n";
    }
}
