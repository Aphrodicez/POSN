/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: BST Travel
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *l, *r;
};

void setIO();

node *root;

node *createNode(int val){
    node *tmp = new node;
    tmp->val = val;
    tmp->l = NULL;
    tmp->r = NULL;
    return tmp;
}

void BSTtravel(node *now, string s){
    if(s == "PRE")
        cout << now -> val << " ";
    
    if(now -> l != NULL)
        BSTtravel(now -> l, s);
    
    if(s == "INF")
        cout << now -> val << " ";
    
    if(now -> r != NULL)
        BSTtravel(now -> r, s);
    
    if(s == "POS")
        cout << now -> val << " ";
}

void insertBST(node *now, int val){
    if(val < now->val){
        if(now -> l == NULL){
            now -> l = createNode(val);
            return ;
        }
        insertBST(now->l, val);
    }
    if(val > now->val){
        if(now -> r == NULL){
            now -> r = createNode(val);
            return ;
        }
        insertBST(now->r, val);
    }
}

void BFS(node *root){
    queue <node*> bfs;
    bfs.push(root);
    node *now;
    while(!bfs.empty()){
        now = bfs.front();
        cout << now -> val << "\n";
        bfs.pop();
        if(now -> l != NULL)
            bfs.push(now -> l);
        if(now -> r != NULL)
            bfs.push(now -> r);
    }
    return ;
}

void solve(){
    int n, num, now;
    cin >> n;
    cin >> num;
    root = createNode(num);
    for(int i = 1; i < n; i++){
        cin >> num;
        insertBST(root, num);
    }
    BSTtravel(root, "PRE");
    cout << "\n";
    BSTtravel(root, "POS");
    cout << "\n";
    BSTtravel(root, "INF");
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

/*
5
17
6
3
14
19
*/