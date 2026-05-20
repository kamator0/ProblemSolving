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
vector<int> v;
vector<int> c;

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

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int cc;
        cin >> cc;
        c.push_back(cc);
    }

    sort(v.begin(), v.end());
    vector<int> result;

    for (int i = 0; i < m; i++)
    {
        int target = c[i];
        int st = 0;
        int en = v.size()-1;
        bool flag = false;
        int mid = (st + en) / 2;
        while (st <= en)
        {
            //cout << mid << " " << target << " " << v[mid] << "\n";
            if (target > v[mid])
            {
                st = mid + 1;
                mid = (st + en) / 2;
            }
            else if (target < v[mid])
            {
                en = mid - 1;
                mid = (st + en) / 2;
            }
            else
            {
                result.push_back(1);
                flag = true;
                break;
            }
        }

        if (!flag)
            result.push_back(0);
    }

    for (int a : result)
    {
        cout << a << " ";
    }
    cout << "\n";
}
