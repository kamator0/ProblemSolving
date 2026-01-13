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

#define INF 12345678

using namespace std;

int n;
vector<pair<int,int>> vx;
vector<pair<int,int>> vy;
vector<pair<int,int>> vz;
vector<pair<int,pair<int,int>>> xw;
vector<pair<int,pair<int,int>>> yw;
vector<pair<int,pair<int,int>>> zw;

//int visited[100005];
int p[100005];
long result = 0;

void initialize()
{
    for(int i = 1 ; i <= n; i++)
    {
        p[i] = - 1;
    }
}

int find(int x)
{
    if(p[x] < 0)
        return x; 
    return p[x] = find(p[x]);
}
bool uni(int u, int v)
{
    u = find(u);
    v= find(v);
    if(u == v)
        return false;
    if (p[u] < p[v])
        p[v] = u;
    else if(p[u] == p[v])
    {
        p[v] = u;
        p[u] --;
    } 
    else
        p[u] = v;
    return true;

}

void solution(){
    // x축에서 n-1 개 
    // y축에서 n-1 개
    // z축에서 n-1 개 
    // 정렬 후에 a1 a4 a2 a3 a5 하고 a1 - a4 a4 - a2 a2- a3 a3- a5

    for(int i = 0; i<n-1;i++)
    {
        xw.push_back({abs(vx[i].first-vx[i+1].first),{vx[i].second,vx[i+1].second}}); // 몇 번째 인지
        yw.push_back({abs(vy[i].first-vy[i+1].first),{vy[i].second,vy[i+1].second}});
        zw.push_back({abs(vz[i].first-vz[i+1].first),{vz[i].second,vz[i+1].second}});
    }
    sort(xw.begin(),xw.end());
    sort(yw.begin(),yw.end());
    sort(zw.begin(),zw.end());
    // 3(n-1) 하고 
    // 

    vector<pair<int,pair<int,int>>> all;

    for(int i= 0; i< xw.size(); i++)
    {
        all.push_back({xw[i].first,{xw[i].second.first,xw[i].second.second }});
    }
    for(int i= 0; i< yw.size(); i++)
    {
        all.push_back({yw[i].first,{yw[i].second.first,yw[i].second.second }});
    }
      for(int i= 0; i< zw.size(); i++)
    {
        all.push_back({zw[i].first,{zw[i].second.first,zw[i].second.second }});
    }

    sort(all.begin(),all.end());

    int edge_count = 0 ;
    
    for(int i = 0 ; i < all.size(); i++)
    {
        int w = all[i].first;
        int a = all[i].second.first;
        int b =all[i].second.second;
        //cout << w <<" "<< a << " "<< b <<"\n";
   
        if (edge_count == n-1)
            break;
        if(!uni(a,b))
            continue;
       
        result += w;
        edge_count ++;
    }



}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n ;

    initialize();
    for(int i= 0; i<n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z ;
        vx.push_back({x,i+1});
        vy.push_back({y,i+1});
        vz.push_back({z,i+1});
    }


    sort(vx.begin(),vx.end());
    sort(vy.begin(), vy.end());
    sort(vz.begin(), vz.end());

    //cout <<"!23"<<"\n";
    solution();

    cout << result <<"\n";
}
