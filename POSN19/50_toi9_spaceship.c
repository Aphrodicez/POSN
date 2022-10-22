#include <stdio.h>

int x[20], y[20], z[20];
int M[20], K[20], C[20];

int visited[20];

int n, m;

int ans = 2e9;

int cost(int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) + (z[i] - z[j]) * (z[i] - z[j]);
}

void play(int now, int _M, int _K, int _C, int sum) {
    if(ans < sum) // ไม่มีทางได้ค่า cost น้อยกว่า ans แล้ว
        return ;
    if(_M >= n && _K >= n && _C >= n) { // Base Case ได้ของครบ
        if(ans > sum)
            ans = sum;
        return ;
    }
    int i;
    for(i = 1; i <= m; i++) {
        if(visited[i]) // เคยไปร้านนี้แล้ว
            continue;
        visited[i] = 1; // Mark ว่า เคยไปร้าน i มาแล้ว
        play(i, _M + M[i], _K + K[i], _C + C[i], sum + cost(now, i));
        visited[i] = 0; // Backtrack ว่าไม่เคยไปร้าน i
    }
}

int main() {
    scanf("%d", &n);
    scanf("%d %d %d", &x[0], &y[0], &z[0]);
    scanf("%d", &m);
    int i;
    for(i = 1; i <= m; i++) {
        scanf("%d %d %d", &x[i], &y[i], &z[i]);
        scanf("%d %d %d", &M[i], &K[i], &C[i]);
    }
    play(0, 0, 0, 0, 0);
    printf("%d", ans);
    return 0;
}