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
vector<long long> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n ;
    for(int i = 0; i<n ;i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    long long result = 1e15;
    for(int i = 0 ; i< n; i++)
    {
        
        int pos = lower_bound(v.begin(),v.end(),-v[i]) - v.begin();
        for(int j = pos-1; j<=pos; j++)
        {
            if(i==j || j<0 || j>=n )
                continue;
            if(abs(result) > abs(v[i]+v[j]))
            {
                result = (v[i]+v[j]);
            }
          
        }
    }

    cout << result <<"\n";


}

