/*
 *    author : Onk_r
 */
#include <bits/stdc++.h>
typedef long long ll;
const ll MOD = 1000000007;
const ll MAX = 1000010;
using namespace std;

pair <ll,ll> cons(ll a,ll b) {
    return make_pair(a,b);
}

ll car(pair <ll,ll> p) {
    return p.first;
}

ll cdr(pair <ll,ll> p) {
    return p.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << car(cons(3,4)) << endl;
    cout << cdr(cons(3,4)) << endl;
    return 0;
}
