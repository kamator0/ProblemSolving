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
// long long 일 1e15 

using namespace std;

int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    vector<long long> narr(n, 0);

    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        narr[i] = a;
    }

    sort(narr.begin(), narr.end());

    cin >> m;
    vector<pair<long long, int>> marr(m, {0, 0});
    //vector<int> cnt(m, 0);
    vector<long long> ncnt (2e7+1,0); // + e7 

    // -1e7 0 1e7 

    for (int i = 0; i < m; i++)
    {
        long long a;
        cin >> a;
        marr[i].first = a;
        marr[i].second = i;
    }
    
    vector<pair<long long,int>> carr;
    carr = marr;


    sort(marr.begin(),marr.end());

    for (int i = 0; i < n; i++)
    {
        int st = 0;
        int ed = m - 1;
        long long k = narr[i];
        int mid = (st + ed) / 2;

        // bool flag = false;
        while (st <= ed)
        {
            //cout << st <<" "<< ed << " " << k << "\n";
            if ( k < marr[mid].first ) // 크다는 것임으로 ed 를 줄여서 고정된 수를 왼쪽으로 두는게 안 헷갈릴듯?
            {
                ed = mid - 1;
                mid = (st + ed) / 2;
            }
            else if ( k > marr[mid].first)
            {
                st = mid + 1;
                mid = (st + ed) / 2;
            }
            else
            {
                // flag = true;
                //cnt[marr[mid].second]++;
                //cout << marr[mid].second <<" " << marr[mid].second + 1e7 <<"\n";
                ncnt[marr[mid].first + 1e7]++;
                break;
            }
        }
    }

    // for(auto x : carr)
    // {
        
    //     cout << x.first <<" " << ncnt[x.first + 1e7] <<"\n";
    // }

    for(auto x : carr)
    {
        
        cout  << ncnt[x.first + 1e7] <<" ";
    }
    cout << "\n";
    // 최대 많아야 500000
}
