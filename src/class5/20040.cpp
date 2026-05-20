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
int n, m;
int p[500001];
vector<pair<int, int>> v;

int find(int x)
{
    if (p[x] < 0)
    {
        return x;
    }
    return p[x] = find(p[x]);
}

bool uni(int v, int u)
{

    v = find(v);
    u = find(u);
    if (v == u)
    {
        return false;
    }

    if (p[u] < p[v])
    {
        p[v] = u;
    }
    else if (p[u] == p[v])
    {
        p[u]--;
        p[v] = u;
    }
    else
    {
        p[u] = v;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    fill(p,p+n+1,-1);

    int cnt = 1;
    int cnow = 0;
    bool flag =false;
    for(auto l : v)
    {
        int x1 = l.first;
        int x2 = l.second;

        if(!uni(x1,x2))
        {
            cnow = cnt ;
            flag = true;
            break;
        }

        cnt ++; 
    }

    if(flag)
    {
        cout << cnow << "\n";
    }
    else
        cout << 0 <<"\n";

}
