/*
 *    author : Onk_r
 */
#include <bits/stdc++.h>
#include <assert.h>
typedef long long ll;
const ll MOD = 1000000007;
const ll MAX = 1000010;
using namespace std;

// # Approaches
// # 1. Using BFS traversal using queue solve this problem

struct Node {
    string val;
    struct Node *left,*right;
    Node(string val,Node *left = NULL,Node *right = NULL) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

string serialize(Node *root) {
    queue <Node*> bfs;
    string tree = "";
    bfs.push(root);
    while(!bfs.empty()) {
        Node *top = bfs.front();
        bfs.pop();
        if(!top) {
            tree+="NONE ";
            continue;
        }
        tree += top->val + " ";
        bfs.push(top->left);
        bfs.push(top->right);
    }
    return tree;
}

vector <string> getTokens(string tree,char format) {
    vector <string> tokens;
    string tmp = "";
    for (int i = 0; i < tree.length(); ++i)
    {
        if(tree[i] == format) {
            tokens.push_back(tmp);
            tmp = "";
            continue;
        }
        tmp+=tree[i];
    }
    return tokens;
}

Node * deserialize(string tree) {
    vector <string> tokens = getTokens(tree,' ');
    queue <Node*> bfs;
    ll k = 0;
    Node * root = new Node(tokens[k++]);
    bfs.push(root);
    while(k < tokens.size()) {
        Node * subroot = bfs.front();
        bfs.pop();
        subroot->left = new Node(tokens[k++]);
        subroot->right = new Node(tokens[k++]);
        bfs.push(subroot->left);
        bfs.push(subroot->right);
    }
    return root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node * root = NULL;
    root = new Node("root",new Node("left",new Node("left.left")),new Node("right"));
    cout << serialize(root) << endl;
    assert(deserialize(serialize(root))->left->left->val == "left.left");
    return 0;
}
