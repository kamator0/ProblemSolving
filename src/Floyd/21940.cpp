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
int k;
int graph[202][202];
vector<int> f;

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (j == k)
                    continue;
                if (graph[j][k] > graph[j][i] + graph[i][k])
                {
                    graph[j][k] = (graph[j][i] + graph[i][k]);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for(int i = 1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            graph[i][j] = INF;
        }
    }
    

    for (int i = 0; i < m; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        graph[a][b] = t;
    }

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        f.push_back(a); // vector로 처리 해
    }

    solution();

    // for(int i = 1; i<=n; i++)
    // {
    //     for(int j=1; j<=n; j++)
    //     {
    //        cout << graph[i][j] <<" ";
    //     }
    //     cout <<"\n";
    // }

    vector<pair<int, int>> p;

    int m_c =INF; 
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int a = 0; a < f.size(); a++)
        {
            // j부터 i까지 저장 만약 INF면 패스 ? 
            int j = f[a] ;
            if( j == i )
                continue;
            cnt = max(graph[j][i] + graph[i][j], cnt);
            //cout << j <<" "<<i << " " << cnt << "\n";
        }
        m_c = min(m_c,cnt);
        p.push_back({cnt, i});
    }
    // 전부 다 왕복한 시간중 도시별 값중 최대 근데 이제 그 도시중에 최소를 고르는것?

    // for(int i = 0 ; i< p.size(); i++)
    // {
    //     cout << p[i].first <<" " <<p[i].second <<"\n";
    // }

    sort(p.begin(),p.end());

    for(pair<int,int> a : p)
    {
        if(a.first == m_c)
        {
            cout << a.second <<"\n";
        }
        else 
            break;
    }


}
