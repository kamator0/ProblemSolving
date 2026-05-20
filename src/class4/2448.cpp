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
char graph[3073][6145];

// 3 * 1024
// 3 * 1024 * 2  6144
// 3000 * 6000 * 4 72 * 10 ^6

void dfs(int n, int r, int c)
{
    if (n == 3)
    {
        graph[r][c] = '*';
        graph[r + 1][c - 1] = '*';
        graph[r + 1][c + 1] = '*';
        graph[r + 2][c - 2] = '*';
        graph[r + 2][c - 1] = '*';
        graph[r + 2][c] = '*';
        graph[r + 2][c + 1] = '*';
        graph[r + 2][c + 2] = '*';
        return;
    }
    dfs(n/2, r,c);  // 위
    dfs(n/2,r+n/2,c-n/2);
    dfs(n/2,r+n/2,c+n/2);
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for(int i = 1;  i<=n; i++)
    {
        for(int j = 1; j<=n * 2; j++)
        {
            graph[i][j] = ' ';
        }
    }
    // 작은거 만들고 큰거 만들고?
    dfs(n,1,n);

    for(int i =1 ; i<= n; i++)
    {
        for(int j =1; j<=n*2; j++)
        {
            cout << graph[i][j] ;
        }
        cout <<"\n";
    }
 
}


