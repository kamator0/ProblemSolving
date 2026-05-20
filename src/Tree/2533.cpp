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

#define INF 0x3f3f3f3f // 경우에 따라 다르게
// long long 일

using namespace std;

int n;
vector<int> graph[1000001];
vector<pair<int, int>> edge_cnt;
int visited[1000001];
int cnt[1000001];
pair<int, int> max_node = {-1, -1};

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 1)
            continue;
        for (auto cur : graph[i])
        {
            if (visited[cur] != 1)
                return false;
        }
    }

    return true;
}

void solution()
{
    // int result = 0 ;
    // for(int i = edge_cnt.size()-1; i>0; i--)
    // {
    //     int vx = edge_cnt[i].second;
    //     visited[vx] = 1 ;
    //     result ++;

    //     if(check())
    //     {
    //         cout << result <<"\n";
    //         return;
    //     }

    // }

    // X 표시가 된다면 edge 를 전부 지워야한다는 것?

    int result = 0;
    while (true)
    {
        int vx = max_node.second;
        visited[vx] = 1;
        result ++;
        cout << vx <<"\n";
        for (auto x : graph[vx])
        {
            if (visited[x] == 1)
                continue;
            cnt[x]--;
        }

        if (check())
        {
            cout << result << "\n";
            return;
        }
        max_node = {-1,-1};

        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 1)
                continue;
            if (cnt[i] > max_node.first)
            {
                max_node.first = cnt[i];
                max_node.second = i;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);

        cnt[u]++;
        cnt[v]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] > max_node.first)
        {
            max_node.first = cnt[i];
            max_node.second = i;
        }
    }


    //cout << max_node.first <<" "<<max_node.second <<"\n";
    // sort(edge_cnt.begin(),edge_cnt.end());

    // 최적해일까?
    // 다 막았는지 어떻게 알지?

    // for(auto x : edge_cnt)
    // {
    //     cout << x. first << " " << x.second <<"\n";
    // }

    // 만약 1 부터 한다고 치면  1이 부모가 아니여도 상관 없는데 보니깐
    // 일단 edge 수 많은거 부터 하나씩 지워서 만약에 이동가능하면 false 하고 뚝딱뚝닥 하면 될듯?

    solution();
}
