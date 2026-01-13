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

int n;
vector<int> child[55];
int cut ; 
int root;
int result = 0;

void bfs()
{
    if(root == cut) // root 가 날라갈 경우
        return;

    queue<int> q;
    q.push(root);


    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int nx : child[cur])
        {
            if(nx== cut)
            {
                if(child[cur].size()==1)
                {
                    result++;
                }
                continue;
            }     
            if(child[nx].size() == 0)
            {   
                result++; 
                continue;
            }

            q.push(nx);
        }

    }


}

void dfs(int cur,int before)
{
    if(cur == cut)
    {
        if(child[before].size() == 1)
        {
            result++;
        }
        return;
    }
    for (int nx : child[cur])
    {
        if(nx == cut)
        {   
            if(child[cur].size()==1)
            {
                result++;
            }
            continue;
        }
        if(child[nx].size() == 0)
        {
            result++;
            continue;
        }
        dfs(nx,cur);
    }

}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n ;
    for(int i = 0 ; i < n; i ++)
    {
        int a;
        cin >> a ; 
        //p[i] = a; 
        if(a == -1)
        {
            root = i;
            continue;
        }
        child[a].push_back(i);
        
    }
    
    cin >> cut;
    

    //bfs();

    dfs(root,root);


    cout << result<<"\n";

    

}
