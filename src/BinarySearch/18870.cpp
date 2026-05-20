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

int n;
int cnt[1000001];
vector<int> arr;
int lower_idx(int target, int len)
{
    int st = 0;
    int en = len;
    while (st < en)
    {
        int mid = (st + en) / 2;
        if (arr[mid] >= target)
            en = mid;
        else
            st = mid + 1;
    }

    return st;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    // ector<pair<int,int>> arr(n,{0,0});

    for (int i = 0; i < n; i++)
    {

        cin >> cnt[i];
        arr.push_back(cnt[i]);
        // arr[i].first = a;
        // arr[i].second = i;
    }

    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()),arr.end());

    for (int i = 0; i < n; i++)
    {
        cout << lower_idx(cnt[i],arr.size())  <<' ';
        //cout << lower_bound(arr.begin(), arr.end(), cnt[i]) - arr.begin() << ' ';
    }

    cout << "\n";
}
