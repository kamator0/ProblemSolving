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

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int r, c, t;
int graph[51][51];
int c_graph[51][51];

// 1000 * 50 * 50  = 25 * 10^6
pair<int, int> up = {-1, -1}; // 세로 가로
pair<int, int> down = {-1, -1};

// vector<pair<int, int>> air;

void spread()
{

    for (int y = 1; y <= r; y++)
    {
        for (int x = 1; x <= c; x++)
        {
            if (graph[y][x] <= 0)
                continue;
            int cnt = 0;
            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (nx < 1 || nx > c || ny < 1 || ny > r)
                    continue;
                // if ((ny == up.first && nx == up.second) || (ny == down.first && nx == down.second))
                //     continue;
                if (graph[ny][nx] == -1)
                    continue;
                c_graph[ny][nx] += (graph[y][x] / 5);
                cnt++;
            }

            graph[y][x] -= cnt * (graph[y][x]/5);
        }
    }
  

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            graph[i][j] += c_graph[i][j];
        }
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            c_graph[i][j] = 0;
        }
    }

    graph[up.first][up.second] = -1;
    graph[down.first][down.second] = -1;
    // for (int i = 1; i <= r; i++)
    // {
    //     for (int j = 1; j <= c; j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

void move()
{
    // down left up right 이런 순으로 해야함

    for (int i = up.first; i > 1; i--)
        graph[i][1] = graph[i - 1][1];

    for (int j = 1; j < c; j++)
        graph[1][j] = graph[1][j + 1];

    for (int i = 1; i < up.first; i++)
        graph[i][c] = graph[i + 1][c]; //

    for (int i = c; i > 2; i--)
        graph[up.first][i] = graph[up.first][i - 1]; // 오른쪽

    graph[up.first][2] = 0;
    graph[up.first][up.second] = -1;

    for (int i = down.first; i < r; i++)
        graph[i][1] = graph[i + 1][1]; //

    for (int j = 1; j < c; j++)
        graph[r][j] = graph[r][j + 1];

    for (int i = r; i > down.first; i--)
        graph[i][c] = graph[i - 1][c];

    for (int i = c; i > 2; i--)
        graph[down.first][i] = graph[down.first][i - 1]; // 오른쪽

    graph[down.first][down.second] = -1;

    graph[down.first][2] = 0;

    // for (int i = 1; i <= r; i++)
    // {
    //     for (int j = 1; j <= c; j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

void solution()
{
    while (t > 0)
    {

        // n^2 * t 까지는 괜찮

        // 미세 확산
        spread();
        // 이동
        // cout << "1" << "\n";
        move();

        // air.clear();

        t--;
    }
    
    int result = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (graph[i][j] == -1)
                continue;
            result += graph[i][j];
        }
    }

    cout << result << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c >> t;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            int a;
            cin >> a;
            if (a == -1)
            {
                if (up.first == -1)
                {
                    up = {i, j};
                }
                else
                {
                    down = {i, j};
                }
            }
            // else if (a >=5 ) {
            //     air.push_back({i,j});
            // }
            graph[i][j] = a;
        }
    }

    solution();
}
