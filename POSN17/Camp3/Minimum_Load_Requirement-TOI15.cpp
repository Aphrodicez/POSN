/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: Permutation + Branch and Bound + Binary Search + Quicksum + Greedy Algorithm
    Status	: Accepted
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

const int N = 1e1 + 10;
const int M = 1e7 + 10;

int n, m, q;

int lift[N], a[N], t[N], group[N], qs[M];

bool check(int timeLimit) {
    bool usedLift[N];
    memset(usedLift, false, sizeof usedLift);
	for(int i = 1, j; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			if(usedLift[j])
                continue;
			int lb = group[i], rb = group[i + 1];
            int cnt = 0;
            bool ch = true;
			while(lb < rb && ch) {
				cnt++;
				int nextl = upper_bound(qs + lb, qs + rb, lift[j] - a[i] + qs[lb - 1]) - qs;
				if(nextl == lb) 
                    ch = false;
				lb = nextl;
			}
			if(ch && cnt <= timeLimit) {
                usedLift[j] = true;
                break;
            }
		}
		if(j == n + 1)
            return false;
	}
	return true;
}

bool solve(int tc) {
    for(int i = 1; i <= n; i++) {
        cin >> group[i];
    }
    group[n + 1] = m + 1;
	do {
		if(check(t[tc]))
            return true;
	}while(next_permutation(a + 1, a + n + 1));
	return false;
}

int main() {
    setIO();
    cin >> n >> m >> q;
	for(int i = 1; i <= n; i++)
		cin >> lift[i];
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++) {
		cin >> qs[i];
        qs[i] += qs[i - 1];
    }
	for(int i = 1; i <= q; i++)
		cin >> t[i];
	sort(lift + 1, lift + n + 1);
	for(int i = 1; i <= q; i++)
		cout << (solve(i) ? "P" : "F") << "\n";
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}
/*
2 10 3
230 300
56 65
160 120 35 80 42 87 72 45 55 63
2 2 1
1 4
1 3
1 6

3 8 1
150 100 200
45 60 55
80 45 50 62 48 40 68 55
2
1 3 5
*/