#include <bits/stdc++.h>
using namespace std;

int rand(int l, int r){
    return rand() % (r - l) + l; 
}

int main(int argc, char* argv[]){
    srand(atoi(argv[1]));
    int n = rand(1, 1e2);
    cout << n << "\n";
    for(int i = 0; i < n; i++){
        cout << rand(1, 1e3) << " ";
    }
}