/*
	Author	: ~Aphrodicez
	School	: RYW
	Lang    : CPP
	Algo	: Math
	Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

struct A{
    int h, k, r;
};

bool isSamePoint(A a, A b){
    if((a.h == b.h) && (a.k == b.k))
        return true;
    return false;
}

int main(){

    int q, ra2, rb2, d2, rarb2;
    A a, b;

    scanf("%d", &q);

    while(q--){

        scanf("%d %d %d %d %d %d", &a.h, &a.k, &a.r, &b.h, &b.k, &b.r);
        
        if(b.r > a.r)
            swap(b, a);
        d2 = (a.h - b.h) * (a.h - b.h) + (a.k - b.k) * (a.k - b.k);
        ra2 = a.r * a.r;
        rb2 = b.r * b.r;
        rarb2 = ra2 * rb2;
        if(4 * rarb2 < (ra2 + rb2 - d2) * (ra2 + rb2 - d2)){
            printf("None\n");
        }
        else if((d2 - ra2 - rb2) * (d2 - ra2 - rb2) > 4*rarb2){
            printf("None\n");
        }
        
        else if(((d2 - ra2 - rb2) * (d2 - ra2 - rb2) == 4*rarb2) && !isSamePoint(a, b)){
            printf("One\n");
        }
        
        else if((4*rarb2 == (ra2 + rb2 - d2) * (ra2 + rb2 - d2)) && (a.r != b.r)){
            printf("One\n");
        }
        
        else{
            printf("More\n");
        }
    }

    return 0;
}
/*
Test Cases :
Input : 

3
0 0 3 0 5 2
0 0 3 0 3 2
0 0 3 -10 -10 3

Output :

One
More
None

*/