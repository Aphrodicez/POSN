/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Expression Tree
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

void setIO();

struct node{
    char val;
    node *l, *r;
};

node *createNode(char val){
    node *tmp = new node;
    tmp -> val = val;
    tmp -> l = NULL;
    tmp -> r = NULL;
    return tmp;
}

void BSTtravel(node *now, string s){
    if(s == "INF" && !isalpha(now -> val))
        cout << "(";
    if(s == "PRE")
        cout << now -> val;
    
    if(now -> l != NULL)
        BSTtravel(now -> l, s);

    if(s == "INF")
        cout << now -> val;

    if(now -> r != NULL)
        BSTtravel(now -> r, s);

    if(s == "POS")
        cout << now -> val;
    
    if(s == "INF" && !isalpha(now -> val))
        cout << ")";
}

stack <node*> st;

void solve(){
    node *root;
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++){
        if(isalpha(s[i])){
            st.push(createNode(s[i]));
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            root = createNode(s[i]);
            root -> r = st.top();
            st.pop();
            root -> l = st.top();
            st.pop();
            st.push(root);
        }
    }
    root = st.top();
    BSTtravel(root, "INF");
    cout << "\n";
    BSTtravel(root, "PRE");
}

int main() {
    solve();
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
a b c+*d+
*/