/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: 
	Status	: Untested
*/

#include <bits/stdc++.h>
using namespace std;

int dp[1010];

string s;

int main(){
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	
	int nowten = 1, nextten = 10, sum, lak, q, k = 1, num, digit, position, idx;
	for(int i = 1; i <= 8; i++){
		dp[i] = 9 * i;
		for(int j = 0; j < i - 1; j++){
			dp[i] *= 10;
		}
		dp[i] += dp[i-1];
		//cout << dp[i] << "\n";
	}
	cin >> q;
	while(q--){
		cin >> k;
		lak = lower_bound(dp + 1, dp + 8 + 1, k) - dp;
		idx = (k-1) - dp[lak-1];
		digit = idx % lak;
		position = idx / lak;
		nowten = pow(10, lak-1);
		num = nowten + position;
		s = to_string(num);
		cout << s[digit] << "\n";
		//cout << num << " " << idx << " " << position << "\n";
	}
    return 0;
}
/*
Test Cases :
Input : 

Output :

*/