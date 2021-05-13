#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e5+10;
int l[mxN], r[mxN], a[mxN];
void query() {
	int n,sum=0,mx=-2e9;
	cin >> n;
	for(int i=1; i<=n; ++i) {
		cin >> a[i];
		sum+=a[i];
		sum=max(sum, 0);
		mx = l[i] = max(sum, mx);
	}
	sum=0,mx=-2e9;
	for(int i=n; i>=1; --i) {
		sum += a[i];
		sum = max(sum, 0);
		mx = r[i] = max(sum, mx);
	}
	int ans=-2e9;
	for(int i=1; i<=n; ++i)
		ans = max(l[i]+r[i+1], ans);
	cout << ans << "\n";
}
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int q;
	cin >> q;
	while(q--)
		query();
	return 0;
}