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

int rc[10004];
int lc[10004];
vector<int> child[10004];
int p[10004];
int subcount[10004];
int depth[10004];
// 생각해보니 굳이 board로 수많은 0을 채울 필요는 없네?
int col[10004]; // 가로
int row[10004]; // 세로

int max_lvl = 1;

pair<int, int> result = {-1, -1}; // lvl width



void inintialize()
{
    for(int i = 1 ; i <=n ; i++)
    {
        p[i] = -1;
    }
}


int find(int x)
{
    if(p[x] <0 )
        return x ;
    return p[x]= find(p[x]);
}



bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first)
    {
        return p1.second < p2.second;
    }
    else
    {
        return p1.first > p2.first;
    }
}

void solution(int cur, int l_min, int r_max)
{

    int r, l, d; // r l d
    int r_c, l_c;
    r = rc[cur];
    l = lc[cur];
    d = depth[cur];
    l_c = subcount[l] + l_min;

    if (lc[cur] != -1)
        solution(lc[cur], l_min, l_c);
    row[cur] = d;
    col[cur] = l_c;
    if (rc[cur] != -1)
        solution(rc[cur], l_c + 1, r_max);

 
}

void cnt_subTree(int cur)
{

    subcount[cur] = 1;
    for (int nx : child[cur])
    {
        cnt_subTree(nx);
        subcount[cur] += subcount[nx];
    }
}
void Depth(int cur, int lvl)
{
    for (int nx : child[cur])
    {
        if (child[nx].size() == 0)
        {
            // cout << nx << " " << lvl+1<<"\n";
            depth[nx] = lvl + 1;
            max_lvl = max(lvl + 1, max_lvl);
            continue;
        }
        depth[nx] = lvl + 1;
        Depth(nx, lvl + 1);
    }
}
void width(vector<int> arr[])
{
    // 처음 0이 아닌 숫자가 나타날 때
    for (int i = 1; i <= max_lvl; i++)
    {
      

        if (arr[i].empty())
            continue;
      
        int mincol = arr[i].front();
        int maxcol = arr[i].back();
        int width = maxcol - mincol +1;

        if (result.second < width)
        {
            result.first = i;
            result.second = width;
        }
        else if (result.second == width)
        {
            result.first = result.first > i ? i : result.first;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    inintialize();
    for (int i = 0; i < n; i++)
    {
        int r, a, b;
        cin >> r >> a >> b;
        lc[r] = a;
        rc[r] = b;
        if (a != -1)
        {
            p[a] = r;
            child[r].push_back(a);
        }
        if (b != -1)
        {
            p[b] = r;
            child[r].push_back(b);
        }
    }


    // root node 먼저 찾기 해야함?
    int root = find(1) ; 

    //cout << root <<"\n";

    cnt_subTree(root);

    // for(int i = 1 ; i <=n; i++ )
    // {
    //     cout << i <<" " <<subcount[i] << "\n";
    // }
    depth[root] = 1;
    Depth(root, 1);
    // cout << max_lvl <<"\n";
    // for(int i = 1; i <=n; i++)
    // {
    //     cout << i <<" " <<depth[i] <<"\n";
    // }

    // node
    // cout << "1234" << "\n";
    solution(root, 1, n);

    vector<int> ans[max_lvl + 1];

    for (int i = 1; i <= n; i++)
    {
        // cout << row[i] <<" " <<col[i] <<"\n";
        ans[row[i]].push_back(col[i]);
    }

    for (int i = 1; i <= max_lvl; i++)
    {
        sort(ans[i].begin(), ans[i].end());
    }

    // for (int i = 1; i <= max_lvl; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << board[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // width();
    width(ans);

    cout << result.first << " " << result.second << "\n";

    // sort(ans.begin(),ans.end(),cmp);

    // cout << ans[0].second<<" " <<ans[0].first <<"\n";
}
