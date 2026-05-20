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
vector<vector<int>> v(4, vector<int>(4001, 0)); // A B C D

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int a;
            cin >> a;
            v[j][i] = a;
        }
    }

    // A + B , C + D 상관은 없을 듯?
    vector<int> v1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v1.push_back(v[0][i] + v[1][j]);
        }
    }

    vector<int> v2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v2.push_back(v[2][i] + v[3][j]);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    long long result = 0 ;
    for(int i =0; i< v1.size(); i++)
    {
        // int st = 0;
        // int en = v2.size()-1;
        // int mid = (st+en)/2;
        // int target = -v1[i];
        // while(st<=en)
        // {
        //     if(target > v2[mid])
        //     {
        //         st = mid + 1; 
        //         mid = (st+en)/2;
        //     }
        //     else if(target == v2[mid])
        //     {

        //     }

        // }
        // 다시 생각해보니 합이기 때문에 중복이 존재 가능하다.
        int target = -v1[i]; 
        int lo = lower_bound(v2.begin(),v2.end(),target) -v2.begin();
        int hi = upper_bound(v2.begin(),v2.end(),target) - v2.begin();

        result += (hi-lo);

    }

    cout << result <<"\n";


    // for(int i = 0 ; i< 4; i++)
    // {
    //     sort(v[i].begin(),v[i].end());
    // }

    //  for(int i =0; i< 4; i++)
    // {
    //     for(int j= 0; j<n ;j++)
    //     {
    //        cout << v[i][j] <<" ";
    //     }
    //     cout <<"\n";
    // }

    // 2 ^ 28 * 4 2^32 ?

    // for(int i = 0 ;  i < 4 ; i++)
    // {
    //     for(int j = 0 ; j< 4; j++)
    //     {
    //         for(int k = j+1 ; k<4 ; k++)
    //         {
    //             int
    //         }
    //     }
    // }
}
