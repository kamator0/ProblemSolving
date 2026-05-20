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

int m, n; // 조카 과자
vector<long long> v;

int Q(int x)
{
    int idx = 0;
    for (int a : v)
    {
        idx += a / x;
    }
    return idx >= m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    // 10억이면 괜찮은거 같기도하고?

    long long st = 1;
    long long en = *max_element(v.begin(), v.end());

    long long s = 0;

    while (st <= en)
    {
        long long mid = (st + en) / 2; // st를 0이라 두면 0+0/2 를 해버려서 컴파일 에러가 됨 

        if (Q(mid))
        {
            st = mid + 1;
            s = max(s,mid);
        }
        else
        {
            en = mid - 1;
        }
    }

    
    cout << s <<"\n";

}
