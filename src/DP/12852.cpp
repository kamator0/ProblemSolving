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
int cnt[1000001];
int nx[1000001];
vector<int> dst[1000001];

void dfs(int cur)
{
    cout << cur <<" ";
    if(cur == 1)
    {
        return;
    }
    dfs(nx[cur]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    // cnt[1] = 0;
    // cnt[2] = 1;
    // cnt[3] = 1;

    cnt[1] = 0;
    cnt[2] = 1;
    cnt[3] = 1;
    nx[2] = 1;
    nx[3] = 1; 

    // vector를 한번에 복사?
    // n (어떤 수에 대해 까지 한번에 복사 )
    for (int i = 4; i <= n; i++)
    {
        int idx = i;
        //dst[i].push_back(i);

        if (idx % 3 == 0)
        {
            if ( idx % 2 == 0 )
            {
                int a = idx / 3 ;
                int b = idx/2 ;
                if(cnt[a] < cnt[b])
                {
                    idx /= 3;
                }
                else{
                    idx /= 2;
                }
            }
            else {
                int a = idx - 1;
                int b= idx /3 ;
                if(cnt[a] < cnt[b])
                {
                    idx -= 1;
                }
                else{
                    idx /= 3;
                }
            }
        }
        else if (idx % 3 == 1)
        {

            // idx % 2 = 0 ?
            // dst[i].push_back(idx);
            if (idx % 2 == 0)
            {
                int a = idx / 2;
                int b = idx - 1;
                // cout << dst[a].size() <<  " " << dst[b].size() <<"\n";
                if (cnt[a] < cnt[b])
                {
                    idx /= 2;
                }
                else
                {
                    idx -= 1;
                }
            }
            else
            {
                idx -= 1;
            }
        }
        else if (idx % 3 == 2)
        {
            if (idx % 2 == 0)
            {
                int a = idx / 2;
                int b = idx - 1;
                if (cnt[a] < cnt[b])
                {
                    idx /= 2;
                }
                else
                {
                    idx -= 1;
                }
                // idx /= 2;
                // dst[i].push_back(idx);
            }
            else
            {
                idx -= 1;
                // dst[i].push_back(idx);
            }
        }

        cnt[i] = cnt[idx] + 1;
        nx[i] = idx ;
        // 저장 말고 차리 이전 idx 를 저장하고 좋을듯? cnt를 따로 관리?
        // for (int k = 0; k < dst[idx].size(); k++)
        // {
        //     dst[i].push_back(dst[idx][k]);
        // }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     if (i == 1)
    //     {
    //         cout << 0 << "\n";
    //         continue;
    //     }
    //     for (int a : dst[i])
    //     {
    //         cout << a << " ";
    //     }
    //     cout << "\n";
    // }
    if (n == 1)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << cnt[n] << "\n";
    }
    dfs(n);
    // for (int a : dst[n])
    // {
    //     cout << a << " ";
    // }
}
