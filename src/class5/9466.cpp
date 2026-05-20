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
#include <sstream>
#include <iomanip>

#define INF 0x3f3f3f3f // 경우에 따라 다르게
// long long 일

using namespace std;

int t;
int n;
int team[100001];
int p[100001];
int visited[100001];
int finish[100001];
// cycle 을 발생 시켜야하는데 ?
vector<int> result;
int cnt = 0;

void dfs(int cur)
{
    visited[cur] = 1;
    int next = team[cur];
    if (visited[next] != 1)
    {
        dfs(next);
    }
    else if (!finish[next])
    {
        // int idx = team[next];
        // while (idx != cur)
        // {
        //     idx = team[idx];
        //     cnt++;
        // }
        // cnt++;
        int idx = next;
        cnt++; 
        while (idx != cur)
        {
            idx = team[idx];
            cnt++;
        }
    }
    finish[cur] = 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    for (int i = 0; i < t; i++)
    {

        cin >> n;
        fill(team, team + n + 1, 0);
        fill(visited, visited + n + 1, 0);
        fill(finish, finish + n + 1, 0);
        // fill(cnt, cnt + n + 1, 0);
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            // vector<int> graph[n+1];
            // graph[j].push_back(a);
            team[j] = a;
        }

        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == 0)
                dfs(i);
        }
        result.push_back( n-cnt);
        cnt = 0;
    }

    for (auto x : result)
    {
        cout << x << "\n";
    }
}
