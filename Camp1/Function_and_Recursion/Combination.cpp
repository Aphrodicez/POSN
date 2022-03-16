#include <stdio.h>

int ans[20];

int cnt = 0;

int n, r, k;

void combi(int state, int last) {
    if(state == r) {
        ++cnt;
        if(cnt == k) {
            for(int i = 0; i < state; i++) {
                printf("%d ", ans[i]);
            }
        }
        return ;
    }
    for(int i = last + 1; i <= n; i++) {
        ans[state] = i;
        combi(state + 1, i);
    }
}

int main()
{
    scanf("%d %d %d", &n, &r, &k);
    combi(0, 0);
    return 0;
}
