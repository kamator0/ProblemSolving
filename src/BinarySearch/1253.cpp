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

    vector<int> check(n,0);

    long long result = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int target = (v[i] + v[j]);
            int lo = lower_bound(v.begin() , v.end(), target) - v.begin();
            int hi = upper_bound(v.begin() , v.end(), target) - v.begin();

           //   최악이면 n ^ 3 인가? 
            // lo 가 n보다 클 때 hi 가 n보다 클때 
            if(lo < n )
            {
                if(check[lo] == 1)
                    continue;
            }
            
            for(int k = lo-1 ; k<= hi ; k++)
            {
                if(k>=n || k <0 )
                    continue;
                if(k==j || k== i)
                    continue;
                if(check[k] == 1)
                    continue;
                if(target == v[k])
                    check[k] = 1;
            }

 
            // lo 
            //cout << lo <<" " << hi <<"\n";
        }
    }

    for(int x : check)
    {
        result += x ;
    }

    cout << result <<"\n";
}
