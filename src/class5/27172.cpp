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
vector<pair<int,int>> v;

bool cmp(pair<int,int> p1 , pair<int,int> p2)
{
    return p1.second < p2.second ;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n ;
    for(int i= 0 ; i< n; i++)
    {
        int a;
        cin >> a;
        v.push_back({a,i});
        
    }
    
    sort(v.begin(),v.end());
    
    vector<int> isnum(v[n-1].first+1,0); // 결과값 저장

    for(int i = 0 ; i<n; i++)
    {
        int x = v[i].first;
        isnum[x] = 1;
    }


    vector<int> cnt(v[n-1].first+1,0);
    


    for(int i =0; i < n; i++)
    {


        for(int j= 2 ; j*v[i].first <= v[n-1].first ; j++)
        {
           
            //cnt[v[i].first]++;
            if(isnum[j*v[i].first] == 1)
                cnt[v[i].first]++;
            cnt[j*v[i].first]--;
         
        }
    }

    
    // 0부터 
    sort(v.begin(),v.end(),cmp);

    for(int i=0; i<n; i++)
    {
       //cout << v[i].second <<" "<<cnt[v[i].first] <<"\n";
       cout << cnt[v[i].first] <<" ";
    }
    cout <<"\n";


}

