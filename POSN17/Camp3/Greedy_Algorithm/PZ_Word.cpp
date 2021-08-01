/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
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

void TESTCASE() {
    
}

vector <pair <int, int>> ans;
int cnt[30], visited[30];

void solve() {
    ans.clear();
    memset(cnt, 0, sizeof (cnt));
    memset(visited, 0, sizeof (visited));
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 1; i <= n; i++) {
        cnt[s[i - 1] - 'a']++;
    }
    for(int i = 1; i <= n; i++) {
        int now = s[i - 1] - 'a';
        cnt[now]--;
        if(visited[now] > 0)
            continue;
        for(int j = now + 1; j < 26; j++) {
            if(cnt[j] > 0)
                visited[j] = 0;
        }
        visited[now] = i;
    }
    for(int i = 0; i < 26; i++) {
        if(!visited[i])
            continue;
        ans.push_back(make_pair(visited[i], i));
    }
    sort(ans.begin(), ans.end());
    int mx = 0;
    for(auto x : ans) {
        for(int i = mx; i < x.second; i++) {
            if(visited[i])
                continue;
            visited[i] = 1;
            cout << char(i + 'a');
        }
        mx = max(mx, x.second + 1);
        cout << char(x.second + 'a');
    }
    for(int i = mx; i < 26; i++) {
        cout << char(i + 'a');
    }
    cout << "\n";
}

int main() {
    setIO();
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
2
abcdefghijklmnopqrstuvwxza
asvbraabrere

1
muyhuaklhijomdlfgzrtlxifwsdvxanrgncpeqeqbyf
*/