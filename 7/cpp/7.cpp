/*
 *    author : Onk_r
 */
#include <bits/stdc++.h>
typedef long long ll;
const ll MOD = 1000000007;
const ll MAX = 1000010;
using namespace std;

// # Approach:
//     1. increment count by 1 for each single characher
//     2. increment count by 2 for two characher if they are smaller than "26"

ll rec(string input) {
    if(!input.length())
        return 0;
    if(input.length() == 1)
        return 1;
    if(input.length() == 2 && input <= "26") {
        return 2;
    }
    ll count = rec(input.substr(1));
    string tmp = input.substr(0,2);
    if(tmp.length() == 2 && tmp <= "26") {
        count += rec(input.substr(2));
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input;

    cout << rec(input) << endl;

    return 0;
}
/*
112 : 3
343 : 1
*/
