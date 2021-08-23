/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Hash Table
    Status	: Accepted
    Created	: 23 August 2021 [00:15]
*/

#include <bits/stdc++.h>
using namespace std;

#define i first
#define j second
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define pc(x) putchar(x)
#define MP make_pair
#define dec(x) fixed << setprecision(x)
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct GRAPH {
    
};

const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int MOD = 99999989;
const int HASH_SIZE = 1e7 + 19;

void TESTCASE() {
    
}

i64 power[2][N];

int hashTable[HASH_SIZE];

void solve() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;
    for(i64 j = 0; j < b; j++) {
        power[0][j] = (j * j) % MOD; 
    }
    for(i64 j = 0; j < m; j++) {
        power[1][j] = (((j * j) % MOD) * j) % MOD;
    }
    int num, now;
    for(int i = 0; i < a; i++) {
        cin >> num;
        for(int j = 0; j < b; j++) {
            now = (num + power[0][j]) % MOD;
            int key = now % HASH_SIZE; 
            while(hashTable[key]) {
                key++;
                key %= HASH_SIZE;
            }
            hashTable[key] = now;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> num;
        for(int j = 0; j < m; j++) {
            now = (num + power[1][j]) % MOD;
            int key = now % HASH_SIZE;
            while (hashTable[key]){
                if(hashTable[key] == now) {
                    ans++;
                    break;
                }
                key++;
                key %= HASH_SIZE;
            }
        }
    }
    cout << ans << "\n";
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
3 1 5 1
1 2 5
5 5 3 0 7
*/