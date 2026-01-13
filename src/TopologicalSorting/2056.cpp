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

int n;

int indegree[10004];
int work[10004];          // 완료할 때 걸린 시각
int sum_work[10004];      // 따로 걸린 시각 합 저장
vector<int> graph[10004]; // a-> b

int result = 0;

void solution()
{
    queue<int> q; // 몇번인지 말고도 시간도 같이 포함 해야할듯?
    // 1번 작업이 항상그런거는 1번 말고도 indegree 0일 수 있는것
    // 근데 이제 n번째 작업에 도달하는 시간이 다르기 때문에 max해서 ?
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            sum_work[i] = work[i];
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        // cout << cur <<"\n";
        //  int t = q.front().second;
        q.pop();

        for (int nx : graph[cur])
        {
            indegree[nx]--;
            sum_work[nx] = max(sum_work[nx], sum_work[cur] + work[nx]);
            if (indegree[nx] == 0)
            {
                q.push(nx);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        work[i] = t;
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            graph[a].push_back(i);
            indegree[i]++;
        }
    }

    solution();

    // for(int i=1 ; i <=n; i++)
    // {
    //     cout << sum_work[i] <<" ";
    // }
    // cout <<"\n";
    // 1번작업
    for (int i = 1; i <= n; i++)
    {
        result = max(result, sum_work[i]);
    }
    cout << result << "\n";
}
