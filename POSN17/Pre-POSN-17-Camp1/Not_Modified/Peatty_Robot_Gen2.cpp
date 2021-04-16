#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    string s;

    cin >> s;

    int dir = 0, nextdir;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'Z'){
            cout << "Z";
            dir = 0;
        }
        else{
            if(s[i] == 'N')
                nextdir = 0;
            if(s[i] == 'E')
                nextdir = 1;
            if(s[i] == 'S')
                nextdir = 2;
            if(s[i] == 'W')
                nextdir = 3;
            while(dir != nextdir){
                cout << "R";
                dir++;
                dir %= 4;
            }
            cout << "F";
        }
    }

    return 0;
}
/*
NNEESWZEE
*/