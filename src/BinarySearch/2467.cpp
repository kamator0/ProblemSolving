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
int idx = 0;
vector<pair<long long, pair<int, int>>> result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        v.push_back(a);
    }

    long long best = 1e15;
    int ansL, ansR;
    for (int i = 0; i < n; i++)
    {
        int pos = lower_bound(v.begin(), v.end(), -v[i]) - v.begin();

        for (int j = pos - 1; j <= pos; j++)
        {
            if (j < 0 || j >= n || j == i)
                continue;
            long long sum = v[i] + v[j];
            if (abs(sum) < abs(best))
            {
                best = sum;
                ansL = min(i, j);
                ansR = max(i, j);
            }
        }
    }

    // {
    //     cout << x.first <<" "<<x.second.first <<" "<<x.second.second<<"\n";
    // }

    cout << v[ansL] << " " << v[ansR] << "\n";
}
