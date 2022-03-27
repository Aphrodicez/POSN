/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Brute Force + Math
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

char s[3][50];
char trash[50];

map <vector <int>, long long> mp;

int eval(int n) {
    for(int i = 0; i < 3; i++) {
        gets(s[i]);
    }
    long long val = 0;
    vector <int> vec;
    for(int state = 0; state < n; state++) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(s[i][j + 4 * state] == ' ')
                    vec.push_back(i * 3 + j);
            }
        }
        val *= 10;
        val += mp[vec];
        vec.clear();
    }
    return val;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    gets(trash);
    mp[{0, 1, 2, 3, 4, 6, 7}] = 1;
    mp[{0, 2, 3, 8}] = 2;
    mp[{0, 2, 3, 6}] = 3;
    mp[{0, 1, 2, 6, 7}] = 4;
    mp[{0, 2, 5, 6}] = 5;
    mp[{0, 2, 5}] = 6;
    mp[{0, 2, 3, 4, 6, 7}] = 7;
    mp[{0, 2}] = 8;
    mp[{0, 2, 6}] = 9;
    mp[{0, 2, 4}] = 0;
    printf("%lld\n", eval(a) + eval(b));
    return 0;
}

/*
5 5
     _   _       _ 
  |  _|  _| |_| |_ 
  | |_   _|   |  _|
 _   _   _   _   _
|_    | |_| |_| | |
|_|   | |_|  _| |_|
*/