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

int n, c;
vector<int> v;

bool canPlace(int dist){
    int cnt = 1 ;
    int last = v[0];

    for(int i = 1 ; i<n; i++)
    {
        if(v[i]-last >= dist)
        {
            cnt ++;
            last = v[i];
        }
    }

    return cnt>=c;

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> c;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    // n이 20만 n^2 도 무조건 시간초과

    // 1 3 7 8

    // 1번에서 뺏을 경우?

    // 예를들어서 1->max 값에 대해서 c가 있다고 하면 최대 값은 max-1 / c-1 ?

    // int result = *max_element(v.begin(),v.end())-1 / c- 1 ;
    int result = 0;

    // target 길이 부터 

    // 
    int st = 1;
    int  en =  v[n-1]-v[0];

    while (st<=en)
    {
        int mid = (st+en)/2;
        if(canPlace(mid))
        {
            result = max(mid,result);
            st = mid +1 ;
        }
        else{
            en = mid - 1 ;
        }
    }
    
    cout <<result <<"\n";


   

}
