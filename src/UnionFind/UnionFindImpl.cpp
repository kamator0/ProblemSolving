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

using namespace std;

vector<int> whoparent(100001,-1);

int find(int x)
{
    if(whoparent[x]<0)
    {
        return x;
    }
    return find(whoparent[x]);
}

int OptmUni(int x)
{
    if(whoparent[x] < 0)
    {
        return x;

    }
    return whoparent[x] = find(whoparent[x]);
}

// 최적화 x 일자형 tree인 경우 find가 O(N)이 된다는 것 
bool uni(int u,int v)
{
    int p1 = find(u) ;
    int p2 = find(v);
    if(p1 != p2)
    {
        whoparent[p2]=p1; 
        return true;
    }
    else{
        return false;
    }
}


bool OptmUni(int u,int v)
{
    int p1 = find(u);
    int p2 = find(v);

    if(p1 == p2)
        return false;
    if(whoparent[p1] < whoparent[p2]) // root의 rank가 어느정도?
    {
        whoparent[p2] = p1;
    }
    else if(whoparent[p1] == whoparent[p2])
    {
        whoparent[p2] = p1;
        whoparent[p1]--;
    }
    else{
        whoparent[p1] = p2 ;
    }
    return true;

}






int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    
}
