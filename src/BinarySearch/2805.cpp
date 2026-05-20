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

int n, m;
vector<long long> v;

bool solve(long long x)
{
    long long cnt = 0 ;
    for(long long a : v )
    {
        if(a > x)
        {
            cnt +=(a-x);
        }
    }

    return cnt >= m;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        long long h;
        cin >> h;
        v.push_back(h);
    }

    sort(v.begin(), v.end());

    long long st = 1;
    long long en = *max_element(v.begin(), v.end());
    long long result = 0;
    while (st <= en)
    {
        long long mid = (st + en) / 2;

        if (solve(mid))
        {
            st = mid + 1;
            result = max(result,mid);
        }
        else
        {
            en = mid - 1;
        }
    }

    cout << result <<"\n";
}
