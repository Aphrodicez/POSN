/*
List of Primes for 1 to N
*/

#include <bits/stdc++.h>
using namespace std;

int prime[500010]; /// Array of Prime

int mark[500010]; /// Mark Possible Prime

int main(){
    int n;
    int ptr = 0; /// pointer of prime list
    scanf("%d", &n);
    if(n < 2){
        printf("No Prime List");
        return 0;
    }
    mark[2] = 1;
    prime[ptr] = 2;
    ptr++;

    for(int i = 3; i <= n; i+=2){
        mark[i] = 1;
        /// Mark Possible Prime
    }

    for(int i = 3; i <= sqrt(n); i+=2){
        if(mark[i]){
            /// Confirmed Prime
            prime[ptr] = i;
            ptr++;
            for(int j = i * i; j <= n; j += i){
                mark[j] = 0;
                /// Uncheck mutiple of primes
            }
        }
    }
    int i = sqrt(n) + 1;
    if(i % 2 == 0)
        i++;
    for(; i <= n; i += 2){
        if(mark[i]){
            /// Confirmed Prime after sqrt(n)
            prime[ptr] = i;
            ptr++;
        }
    }
    for(int i = 0; i < ptr; i++){
        printf("%d ", prime[i]);
    }
    return 0;
}