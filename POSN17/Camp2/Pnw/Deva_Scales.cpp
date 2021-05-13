#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mxN = 25;
ll a[mxN], b[mxN];
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	ll t=0ll, sum;
	a[0]=1;
	for(int i=1; i<=20; ++i)
		a[i]=a[i-1]*3;
	b[0]=1;
	for(int i=1; i<=20; ++i)
		b[i]=a[i]+b[i-1];
	cin >> n;
	sum=n;
	while(1) {
		int i;
		for(i=0; i<20; ++i)
			if(b[i]+n<a[i+1])
				break;
		n=abs(n-a[i]), ++t;
		sum+=a[i];
		if(n==0) break;
	}
	cout << t << " " << sum/2 << "\n";
	return 0;
}