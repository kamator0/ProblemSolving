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

int cnt[101];
int n, m;
int graph[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cnt[i] = INF;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    cnt[1] = 0;

    priority_queue<pair<int, int>> pq;

    for (int i = 1; i <= n; i++)
    {
        if (graph[1][i] == 0)
            continue;
        pq.push({-graph[1][i], i}); 
    }

    while (!pq.empty())
    {
        int d = -pq.top().first;
        int nx = pq.top().second;
        pq.pop();

        if(cnt[nx] != INF)
            continue;
    
        cnt[nx] = d ;
        cout << nx << " " << cnt[nx] << "\n";

        for (int i = 1; i <= n; i++)
        {
            if (graph[nx][i] == 0)
            {
                continue;
            }
            if (cnt[i] != INF)
                continue;

            //cnt[i] = (cnt[nx] + graph[nx][i]);
            pq.push({-(cnt[nx] + graph[nx][i]), i});
        }
    }

    for (int i = 1.; i <= n; i++)
    { 
        cout << cnt[i] << " ";
    }
    cout << "\n";
}
