/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: String Matching [ Rabin Karp ] + Hash
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
const int MOD = 1e6 + 3;
const int HASH_VALUE = 37;

int mod(int val) {
    return ((val % MOD) + MOD) % MOD;
}

int hash_function(char c) {
    if(isalpha(c))
        return c - 'a';
    else if(isdigit(c))
        return c - '0' + 26;
}

void solve() {
    string text, pattern;
    cin >> text >> pattern;
    int place_value = 1;
    int hash_text = 0, hash_pattern = 0;
    int sz = (int)pattern.size();
    for(int i = 0; i < sz; i++) {
        hash_text = mod(mod(mod(hash_text) * mod(HASH_VALUE)) + mod(hash_function(text[i]))); 
        hash_pattern = mod(mod(mod(hash_pattern) * mod(HASH_VALUE)) + mod(hash_function(pattern[i]))); 
        if(i == sz - 1)
            break;
        place_value = mod(mod(place_value) * mod(HASH_VALUE));
    }
    for(int i = 0; i + sz - 1 < (int)text.size(); i++) {
        if(hash_text == hash_pattern) {
            bool ans = true;
            for(int j = 0; j < sz; j++) {
                if(text[i + j] != pattern[j]) {
                    ans = false;
                    break;
                }
            }
            if(ans) {
                cout << "Lucky" << "\n";
                return ;
            }
        }
        hash_text = mod(mod(mod(hash_text - mod(hash_function(text[i]) * place_value)) * HASH_VALUE) + hash_function(text[i + sz]));
    }
    cout << "Unlucky" << "\n";
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
peatthandsome
peatt

peatt12345
peatt2
*/