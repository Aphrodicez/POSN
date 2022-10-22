/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Modulo
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

char s[1010];

int main(){

    int q, n, k, i, j, c;

    scanf("%d", &q);
    
    while(q--){
        scanf(" %s", s);
        scanf("%d %d", &n, &k);
        k %= n;
        k = n - k; // เปลี่ยนทิศการหมุน
        for(int j = 0; j < strlen(s); j++){
            c = j - (j % n); // ตัวแรกของชุด 
            i = j % n; // ตำแหน่งที่เท่าไหร่ของชุดนี้
            i += k; // เอาตัวที่อยู่ขวาเรา k ตัว มา
            i %= n;
            printf("%c", s[c + i]);
        }
        printf("\n");
    }

    return 0;
}
/*
2
abcdefghi
3 1
abcdefghi
3 2
*/