/*
 *    author : Onk_r
 */
#include <bits/stdc++.h>
typedef long long ll;
const ll MOD = 1000000007;
const ll MAX = 1000010;
using namespace std;

// Approaches
//
// #1.
// Use hashtable with O(1) lookup and check for every number. because space complexity is not mentioned

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin >> n >> k;
    ll arr[n];
    set <ll> unique;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        unique.insert(arr[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        if(unique.count(k-arr[i])) {
            cout << arr[i]  << " + " << k - arr[i]  << " = " << k << endl;
            return 0;
        }
    }

    cout << "Not possible!" << endl;
    return 0;
}
