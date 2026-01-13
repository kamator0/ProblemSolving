// #include <iostream>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <queue>
// #include <stack>
// #include <deque>
// #include <map>
// #include <unordered_map>
// #include <set>
// #include <unordered_set>
// #include <cmath>
// #include <numeric>
// #include <limits>

// #define INF 12345678

// using namespace std;

// int n;

// vector<pair<int, int>> graph[10004]; // c -> p
// // vector<pair<int,pair<int,int>>> graph;
// vector<int> child[10004];
// int visited[10004];
// int p[10004];
// int w_c[10004]; // root 부터 n번째 node 까지의 거리

// int result = 0;

// void bfs()
// {
//     queue<int> q;
//     for (int i = 1; i <= n; i++)
//     {
//         if (child[i].size() == 0)
//             q.push(i);
//     }

//     while (!q.empty())
//     {
//         int cur = q.front();
//         q.pop();
//         cout << cur << " " << w_c[cur]<< " " <<result << "\n";
//         if (cur == 1)
//             break;
//         if (w_c[p[cur]] == 0)
//         {
//             w_c[p[cur]] = w_c[cur] + graph[cur][0].second;
//             q.push(p[cur]);
//         }
//         else
//         {
//             result = max(result, w_c[p[cur]] + w_c[cur] + graph[cur][0].second);
//             w_c[p[cur]] = max(w_c[p[cur]], w_c[cur] + graph[cur][0].second);
//         }
//     }
// }

// void solution(int root, int cur)
// {

//     for (pair<int, int> nx : graph[cur])
//     {

//         w_c[nx.first] = w_c[cur] + nx.second;
//         // cout << w_c[nx.first] << " " << w_c[cur] << "\n";
//         solution(root, nx.first);
//     }
// }

// // void solution(int cur)
// // {
// //     cout << cur <<"\n";
// //     for(int nx : child[cur])
// //     {
// //         solution(nx);
// //         // 거리
// //     }

// // }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> n;

//     for (int i = 0; i < n - 1; i++)
//     {
//         int r, b, w;
//         cin >> r >> b >> w;
//         child[r].push_back(b);
//         graph[b].push_back({r, w});
//         // graph.push_back({w,{r,b}});
//         p[b] = r;
//     }
//     //
//     // sort(graph.begin(), graph.end());

//     // for (int i = 1; i <= n; i++)
//     // {

//     //     solution(i,i);
//     //     for (int j = 1; j <= n; j++)
//     //     {
//     //         cout << w_c[j] << " ";
//     //     }
//     //     cout << "\n";

//     //     for(int j= 1; j<=n ; j++)
//     //     {
//     //         w_c[j] = 0;
//     //     }
//     // }
//     bfs();

//     // solution(1,1);

//     // for(int i = 1; i<=n; i++)
//     // {
//     //     cout << w_c[i] <<" ";
//     // }
//     // cout <<"\n";
//     // cout <<"\n";
//     // for (int i = 1; i <= n; i++)
//     // {
//     //     cout << w_c[i] << " ";
//     // }
//     // cout << "\n";
//     cout << result << "\n";
//     // cout << result <<"\n";
//     //  임의 시작점에서 왼쪽과 오른쪽 끝 을 고르고 최대가 되는 것을 고름
// }

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
vector<pair<int, int>> child[10004];
vector<pair<int, int>> graph[10004];
pair<int, int> long_idx;
int result = 0 ;
int p[10004];
int visited[10004];

void solution(int cur, int count)
{
    cout << cur << " " << count << "\n";
    if (long_idx.second < count)
    {
        long_idx.second = count;
        long_idx.first = cur;
    }
    if (child[cur].empty())
    {
        return;
    }
    for (pair<int, int> p : child[cur])
    {
        solution(p.first, count + p.second);
    }
}

void back()
{
    queue<pair<int, int>> q;
    q.push({long_idx.first,0});
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        if(result < p.second)
            result = p.second;
        for(pair<int,int> nx : graph[p.first])
        {
            if(visited[nx.first]==1)
                continue;
            visited[nx.first] = 1;
            q.push({nx.first, p.second + nx.second});
        }
        for(pair<int,int> nx : child[p.first])
        {
            if(visited[nx.first] == 1)
                continue;
            visited[nx.first] = 1;
            q.push({nx.first, p.second + nx.second});
        }
    
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        child[a].push_back({b, w});
        graph[b].push_back({a, w});
        p[b] = a;
    }

    solution(1, 0);

    cout << long_idx.first << " " << long_idx.second << "\n";

    visited[long_idx.first] = 1;


    back();

    cout << result <<"\n";
}
