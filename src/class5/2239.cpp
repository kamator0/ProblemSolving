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
int graph[10][10];
vector<pair<int, int>> zeros;

// 자기 열 검사
void row(int r, int c, vector<int> &check)
{

    for (int i = 1; i <= 9; i++)
    {

        if (graph[i][c] != 0)
        {
            check[graph[i][c]] = 1;
        }
    }
    // vector<int> v;
    // for (int i = 1; i <= 9; i++)
    // {
    //     if (check[i] != 1)
    //     {
    //         v.push_back(i);
    //     }
    // }

    // return v;
}

// 자기 행 검사
void col(int r, int c, vector<int> &check)
{

    for (int i = 1; i <= 9; i++)
    {

        if (graph[r][i] != 0)
        {
            check[graph[r][i]] = 1;
        }
    }
    // vector<int> v;
    // for (int i = 1; i <= 9; i++)
    // {
    //     if (check[i] != 1)
    //     {
    //         v.push_back(i);
    //     }
    // }

    // return v;
}

void area(int r, int c, vector<int> &check)
{
    // vector<int> check(10, 0);

    // 1 ~ 9
    // 1 ~ 9

    int rl, rr, ll, lr;

    if (r <= 3)
    {
        rl = 1;
        rr = 3;
    }
    else if (r <= 6)
    {
        rl = 4;
        rr = 6;
    }
    else
    {
        rl = 7;
        rr = 9;
    }

    if (c <= 3)
    {
        ll = 1;
        lr = 3;
    }
    else if (c <= 6)
    {
        ll = 4;
        lr = 6;
    }
    else
    {
        ll = 7;
        lr = 9;
    }

    for (int i = rl; i <= rr; i++)
    {
        for (int j = ll; j <= lr; j++)
        {
            if (graph[i][j] != 0)
            {
                check[graph[i][j]] = 1;
            }
        }
    }

    // vector<int> v;
    // for (int i = 1; i <= 9; i++)
    // {
    //     if (check[i] != 1)
    //     {
    //         v.push_back(i);
    //     }
    // }

    // return v;
}

void solution(int idx)
{
    if (idx == zeros.size())
    {
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                cout << graph[i][j] ;
            }
            cout << "\n";
        }
        exit(0);
    }

    int y = zeros[idx].first;
    int x = zeros[idx].second;
    vector<int> check(10, 0);

    row(y, x, check);
    col(y, x, check);
    area(y, x, check);

    
    for (int i = 1; i <= 9; i++)
    {
        if (check[i] == 0)
        {
            graph[y][x] = i;
            solution(idx + 1);
            graph[y][x] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    for (int i = 1; i <= 9; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= 9; j++)
        {
            graph[i][j] = s[j - 1] - '0';
            if (graph[i][j] == 0)
                zeros.push_back({i, j});
        }
    }

    solution(0);
}
