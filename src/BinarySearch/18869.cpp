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

int m, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;

    // n^2 * m 은 시간초과

    // 뭔가 mid 의 Index 값이 같다면 이것은 동일한 배열을 가지고 있지 않을까? 틀림 
    // 1 5 4 2 3 / 3 2 4 5 1

    vector<vector<pair<int, int>>> s(m, vector<pair<int, int>>(n, {0, 0}));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int t;
            cin >>  t; 
            s[i][j].first = t ;
            s[i][j].second = j;
        }
    }

    for(int i = 0 ; i<m; i++)
    {
        sort(s[i].begin(),s[i].end());
    }
    
    for(int i = 0 ; i< m; i++)
    {
        int st = 1 ;
        int en = 
    }



}
