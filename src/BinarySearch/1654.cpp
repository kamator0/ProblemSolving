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

int k, n ; 
vector<int> v ;
long long result = 0;

bool Q(long long x)
{
    int q = 0;
    for(int a : v)
    {
        q += a/x;
    }

    if(q >= n )
    {
        return true;
    }
    else{
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> n ;

    for(int i = 0 ; i< k; i++)
    {
        int a ;
        cin >> a;
        v.push_back(a);
    }

    // 
    sort ( v.begin(),v.end());

    // 어떤 수를 나눴을 때의 몫의 합이 11이 나와야하는데 그 중 나머지 값이 가장 적은 것? 


    // long long s = 0 ;
    // for(int a : v)
    // {
    //     s+=a;
    // }

    
    long long st= 1;
    long long en=  *max_element(v.begin(), v.end()); //ㅅ;

    while(st<= en)
    {
        long long mid= (st+en)/2;
        if(Q(mid))
        {
            result = max(result,mid);
            st = mid + 1;
        }
        else{
            en = mid - 1; 
        }

        // if (s/mid == n)
        // {
        //     result = max(result,mid);
        //     st = mid + 1 ;
        // }
        // else{
        //     en = mid -  1;
        // }
    }
    
    cout << result <<"\n";





}

