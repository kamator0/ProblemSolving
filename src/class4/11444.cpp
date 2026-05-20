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

#define INF 0x3f3f3f3f // 경우에 따라 다르게
// long long 일

using namespace std;

long long n;

// dp로 10^18 정의 하면 메모리초과인데?

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    // 0 , 1

    long long cnt = 1; // n번째 0부터시작

    int dp1 = 0;
    int dp2 = 1;

    // n-1 이 1이되고 n이 0이 될때까지  돌림
    // 그러면 그게 한 주기고 break한 다음에 n을 cnt로 나누고 나머지로 어찌하면 되지 않을가?

    int idx = 1000000007;

    while (true)
    {
        if (cnt % 2 == 1)
        {
            dp1 += (dp2 % idx);
            if (dp1 >= idx)
                dp1 %= idx;
        }
        else
        {
            dp2 += (dp1 % idx);
            if (dp2 >= idx)
                dp2 %= idx;
        }

        cnt++;

        if (cnt % 2 == 1)
        {
            if (dp2 == 0 && dp1 == 1)
                break;
        }
        else
        {
            if (dp1 == 0 && dp2 == 1)
                break;
        }
    }

    cout << cnt <<"\n";
    // int dp3 = 0 ;

    // 지금 생각해보니 cnt 를 10^18 까지 돌리면 일단 시간초과임
    // 근데 왜 나머지가 반복되는거지?
    // while (cnt <= n)
    // {
    //     if (cnt % 2 == 1)
    //     {
    //         dp1 += (dp2 % 1000000007);
    //         if (dp1 >= 1000000007)
    //             dp1 %= 1000000007;
    //     }
    //     else
    //     {
    //         dp2 += (dp1 % 1000000007);
    //         if (dp2 >= 1000000007)
    //             dp2 %= 1000000007;
    //     }

    //     cnt++;
    // }

    // if (n % 2 == 1)
    // {
    //     cout << dp2 << "\n";
    // }
    // else
    // {
    //     cout << dp1 << "\n";
    // }
}
