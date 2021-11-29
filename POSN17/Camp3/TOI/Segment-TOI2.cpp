/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Big Number
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct GRAPH {
    
};

string s;
vector <string> num[10];
map <vector <string>, long long> mp;

long long eval(int len) {
    for(int k = 0; k < 3; k++) {
        getline(cin, s);
        for(int i = 0; i <= len - 1; i++) {
            num[i].push_back(s.substr(i * 4, 3));
        }
    }
    long long sum = 0;
    for(int i = 0; i <= len - 1; i++) {
        sum = sum * 10 + mp[num[i]];
        num[i].clear();
    }
    return sum;
}

void solve() {    
    mp[{"   ", "  |", "  |"}] = 1;
    mp[{" _ ", " _|", "|_ "}] = 2;
    mp[{" _ ", " _|", " _|"}] = 3;
    mp[{"   ", "|_|", "  |"}] = 4;
    mp[{" _ ", "|_ ", " _|"}] = 5;
    mp[{" _ ", "|_ ", "|_|"}] = 6;
    mp[{" _ ", "  |", "  |"}] = 7;
    mp[{" _ ", "|_|", "|_|"}] = 8;
    mp[{" _ ", "|_|", " _|"}] = 9;
    mp[{" _ ", "| |", "|_|"}] = 0;
    int n, m;
    cin >> n >> m;
    getline(cin, s);
    long long a = eval(n);
    long long b = eval(m);
    cout << a + b << "\n";
}

int main() {
    setIO();
    int q = 1;
    
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
4 3
         _   _ 
  | |_|  _|  _|
  |   | |_   _|
 _       _ 
  |   | |_ 
  |   | |_|


4 2
               
  | |_|   | |_|
  |   |   |   |
       
|_|   |
  |   |
*/