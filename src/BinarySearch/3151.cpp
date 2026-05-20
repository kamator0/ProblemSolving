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
vector<int> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    long long result = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int target = -(v[i] + v[j]);
            int lo = lower_bound(v.begin()+j+1, v.end(), target) - v.begin();
            int hi = upper_bound(v.begin()+j+1, v.end(), target) - v.begin();

 

            cout << lo << " " << hi << "\n";
            result += (hi - lo);
        }
    }

    cout << result << "\n";
}
