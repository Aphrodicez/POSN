#include <bits/stdc++.h>
using namespace std;

int rand(int l, int r){
    return l + rand() % (r - l + 1);
}

double frand(double l, double r){
    return l + fmod(rand(), r - l + 1);
}

int ans[100010];

int main(int argc, char* argv[]){
    int caseNumber = atoi(argv[1]);
    srand(caseNumber);
    int q = rand(1, 15);
    cout << q << "\n";
    while(q--) {
        int n = rand(26, (int)1e2);
        for(int i = 0; i < 26; i++) {
            ans[i] = i;
        }
        for(int i = 26; i < n; i++) {
            ans[i] = rand(0, 25);
        }
        random_shuffle(ans, ans + n);
        for(int i = 0; i < n; i++)
            cout << char(ans[i] + 'a');
        cout << "\n";
    }
    return 0;
}