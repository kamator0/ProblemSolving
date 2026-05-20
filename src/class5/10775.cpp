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
// long long 일

using namespace std;

int g, p;
vector<int> f;
int visited[100001];
int dp[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> g;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        int n;
        cin >> n;
        f.push_back(n);
    }


    for(int i =1 ; i<= g ; i++)
    {
        dp[i] = i;
    }


    int cnt = 0;
    bool flag = false;




    for (auto x : f)
    {
        flag = false;

       // cout << "1" << "\n";

        for (int i = dp[x]; i >= 1; i--)
        {
            if (visited[i] == 0)
            {
                visited[i] = 1;
                flag = true;
                dp[x] --;
                break;
            }
        }

        if (!flag)
            break;

        cnt++;
    }

    cout << cnt << "\n";
}
