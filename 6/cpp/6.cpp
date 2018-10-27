/*
 *    author : Onk_r
 */
#include <bits/stdc++.h>
typedef long long ll;
const ll MOD = 1000000007;
const ll MAX = 1000010;
using namespace std;

// # Approach :
//     Using three ptrs prev,curr,next
//     curr->link = prev ^ next
//

struct Node {
    ll val;
    struct Node * both;
    Node(ll val) {
        this->val = val;
        this->both = NULL;
    }
};

Node * head = NULL;

Node * XOR(Node *f = NULL,Node *s = NULL) {
    return (Node *)((unsigned ll)(f) ^ (unsigned ll)(s));
}

void add(Node *element) {
    if(head == NULL) {
        head = element;
        element->both = XOR();
    }
    else {
        Node *prev = NULL, *curr = head, *next = XOR(curr->both,prev);
        while (next!=NULL)
        {
            prev = curr;
            curr = next;
            next = XOR(curr->both,prev);
        }
        curr->both = XOR(prev,element);
        element->both = XOR(curr);
    }
}

ll get(ll index) {
    ll i = 0;
    Node *p = head, *l = head, *n = XOR(l->both,NULL);
    while (n!=NULL)
    {
        if(i == index) {
            return l->val;
        }
        p = l;
        l = n;
        n = XOR(l->both,p);
        i+=1;
    }
    if(i == index) {
        return l->val;
    }
    else {
        return -1;
    }
}

void print() {
    Node *p = head, *l = head, *n = XOR(l->both,NULL);
    cout << "Forward traversal : ";
    while (n!=NULL)
    {
        cout << l->val << " ";
        p = l;
        l = n;
        n = XOR(l->both,p);
    }
    cout << l->val << endl;
    cout << "Backward traversal : ";
    p = l;
    n = XOR(l->both);
    while (n!=NULL)
    {
        cout << l->val << " ";
        p = l;
        l = n;
        n = XOR(l->both,p);
    }
    cout << l->val << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    add(new Node(1));
    add(new Node(2));
    add(new Node(3));
    add(new Node(4));
    add(new Node(5));
    print();
    cout << get(3) << endl;
    return 0;
}
