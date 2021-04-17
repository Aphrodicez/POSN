/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: 
	Status	: Untested
*/

#include <bits/stdc++.h>
using namespace std;

struct A{
	int val, idx;
	bool operator < (const A& o) const{
		if(val != o.val)
			return val < o.val;
		return idx < o.idx;
	}
};

struct B{
	int val, idx, freq;
	bool operator < (const B& o) const{
		if(freq != o.freq)
			return freq > o.freq;
		return idx < o.idx;
	}
};

A a[1010];
B b[1010];

int main(){
	int n, c;
	scanf("%d %d", &n, &c);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i].val);
		a[i].idx = i;
	}
	sort(a, a + n);
	int last = -1, cnt = -1;
	for(int i = 0; i < n; i++){
		if(a[i].val != last){
			cnt++;
			b[cnt].val = a[i].val;
			b[cnt].idx = a[i].idx;
			b[cnt].freq = 0;
		}
		b[cnt].freq++;
		last = a[i].val;
	}
	cnt++;
	sort(b, b + cnt);
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < b[i].freq; j++){
			printf("%d ", b[i].val);
		}
	}
    return 0;
}
/*
Test Cases :
Input : 

5 4
4 3 4 3 4

8 10
7 9 9 8 8 8 7 7
Output :

*/