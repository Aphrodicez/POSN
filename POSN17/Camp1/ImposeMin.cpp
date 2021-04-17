/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: 
	Status	: Untested
*/

#include <bits/stdc++.h>
using namespace std;

string s;

vector <int> vec;

vector <string> a;

int main(){
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, num;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num;
		if(num % 10 == 0){
			vec.push_back(num);
			continue;
		}
		a.push_back(to_string(num));
		int sz = a.size();
		
	}
	sort(a.begin(), a.end());
	for(int x : vec){
		cout << x;
	}
	for(string s: a){
		cout << s;
	}
    return 0;
}
/*
Test Cases :
Input : 

Output :

*/