#include <stdio.h>

int a[1100];

int main(){
    int n;
    int mn = 2e9, mx = -2e9; /// mn = min, mx = max;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        if(a[i] < mn){
            mn = a[i];
        }
        if(a[i] > mx){
            mx = a[i];
        }
    }
    printf("%d\n%d", mn, mx);
    return 0;
}