/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: 
	Status	: Untested
*/

#include <bits/stdc++.h>
using namespace std;

struct A {
	string s;
	bool operator < (const A& o) const{
		if(s + o.s < o.s + s)
			return true;
		return false;
	}
};

string s;

vector <A> vec;

int main(){
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, sz, it;
	char tmp;
	cin >> n;
	for(int i = 1; i <= n; i++){
		//s = to_string(i);
		cin >> s;
		vec.push_back({s});
	}
	sort(vec.begin(), vec.end());
	for(auto x : vec){
		cout << x.s << " ";
	}
    return 0;
}
/*
Test Cases :
Input : 

Output :

*/