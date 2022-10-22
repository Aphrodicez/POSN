#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e5 + 10;

struct A {
    int x, y;
    bool operator < (const A &o) const {
        if(x != o.x)
            return x < o.x;
        return y > o.y; // ห้ามมี if ที่ return สุดท้าย
    }
} a[MaxN];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d %d", &a[i].x, &a[i].y);
    
    sort(a + 1, (a + 1) + n);
    
    for(int i = 1; i <= n; i++)
        printf("%d %d\n", a[i].x, a[i].y);
    
    return 0;
}

/*
5
1 4
2 7
3 9
1 8
2 4
*/