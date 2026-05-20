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

#define INF 1e15 // 경우에 따라 다르게
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

    //     for(int i : v)
    // {
    //     cout << i <<" ";
    // }
    // cout <<"\n";
    long long result = INF;

    pair<long long,pair<long long,long long>> p = {0,{0,0}};
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long target = (v[i] + v[j]);

            int pos = lower_bound(v.begin() + j + 1, v.end(), -target) - v.begin();

            //cout << i << " "<< j <<" "<<pos <<"\n";
            for (int k = pos - 1; k <= pos; k++)
            {
                if (k < 0 || k >= n)
                    continue;
                if ( k== i || k== j)
                    continue;
                if(abs(target+v[k]) < abs(result))
                {
                    result = (target+v[k]);
                    p.first = v[i];
                    p.second.first = v[j];
                    p.second.second = v[k];
                }   
            }
        }
    }
    
    vector<long long> ans(3,0);
    ans[0] = p.first;
    ans[1] = p.second.first;
    ans[2] = p.second.second;

    sort(ans.begin(),ans.end());

    for(long long i : ans)
    {
        cout << i <<" ";
    }
    cout <<"\n";

}
