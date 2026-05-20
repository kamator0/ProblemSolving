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
// long long 일 1e18

using namespace std;

int t ;
int n,k ; 
vector<int> ans;
int cnt[200001];
int suffix_max[200001];
void solution(int n , int k , vector<int> x, vector<int> y)
{
    sort(x.begin(),x.end());
    int st = x[0];
    int en = x[x.size()-1];

    if(en-st<= 2 * k )
    {
        ans.push_back(x.size());
        return;
    }
    
    for(int i = 0; i<x.size(); i++)
    {
        cnt[i] = (upper_bound(x.begin(),x.end(), x[i]+k)- x.begin() )- i;
    }

    suffix_max [n-1] = cnt[n-1];
    for(int i = n-2;  i>=0; i--)
    {
        suffix_max[i] = max(cnt[i],suffix_max[i+1]); // i에 대해서 i 이후 최댓값 
    }

    int result = 0;
    for(int i = 0 ; i<n; i++)
    {
        int j = upper_bound(x.begin(),x.end(),x[i]+k)-x.begin();
        result = max(result, cnt[i]+suffix_max[j]);
    }

    // cnt[i] 

    ans.push_back(result);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t ;
    while(t> 0)
    {
        cin >> n >> k; 
        vector<int> x ;
        vector<int> y ;
        for(int i = 0 ;  i < n; i++)
        {
            int a;
            cin >> a; 
            x.push_back(a);
        }
        for(int i = 0 ;  i < n; i++)
        {
            int a;
            cin >> a; 
            y.push_back(a);
        }

        fill(cnt,cnt+n+1,0);
        fill(suffix_max,suffix_max+n+1,0);
        solution(n,k,x,y);


        t--;
    }


    for(auto x : ans)
    {
        cout << x <<"\n";
    }
    
}

