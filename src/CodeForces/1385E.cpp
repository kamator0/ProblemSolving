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
// long long 일 1e18

using namespace std;

int t;
int n, m;
// vector<int> edge[200001];
// vector<tuple<int, int, int>> dedge;
vector<int> edge[200001];
// vector<int> unedge[200001];
vector<pair<int, int>> undedge;
int cnt[200001];
int pos[200001];

void sol()
{

    queue<int> q;
    int pn = 1;
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == 0)
        {
            q.push(i);
        }
    }

    // 그래프
    vector<pair<int, int>> result;
    int ncnt = 0; // 사이클인가? 과연

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        ncnt++;
        pos[cur] = pn;
        pn++;

        for (auto nxt : edge[cur])
        {
            cnt[nxt]--;
            if (cnt[nxt] == 0)
            {
                q.push(nxt);
                // result.push_back({cur, nxt});
            }
        }
    }

    // cycle 생기는지 확인
    // n * n 번 탐색?

    if (ncnt < n)
    {
        // 방향 그래프끼리 cycle NO

        for (int i = 1; i <= n; i++)
            edge[i].clear();
        undedge.clear();
        cout << "NO" << "\n";
        return;
    }

    // 무방향 연결시켜서

    // 무방향에대해서 무조건 두개의 node가 연결된다면 먼저 처리한 순서 에서
    // 나중 처리한 순서로 연결하면 사이틀 발생 안함

    for (auto E : undedge)
    {
        int x = E.first;
        int y = E.second;
        if (pos[x] < pos[y])
        {
            result.push_back({x, y});
        }
        else
        {
            result.push_back({y, x});
        }
    }

    cout << "YES" << "\n";
    for (auto ans : result)
    {
        cout << ans.first << " " << ans.second << "\n";
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto x : edge[i])
        {
            cout << i << " " << x << "\n";
        }
    }

    for (int i = 1; i <= n; i++)
        edge[i].clear();
    undedge.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t > 0)
    {
        cin >> n >> m;
        fill(cnt, cnt + n + 1, 0);
        fill(pos, pos + n + 1, 0);
        for (int i = 0; i < m; i++)
        {
            int a, x, y;
            cin >> a >> x >> y;
            if (a == 0)
            {
                // unedge[x].push_back(y);
                // unedge[y].push_back(x);
                undedge.push_back({x, y});
            }
            else
            {
                edge[x].push_back(y);
                cnt[y]++;
                // edge.push_back({1, x, y});
            }
        }

        // 만약 direct edge가 없을 때
        sol();

        t--;
    }
}
