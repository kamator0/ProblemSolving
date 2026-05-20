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

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0}; // 아래 위 오른족 왼쪽

int r, c;
char graph[21][21];
int visited[26]; // 알파벳 26개
int result = -1;

void solution(int y, int x, int cnt)
{
    // cout << y << " " << x << " " << cnt << "\n";

    // for (int i = 0; i < 26; i++)
    // {
    //     cout << visited[i] << " ";
    // }

    // cout << "\n";
    result = max(cnt, result);
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > c || ny < 1 || ny > r) // y축 x축 순간 헷갈림;;
            continue;
        if (visited[(int)graph[ny][nx] - 65] == 1)
            continue;
        // cout << nx <<" " <<ny  <<"\n";
        // cout << graph[nx][ny] <<"\n";
        // cout << (int)graph[nx][ny] - 65 <<"\n";
        // cout << visited[(int)graph[nx][ny] - 65] <<"\n";
        visited[(int)graph[ny][nx] - 65] = 1;
        solution(ny, nx, cnt + 1);
        visited[(int)graph[ny][nx] - 65] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            char cc;
            cin >> cc;
            graph[i][j] = cc;
        }
    }
    // for (int i = 1; i <= r; i++)
    // {
    //     for (int j = 1; j <= c; j++)
    //     {
    //         cout << graph[i][j] <<" ";
    //     }
    //     cout <<"\n";
    // }

    // cout << (int)graph[1][1] <<"\n";

    // for(int i = 0 ; i < 26; i++)
    // {
    //     cout << visited[i] <<" ";
    // }

    // cout<<"\n";

    visited[(int)graph[1][1] - 65] = 1;

    solution(1, 1, 1);

    cout << result << "\n";
}
