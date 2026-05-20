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

int dx[4] = {0, 0, -1, 1}; // 가로
int dy[4] = {1, -1, 0, 0}; // 세로

int n, m; // 세로 가로

int graph[101][101];
int vc[101][101];
int visited[101][101];
int cnt = 0;



void bfs()
{
    queue<pair<int, int>> q;

    int t = 0;
    while (true)
    {
        if (cnt == 0)
            break;
        q.push({1, 1});
        visited[1][1] = 1;

        while (!q.empty())
        {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (nx < 1 || nx > m || ny < 1 || ny > n)
                    continue;

                if (visited[ny][nx] == 1)
                    continue;
                if (graph[ny][nx] == 1)
                {
                    vc[ny][nx] += 1;
                    continue;
                }
                visited[ny][nx] = 1;
                q.push({ny, nx});
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (vc[i][j] >= 2)
                {
                    graph[i][j] = 0;
                    cnt--;
                }
            }
        }

        for(int i = 1;  i<=n ; i++)
        {
            for(int j =1 ; j<=m ; j++)
            {
                visited[i][j] = 0; 
            }
        }
        for(int i = 1;  i<=n ; i++)
        {
            for(int j =1 ; j<=m ; j++)
            {
                vc[i][j] = 0; 
            }
        }
        t++;
    }

    cout << t << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int a;
            cin >> a;
            if (a == 1)
            {
                // cheeze.push_back({i, j});
                cnt++;
            }
            graph[i][j] = a;
        }
    }

    // cout << cnt << "\n";
    //  치즈가 없는 곳중 외부공기 유입이 없는것들을 먼저 찾기?

    bfs();
}
