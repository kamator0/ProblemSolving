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

long long r, g, b ;
vector<long long> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> g >> b ;
    v.push_back(r);
    v.push_back(g);
    v.push_back(b);

    sort(v.begin(),v.end());

    if(v[2] >= 2*(v[1]+v[0]))
    {
        cout << v[1] + v[0] <<"\n";
    }
    else{
        cout << (v[2] +v[1]+v[0])/3 <<"\n";
    }

}

