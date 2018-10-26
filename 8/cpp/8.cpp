/*
 *    author : Onk_r
 */
#include <bits/stdc++.h>
typedef long long ll;
const ll MOD = 1000000007;
const ll MAX = 1000010;
const ll NA = LONG_LONG_MIN;

using namespace std;

// # Approach:
//     Recurse using postorder traversal on binary subtree
//     and increment count if leftVal == rightVal == root->val

struct Node {
    ll val;
    struct Node *left,*right;
    Node(ll val,struct Node *left = NULL,struct Node *right = NULL) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

Node *root = NULL;
ll ans;
ll valueOfSubtree(Node *root) {
    if(!root)
        return -1;
    ll left = valueOfSubtree(root->left);
    ll right = valueOfSubtree(root->right);
    if(left == -1 && right == -1) {
        ans++;
        return root->val;
    }
    if(left == right && left == root->val) {
        ans++;
        return root->val;
    }
    return NA;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    root = new Node(0,new Node(1),new Node(0,new Node(1,new Node(1),new Node(1)),new Node(0)));
    valueOfSubtree(root);
    cout << ans << endl;
    return 0;
}
