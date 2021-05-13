#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e5+10;
struct A {
	int e,s,w;
	bool operator < (const A&o )const {
		if(e!=o.e) return e<o.e;
		return s<o.s;
	}
} a[mxN];
int dp[mxN];
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n,idx;
	cin >> n;
	for(int i=1; i<=n; ++i)
		cin >> a[i].s >> a[i].e >> a[i].w;
	sort(a+1, a+1+n);
	for(int i=1; i<=n; ++i) {
		idx = lower_bound(a+1, a+1+n, A{a[i].s, INT_MIN, INT_MIN})-(a+1);
		dp[i] = max(dp[i-1], dp[idx]+a[i].w);
	}
	cout << dp[n] << "\n";
	return 0;
}