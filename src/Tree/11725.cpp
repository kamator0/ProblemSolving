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

int visit[100001];
vector<int> arr [100001];
int whoparent[100001];

void solution(int cur)
{

    //cout << cur << "\n";
    for (int i = 0 ; i < arr[cur].size(); i++ )
    {
        if(visit[arr[cur][i]] == 1)
            continue;
        whoparent[arr[cur][i]] = cur;
        visit[arr[cur][i]] = 1;
        solution(arr[cur][i]);

    }

    // 시작 부터 모든 노드 순회해서 답을 못 구 했다가 단일 노드 기준으로 바꿔서 구함 


    return ; 
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for(int i= 1 ; i <= n-1 ; i++){
        int a,b;
        cin >> a >>b ;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    // for (size_t i = 1; i <= n; i++)
    // {
    //     for(int j = 0; j <arr[i].size(); j++ )
    //     {
    //         cout << arr[i][j] <<" ";
    //     }
    //     cout << "\n";
    // }
    

    visit[1] = 1 ; 
    solution(1) ; 

    //cout << "=======" <<"\n";

    for(int i= 2; i <= n ; i++)
    {
        cout << whoparent[i] << "\n";
    }


}
