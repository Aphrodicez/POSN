/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Hash Table
    Status	: Accepted
    Created	: 24 August 2021 [00:16]
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
const int HASH_SIZE = 5e6 + 11;

void TESTCASE() {
    
}

int hashTable[HASH_SIZE], hashValue[2][HASH_SIZE];

int x[4][N], y[4][N];

int hashFunction(int sumx, int sumy) {
    int key = ((sumx + (3 * sumy) % HASH_SIZE) % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
    return key;
}

void solve() {
    int ansx, ansy, n;
    cin >> ansx >> ansy >> n;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < n; j++) {
            cin >> x[i][j] >> y[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int sumx = x[0][i] + x[1][j];
            int sumy = y[0][i] + y[1][j];
            int key = hashFunction(sumx, sumy);
            while(hashTable[key]) {
                key++;
                key %= HASH_SIZE;
            }
            hashTable[key] = (n * i) + j + 1;
            hashValue[0][key] = sumx;
            hashValue[1][key] = sumy;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int sumx = ansx - (x[2][i] + x[3][j]);
            int sumy = ansy - (y[2][i] + y[3][j]);
            int key = hashFunction(sumx, sumy);
            while(hashTable[key]) {
                if(hashValue[0][key] == sumx && hashValue[1][key] == sumy) {
                    int idx = hashTable[key] - 1;
                    cout << x[0][idx / n] << " " << y[0][idx / n] << "\n";
                    cout << x[1][idx % n] << " " << y[1][idx % n] << "\n";
                    cout << x[2][i] << " " << y[2][i] << "\n";
                    cout << x[3][j] << " " << y[3][j] << "\n";
                }
                key++;
                key %= HASH_SIZE;
            }
        }
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
/*
-2 2
2
1 2 -2 10
-6 -6 -1 3
-1 -2 -6 -5
5 -4 7 0

-1 3
3
1 -10 16 3 -11 -10
-17 7 -15 -2 -7 9
-2 6 -18 -15 5 19
9 -18 -7 -17 19 4

-10 10
2
1 8 -2 -5
-5 -5 -5 2
9 0 -1 4
10 8 -5 3
*/