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

int rc[100001];
int lc[100001];
int visited[100001]; // 방문 완료 한것 
int n;
int whoparent[100001];

int result;
int nodecount = 0;

// 순회의 끝이 정확히 무엇인가를 생각 

void inorder(int cur,int before)
{
    // if(nodecount == n)
    // {
    //     cout << cur <<" " << result<<" "<< nodecount<<"\n";
    //     return;
    // }

    // if(lc[cur] != -1)
    // {
    //     result+=1;
    //     cout << cur <<" " << result<<" "<< nodecount<<"\n";
    //     inorder(lc[cur],nodecount+1);
    // }
    // else{
    //     result+=1;
    //     cout << cur <<" " << result<<" "<< nodecount<<"\n";

    // }
    // if(rc[cur] != -1)
    // {
    //     result+=1;
    //     inorder(rc[cur],nodecount+1);
    //     cout << cur <<" " << result<<" "<< nodecount<<"\n";

    // }
    // else{
    //     result+=1;
    //     cout << cur <<" " << result<<" "<< nodecount<<"\n";

    // }
    
    // if(lc[cur] == -1 && rc[cur] == -1)
    // {
    //     if(n==1)
    //         return;
    //     if(nodecount == n) // 중위 순회 node 끝
    //         return;
    //     inorder(before,cur);
    // }
    // if(lc[cur] != -1)
    // {
    //     result+=1;
    //     cout << cur <<" "<<lc[cur] <<" " << result<<" "<< nodecount<<"\n";
    //     inorder(lc[cur],cur);
    // }
    // if(lc[cur] == before || rc[cur] == before)
    // {
    //     nodecount+=1; 
    //     result += 1;
    //     cout << cur <<" " << result<<" "<< nodecount<<"\n";
    // }
    // else{
    //     nodecount+=1; 
    //     cout << cur <<" " << result<<" "<< nodecount<<"\n";
    // }
    // if(nodecount == n)
    // {
    //     return;
    // }
    // if(rc[cur]!=-1)
    // {
    //     result+=1;
    //     cout << cur <<" " <<rc[cur] <<" "<< result<<" "<< nodecount<<"\n";
    //     inorder(rc[cur],cur);
    // }
    

    // inorder left 
    // inorder 
    // inorder right 
    //cout << cur <<" " <<before<< " "<< lc[cur] << " " << rc[cur] <<" "<< nodecount << " "<<result <<"\n";
    // if(nodecount == n)
    //     return;

    // if(lc[cur] == -1 && rc[cur] == -1)
    // {
    //     visited[cur] = 1;
    //     if(n==1)
    //         return;
    //     if(nodecount == n)
    //         return;
    //     result++;
    //     inorder(before,cur);
    // }
    // if(lc[cur] != -1)
    // {
    //     if(visited[lc[cur]] == 1)
    //     {
    //         if(visited[rc[cur]] == 1 )
    //         {
    //             inorder(whoparent[cur],cur);
    //         }    
    //         return;
    //     }
    //     result++;
    //     inorder(lc[cur],cur);
    // }
    // if (lc[cur] == before || rc[cur] == before )
    // {
    //     cout << "Lec" << cur << " " <<before<<"\n";
    //     result++;
    //     inorder(whoparent[cur],cur);
    // }
    // else{
    //     nodecount++;
    //     visited[cur] = 1 ;
    // }

    // if (rc[cur] != -1)
    // {
    //     if(visited[rc[cur]] == 1)
    //     {         
    //         return;
    //     }
    //     result++;
    //     inorder(rc[cur],cur);        
    // }

    // if (lc[cur] == before || rc[cur] == before )
    // {
    //     cout << "Rec" << cur << " " <<before<<"\n";
    //     result++;
    //     inorder(whoparent[cur],cur);
    // }
    //cout << cur <<" " <<before<< " "<< lc[cur] << " " << rc[cur] <<" "<< nodecount << " "<<result <<"\n";




    if(lc[cur] == - 1 && rc[cur] == -1)
    {
        if(n==1)
            return;
        visited[cur] =1;
        nodecount +=1;
        result++;
        return;
    }

    if(lc[cur] != -1)
    {
        result++;
        inorder(lc[cur],cur);
    }
    // cout <<"=========="<<"\n";
    // cout << cur <<" " <<before<< " "<< lc[cur] << " " << rc[cur] <<" "<< nodecount << " "<<result <<"\n";
    nodecount +=1;
    if(rc[cur] != -1)
    {
        result++;
        inorder(rc[cur],cur);
    }
    
    if( (visited[rc[cur]] == 1 && lc[cur] ==-1) || (visited[lc[cur]] == 1 && rc[cur] ==-1))
    {   
        if(nodecount != n )
        result++;
    }

    // cout <<"******" <<"\n";
    // cout << cur <<" " <<before<< " "<< lc[cur] << " " << rc[cur] <<" "<< nodecount << " "<<result <<"\n";


    return;
}   


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>> n;

    for(int i = 0 ; i< n; i++)
    {
        int root , l, r ;
        cin >> root >> l >> r; 
        lc[root] = l;
        rc[root] = r; 
        if(l != -1)
        {
            whoparent[l] = root;
        }
        if(r != -1)
        {
            whoparent[r] = root;  
        }
    }

    inorder(1,1);

    cout << result <<"\n";
}
