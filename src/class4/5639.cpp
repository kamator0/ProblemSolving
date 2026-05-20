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

#define INF 0x3f3f3f3f // 경우에 따라 다르게
// long long 일

using namespace std;
vector<int> nums;
int lc[10001];
int rc[10001];
int visited[10001];

void dfs(int cur)
{

    if (lc[cur] != 0)
    {
        dfs(lc[cur]);
    }
    cout << cur << "\n";

    if (rc[cur] != 0)
    {
        dfs(rc[cur]);
    }

    // 오른쪽 노드로 갔다가 다시 처리하는게 말이 안되서 그냥 다른방법 생각함
}

void find(int start, int end)
{
    //cout << start <<" " << end <<"\n";
    if (start > end)
        return;

    int root = nums[start];
    int mid = end + 1;
    for (int i = start+1; i <= end; i++)
    {
        if (nums[i] > root)
        {
            mid = i;
            break;
        }
    }

    find(start+1, mid-1); // 왼
    find(mid, end); // 오 
    cout << root << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    while (cin >> x)
    {
        nums.push_back(x);
    }

    // for (auto x : nums)
    // {
    //     cout << x << " ";
    // }
    // cout << "\n";

    find(0, nums.size()-1);
    // crtl + d

    

}
