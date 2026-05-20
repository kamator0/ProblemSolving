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

int a, b;
vector<int> va;
vector<int> vb;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;

    for (int i = 0; i < a; i++)
    {
        int x;
        cin >> x;
        va.push_back(x);
    }

    for (int i = 0; i < b; i++)
    {
        int x;
        cin >> x;
        vb.push_back(x);
    }

    sort(vb.begin(),vb.end());
    
    vector<int> result;

    for(int i = 0 ; i< a ; i++)
    {
        int st = 0 ;
        int en = vb.size()-1;
        int mid = (st+en)/2;
        int target = va[i];
        bool flag =false;
        while (st<=en)
        {
            if(target > vb[mid])
            {
                st = mid + 1; 
                mid = (st+en)/2;
            }
            else if(target < vb[mid])
            {
                en = mid - 1; 
                mid = (st+en)/2;
            }
            else{
                flag = true;
                break;
            }

        }
        if(!flag)
        {
            result.push_back(target);
        }
        
    }
    
    sort(result.begin(),result.end());
    cout << result.size()<<"\n";
    for(int x : result)
    {   
        cout << x <<" ";
    }
    cout <<"\n";


}
