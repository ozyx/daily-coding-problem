/*
 *    author : Onk_r
 */
#include <bits/stdc++.h>
typedef long long ll;
const ll MOD = 1000000007;
const ll MAX = 1000010;
const ll inf = LONG_LONG_MAX;
using namespace std;

// # Approach :
//
//     1. First move all negative integers to left of array and replace them with high number e.g. INT_MAX
//     2. traverse array and check if number is in range of 1 and N if not ignore it
//     3. If true in step 2 then itterate over all a[a[i]] elements to remove dependency and assign -1 to all visited numbers
//     4. at last again check if number is != -1 then its missing number

void print(ll a[],ll n) {
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void swap(ll *t,ll *y) {
    ll p = *y;
    *y = *t;
    *t = p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    ll a[N];

    for(ll i=0;i<N;i++)
        cin >> a[i];

    ll prevPos = 0;
    for(ll i=0;i<N;i++) {
        if(a[i] < 0) {
            a[i] = inf;
            swap(a+i,a+prevPos);
            prevPos++;
        }
    }

    //print(a,N);
    for(ll i = prevPos;i<N;i++) {
        if(a[i] > 0 && a[i] <= N) {
            ll at = a[i] - 1;
            // Nesting of a[a[i]] and assign -1 to all visited
            while(at >= 0 && at < N) {
                ll tmp = a[at] - 1;
                a[at] = -1;
                at = tmp;
            }
        }
        //print(a,N);
    }

    for(ll i=0;i<N;i++) {
        if(a[i]!=-1) {
            cout << "Missing : " <<  i+1 << endl;
            return 0;
        }
    }
    cout << "Missing : " <<  N+1 << endl;

    return 0;
}
/*
e.g. testcases

4
3 4 -1 1

4
3 3 3 3
*/
