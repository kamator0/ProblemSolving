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

string s1, s2;

bool find(string&a , string &b)
{
    bool flag = false; 

    for(int i = 0 ; i<a.size(); i++)
    {
        for(int j =0 ; j<b.size(); j++)
        {
            if(i+j >= a.size())
                break;
            if(b[j] != a[i+j])
            {
                flag = false;
                break;
            }
            flag = true;
        }

        if(flag)
            return true;
    }
    
    if(flag)
        return true;
    else
        return false;

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s1 >> s2 ;

    if(s1.size() > s2.size())
    {
        cout << find(s1,s2) <<"\n";
    }else{
        cout << find(s2,s1) <<"\n";
    }

    
}

