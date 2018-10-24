/*
 *    author : Onk_r
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Approaches
//
// #1.use pow(num,-1);

int main() {
    ll n;
    cin >> n;
    ll a[n];
    ll product = 1;

    for(ll i=0;i<n;i++) {
        cin >> a[i];
        product *= a[i];
    }

    ll newArray[n];
    for(ll i=0;i<n;i++) {
        cout << product*pow(a[i],-1) << " ";
    }
    cout << endl;
    return 0;
}
