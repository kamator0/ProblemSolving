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
vector<int> ss;
vector<pair<int, int>> sm;

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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ss.push_back(v[i] + v[j]);
        }
    }

    sort(ss.begin(), ss.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i] - v[j] <= 1)
                continue;
            sm.push_back({v[i] - v[j], i}); // 자연수 더한 조합이니깐 최소 ? 2 이상
        }
    }

    sort(sm.begin(), sm.end());

    int result = -1;

    for (int i = 0; i < sm.size(); i++)
    {
        int st = 0;
        int en = ss.size();
        while (st <= en)
        {
            int mid = (st + en) / 2;

            if (ss[mid] < sm[i].first)
            {
                st = mid + 1;
            }
            else if (ss[mid] > sm[i].first)
            {
                en = mid - 1;
            }
            else
            {
                result = max(result, sm[i].second);
                break;
            }
        }
    }

    cout << v[result] << "\n";
    // 맨 뒤 부터 --

    // ss + k = l

    // ss

    // 1+1 1+2 1+3 ... n^2

    // 뒤에서 부터 하나씩

    // 가장 큰수 인데 어떠한 수를 더한 것에 대한 중간 값보다
}
