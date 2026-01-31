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

#define INF 0x3f3f3f3f

using namespace std;
vector<string> split(const string& s, const string& sep){
    vector<string> ret;
    int pos = 0 ;
    while( pos < s.size()){
        int nxt_pos = s.find(sep,pos);
        if(nxt_pos == -1)
            nxt_pos = s.size();
        if(nxt_pos - pos > 0 )
            ret.push_back(s.substr(pos,nxt_pos - pos));
        pos = nxt_pos + sep.size();
    }

    return ret;
}



int main()
{
    string s = "hello";
    s += " BKD!";                   // hello BKD!
    cout << s.size() << '\n';       // 10
    cout << s.substr(2, 3) << '\n'; // llo
    cout << s[1] << '\n';           // e
    s.replace(6, 4, "guys");        // hello guys
    cout << s << '\n';
    int it = s.find("guys");      // 6
    s.replace(it, 4, "everyone"); // hello everyone
    cout << s << '\n';
    s.erase(7, 6); // hello ee  7번째 부터 6개 (veryon)
    cout << s << '\n';
    s[6] = 'm'; // hello me 6 m 
    cout << s << '\n';
    s.insert(0, "say "); // say hello me
    cout << s << '\n';
    if (s.find("to") == string::npos) // string::npos == -1
        cout << "'to' is not in string 's'\n";
    vector<string> chunks1 = split("welcome to the black parade", " ");
    // welcome/to/the/black/parade/
    for (auto chunk : chunks1)
        cout << chunk << '/';
    cout << '\n';
    vector<string> chunks2 = split("b*!*ac*!**!*e*!*y*!*", "*!*");
    // b/ac/a/y/
    for (auto chunk : chunks2)
        cout << chunk << '/';
}
