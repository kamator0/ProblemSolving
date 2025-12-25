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


int n,m;

int p[1000001];

void initialize()
{
    for(int i = 0 ; i < 1000001; i++)
        p[i] = -1;
}

int find(int x)
{
    if(p[x] < 0)
        return x;
    return p[x] = find(p[x]);
}

bool uni(int u,int v)
{
    u = find(u);
    v = find(v);
    if (u==v)
    {
        return false;
    }
    if(p[u] < p [v])
    {
        p[v] = u;
    }
    else if(p[u]==p[v])
    {
        p[v] = u;
        p[u] --;
    }
    else{
        p[u]= v;
    }
    return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    initialize();
    cin >> n >> m ;

    bool flag = false;
    vector<string> result;
    for(int i = 0 ; i< m; i++)
    {
        int com,a,b;
        cin >> com >> a >> b ;
        if(com == 1)
        {
            if(find(a) == find(b))
                result.push_back("yes");
            else
                result.push_back("no");
        }
        else{
            uni(a,b);
        }
    }

    for(string s : result)
        cout << s <<"\n";

}
