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

int visit[27];
int n ; 
char lc [27] ;
char rc [27] ;

void preorder(char cur)
{
    if ( cur -'\0' < 65 || cur - '\0' > 90)
        return;
    cout << cur ;
    preorder(lc[cur-'\0'-64]);
    preorder(rc[cur-'\0'-64]);
}
void inorder(char cur)
{
    if ( cur -'\0' < 65 || cur - '\0' > 90)
        return;
    inorder(lc[cur-'\0'-64]);
    cout << cur ;
    inorder(rc[cur-'\0'-64]);
}
void postorder(char cur)
{
    if ( cur -'\0' < 65 || cur - '\0' > 90)
        return;
    postorder(lc[cur-'\0'-64]);
    postorder(rc[cur-'\0'-64]);
    cout << cur ;
}

// 대문자 A ASCII CODE 65 
// . 문자 ASCII 46 근데 굳이 알 필요 없음 


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n ;

    for(int i = 0 ; i < n; i ++)
    {
        char root, l , r ;
        cin >> root >> l >> r; 
        // if ( r-'\0' <65 || r-'\0' > 90 || l-'\0' < 65 || l-'\0' > 90)
        // {
        //     root  = (root - '\0' - 64) ;
            
        // }
        // if (l-'\0' == 46)
        // {
            
        // }
        // if (r-'\0' == 46)
        // {
            
        // }
        lc[root-'\0'-64] = l ;
        rc[root-'\0'-64] = r ; 
    }


    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
    cout <<"\n";

}
