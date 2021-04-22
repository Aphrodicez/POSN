/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: 
	Status	: Untested
*/

#include <bits/stdc++.h>
using namespace std;

int main(){	
	string s, s2;
	cin >> s;
	cin >> s2;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != s2[i]){
			cout << s[i] << " " << s2[i] << " " << i << "\n";
		}
	}
    return 0;
}
/*
Test Cases :
Input : 

Output :

*/