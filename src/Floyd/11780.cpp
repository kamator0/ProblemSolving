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

int n, m;
int graph[105][105];
int nx[105][105];

vector<int> dst[105][105];

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if(j==k)
                    continue;
                if (graph[j][k] > graph[j][i] + graph[i][k])
                {
                    graph[j][k] = graph[j][i] + graph[i][k];
                    nx[j][k] = nx[j][i]; // j k로 가는거보다 i k 다음
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        // i 부터 j까지 가는데
        for (int j = 1; j <= n; j++)
        {
            if (i == j || graph[i][j] == INF) // i와 j 일 때와 graph[i][j] 가 INF이면 경로가 없음
            {
                continue;
            }
            // nx[i][j] -> j 는 고정
            dst[i][j].push_back(i);
            int idx = nx[i][j];
           
            while (idx != j)
            {
                dst[i][j].push_back(idx);
                idx = nx[idx][j];
                
            }
            dst[i][j].push_back(j);
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
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = INF;
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (graph[a][b] > c)
        {
            graph[a][b] = c;
            nx[a][b] = b;
        }
    }

    solution();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (graph[i][j] == INF)
            {
                cout << 0 << " ";
                continue;
            }
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }

    for(int i = 1; i <=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            cout << dst[i][j].size() <<" ";
            for(int a :  dst[i][j])
            {
                cout << a<<" ";
            }
            cout <<"\n";
        }
    }


}
