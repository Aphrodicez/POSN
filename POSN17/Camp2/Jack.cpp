/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: BST Travel
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

struct node{
    int val;
    node *l, *r;
};

node *root;

node *createNode(int val){
    node *tmp = new node;
    tmp->val = val;
    tmp->l = NULL;
    tmp->r = NULL;
    return tmp;
}

void insertBST(node *now, int val){    
    if(val < now -> val){        
        cout << "L";
        if(now -> l == NULL){
            now -> l = createNode(val);
            cout << "*\n";
            return ;
        }
        insertBST(now -> l, val);
    }
    if(val > now -> val){        
        cout << "R";
        if(now -> r == NULL){
            now -> r = createNode(val);
            cout << "*\n";
            return ;
        }
        insertBST(now -> r, val);
    }
}

void solve(){
    int n, val;
    cin >> n;
    cin >> val;
    root = createNode(val);
    cout << "*\n";
    for(int i = 1; i < n; i++){
        cin >> val;
        insertBST(root, val);
    }
}

int main() {
    setIO();
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}