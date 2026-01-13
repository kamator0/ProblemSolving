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

using namespace std;

int n, m;
vector<string> names;
int indegree[1004];
vector<int> graph[1004];
// 자식 수 기록 어떤 자식인지
vector<int> child[1004];
int p[1004];
int visited[1004];

int idx(string s)
{
    for (int i = 0; i < n; i++)
    {
        if (names[i] == s)
            return i;
    }
    return 0;
}
void initialize()
{
    for (int i = 0; i < n; i++)
    {
        p[i] = -1;
    }
}

int find(int x)
{
    // cout << x <<"\n";
    if (p[x] < 0)
    {
        return x;
    }
    return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (p[u] < p[v])
    {
        p[v] = u;
    }
    else if (p[u] == p[v])
    {
        p[v] = u;
        p[u]--;
    }
    else
    {
        p[u] = v;
    }
    return true;
}

void solution()
{
    queue<int> q;
    vector<int> zero_indegree;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] != 0)
            continue;
        q.push(i);
        zero_indegree.push_back(i);
    }
    while (!q.empty())
    {
        int cur = q.front();
        // cout << names[cur] << " " << indegree[cur] <<"\n";
        q.pop();

        for (int nx : graph[cur])
        {
            indegree[nx]--;
            if (indegree[nx] == 0)
            {
                q.push(nx);
            }
        }

        // 직접적으로 연결된 graph에 대해서 size (조상 수가 가장 많은 것)가 가장 큰 부모 것이 직접 부모이다 
        int directParent = -1;
        int maxAncestors = -1;
        for (int nx : graph[cur])
        {
            if ((int)graph[nx].size() > maxAncestors)
            {
                maxAncestors = graph[nx].size();
                directParent = nx;
            }
        }
        if (directParent != -1)
        {
            p[cur] = directParent;
            child[directParent].push_back(cur);
        }
    }

    // for(int i = 0 ; i<n; i++)
    //     cout << names[i] <<" " <<p[i] <<"\n";
    // cout <<"\n";

    vector<string> gamun;
    int gamun_count = 0;
    // indegree 0인것을 고르는 방법?
    for (int x : zero_indegree)
    {

        int parent = find(x);
        // cout << names[x] << " "  <<names[parent] <<"\n";
        if (visited[parent] == 1)
            continue;
        visited[parent] = 1;
        gamun_count++;
        gamun.push_back(names[parent]);
    }

    // for(int i = 0 ; i < n; i++)
    // {
    //     if(visited[i] == 1)
    //         continue;
    //     int king = find(i);
    //     cout <<  names[i] <<" "<< king <<"\n";
    //     if (king == -1)
    //         continue;
    //     gamun.push_back (names[king]);
    //     gamun_count++;
    // }

    sort(gamun.begin(), gamun.end());
    cout << gamun_count << "\n";
    for (int i = 0; i < gamun.size(); i++)
    {
        cout << gamun[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << names[i] << " ";
        cout << child[i].size() << " ";
        sort(child[i].begin(), child[i].end());
        for (int x : child[i])
        {
            cout << names[x] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        names.push_back(str);
    }
    sort(names.begin(), names.end());

    unordered_map<string, int> nameToIdx;

    for (int i = 0; i < n; i++)
    {
        nameToIdx[names[i]] = i;
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string x, y;
        int a, b;
        cin >> x >> y; // x의 조상중에 y가 있음
        a = nameToIdx[x];
        b = nameToIdx[y];
        graph[a].push_back(b);
        indegree[b]++;
    }

    initialize();

    solution();
}
