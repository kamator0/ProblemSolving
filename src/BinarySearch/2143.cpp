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

int t;
int n;
int m;
vector<int> va;
vector<int> vb;

vector<int> vsa;
vector<int> vsb;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        va.push_back(a);
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        vb.push_back(b);
    }

    // 1 2 3 4
    // 1 2 , 1 3  ,1 4 , 2 3 ,2 4, 3 4
    // 1 2 3, 1 2 4 ,1 3 4,  2 3 4,
    // 1 2 3 4

    // 5
    // 10
    // 10
    // 5
    // 1
    // n ^ 3 이면 시간 초과

    // 1 2 3 4  4
    // 1 2,2 3,3 4 3
    // 1 2 3, 2 3 4  2
    // 1 2 3 4  1
    for (int i = 1; i <= n; i++)
    {
        int idx = 0;
        // int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (j + i > n)
                break;
            for (int k = j; k < j + i; k++)
            {
                idx += va[k];
            }

            vsa.push_back(idx);

            idx = 0;
            // if(cnt >= i)
            // {
            //     vsa.push_back(idx);
            //     idx = 0 ;
            //     cnt = 0 ;
            // }
            // idx += va[j] ;
            // cnt ++ ;
            // cout << idx <<" "<<cnt <<"\n";
        }
        // vsa.push_back(idx);
    }

    for (int i = 1; i <= m; i++)
    {
        int idx = 0;
        // int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (j + i > m)
                break;
            for (int k = j; k < j + i; k++)
            {
                idx += vb[k];
            }

            vsb.push_back(idx);

            idx = 0;
        }
    }

    sort(vsa.begin(), vsa.end());
    
    // cout << vsa.size() << "\n";
    // for (int x : vsa)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";

    // cout << vsb.size() << "\n";
    // for (int x : vsb)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";

    

    long long result = 0;
    // n (n+1) /2 * n(n+1) 최대 10 ^ 12 촤과

    for (int i = 0; i < vsb.size(); i++)
    {
        // int st = 0;
        // int en = vsa.size() - 1;
        int target = t - vsb[i];

       // cout << target <<"\n";
        // 중복 

        int lo = lower_bound(vsa.begin(),vsa.end(),target)-vsa.begin();
        int hi = upper_bound(vsa.begin(),vsa.end(),target)-vsa.begin();

        
        result+=(hi-lo);

    }

    cout << result <<"\n";
}
