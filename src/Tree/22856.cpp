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
int lc[100003];
int rc[100003];

int last;
int result;

bool flag = false;

void inorder(int cur)
{
    if (lc[cur] != -1)
    {
        inorder(lc[cur]);
    }
    last = cur;
    if (rc[cur] != -1)
    {
        inorder(rc[cur]);
    }

    return;
}

void solution(int cur)
{
    // if (last == 1)
    //     return;
    //cout << "처음 " << cur << " " << result << "\n";
    if (flag)
        return;

    if (lc[cur] != -1)
    {
        result++;
        solution(lc[cur]);
        if(flag) return;
        result++;
    }
    //cout << "중간 " << cur << " " << result << "\n";
    if (cur == last)
    {
        flag = true;
        return;
    }
    if (rc[cur] != -1)
    {
        result++;
        solution(rc[cur]);
        if(flag) return;
        result++;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int r, a, b;
        cin >> r >> a >> b;
        lc[r] = a;
        rc[r] = b;
    }

    inorder(1);

    //cout << last<<"\n";

    solution(1);

    cout << result << "\n";
}
