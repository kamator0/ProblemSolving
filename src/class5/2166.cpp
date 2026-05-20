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
#include <sstream>
#include <iomanip>

#define INF 0x3f3f3f3f // 경우에 따라 다르게
// long long 일

using namespace std;

int n;
vector<pair<int, int>> pos;

double result = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pos.push_back({x, y});
    }

    // for(auto x : pos)
    // {
    //     cout << x.first <<" " <<x.second<<"\n";
    // }

    // vector의 외적 x1 , y1 에 대해서 전부 비교
    // 1 2 3  // 1 3 4 // 1 4 5 ... 1 n-1 n

    pair<int, int> p1 = pos[0];

    // 볼록 다각형일때만 성립
    // for(int i = 1; i<n-1; i++)
    // {
    //     pair<int,int> p2 = pos[i];
    //     pair<int,int> p3 = pos[i+1];

    //     result +=  (double)abs ( (long long)(p2.first - p1.first) * (p3.second-p1.second)
    //     - (long long)(p3.first-p1.first) * (p2.second-p1.second))/2.0;
    //     //cout << result <<"\n";
    // }

    // cout << fixed << setprecision(1) << result << "\n";

    // 오목 다격형일때와 볼록 다각형 둘다 성립하려면

    // 신발끈 공식 
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        result += (long long)pos[i].first * pos[j].second;
        result -= (long long)pos[j].first * pos[i].second;
    }
    cout << fixed << setprecision(1) << abs(result) / 2.0 << "\n";
}
