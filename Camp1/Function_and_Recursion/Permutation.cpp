#include <stdio.h>
#include <stdlib.h>

int mark[20], ans[20];

int cnt = 0;

int n, r, k;

void permu(int state) {
    if(state == r) {
        ++cnt;
        if(cnt == k) {
            for(int i = 0; i < state; i++) {
                printf("%d ", ans[i]);
            }
            exit(0);
        }
        return ;
    }
    for(int i = 1; i <= n; i++) {
        if(!mark[i]) {
            mark[i] = 1;
            ans[state] = i;
            permu(state + 1);
            mark[i] = 0;
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &r, &k);
    permu(0);
    return 0;
}
