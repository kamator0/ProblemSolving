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


int t;

int p[1000001];

void initialize(int n)
{
    for(int i = 0 ; i<n; i++)
    {
        p[i] = -1;
    }
}



int find(int x)
{
    if(p[x] <0)
        return x;
    return p[x] = find(p[x]);
}

bool uni(int u,int v)
{
    u = find(u);
    v = find(v);

    if(u==v)
        return false;
    if(p[u] < p[v])
        p[v] = u;
    else if(p[u] == p[v])
    {
        p[v] = u ;
        p[u]--;
    }
    else{
        p[u]= v;
    }
    return true;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t ;

    
    for(int i = 0 ; i < t ; i++)
    {
        int n;
        cin >> n;
        initialize(n); // 마음에 안들긴 함 
        int k ;
        cin >> k ;
        for(int j = 0; j<k; j++)
        {
            int a, b ;
            cin >> a >> b;
            // 연결 함수
            uni(a,b);
        } 

        vector<int> result;

        int m ; 
        cin>> m ;
        for(int j = 0; j< m; j++)
        {
            int u, v;
            cin >> u >> v ;
            
            // 같은 연결에 있는 함수 인가? 
            if(find(u)==find(v))
                result.push_back(1);
            else
                result.push_back(0);
        }

        cout << "Scenario " << i+1 <<":"<<"\n";
        for(int x : result)
            cout<< x << "\n";

        cout <<"\n";
        
    }
    
}
