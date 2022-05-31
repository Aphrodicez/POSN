/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Lazy Segment Tree
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MaxN = 2e5 + 10;

int n;

struct LAZY {
    long long tree[4 * MaxN];
    long long lazy[4 * MaxN];

    void push_lazy(int now, int l, int r) {
        tree[now] += lazy[now] * (r - l + 1);
        if(l != r) {
            lazy[now * 2] += lazy[now];
            lazy[now * 2 + 1] += lazy[now];
        }
        lazy[now] = 0;
    }

    void update(int now, int ql, int qr, long long val, int l = 1, int r = n) {
        if(lazy[now])
            push_lazy(now, l, r);
        if(qr < l || r < ql)
            return ;
        if(ql <= l && r <= qr) {
            lazy[now] = val;
            push_lazy(now, l, r);
            return ;
        }
        long long mid = l + (r - l) / 2;
        update(now * 2, ql, qr, val, l, mid);
        update(now * 2 + 1, ql, qr, val, mid + 1, r);
        tree[now] = tree[now * 2] + tree[now * 2 + 1];
    }
    
    long long query(int now, int ql, int qr, int l = 1, int r = n) {
        if(lazy[now])
            push_lazy(now, l, r);
        if(qr < l || r < ql)
            return 0;
        if(ql <= l && r <= qr) {
            return tree[now];
        }
        int mid = l + (r - l) / 2;
        long long sum = query(now * 2, ql, qr, l, mid) + query(now * 2 + 1, ql, qr, mid + 1, r);
        return sum;
    }
};

LAZY seg;


int main() {
    scanf("%d", &n);
    int cnt = 1;
    for(int i = 1; i <= n; i++) {
        int opr;
        scanf("%d", &opr);
        if(opr == 1) {
            int r;
            long long val;
            scanf("%d %lld", &r, &val);
            seg.update(1, 1, r, val);
        }
        if(opr == 2) {
            long long val;
            scanf("%lld", &val);
            ++cnt;
            seg.update(1, cnt, cnt, val);
        }
        if(opr == 3) {
            seg.update(1, cnt, cnt, -seg.query(1, cnt, cnt));
            --cnt;
        }
        printf("%lld %d\n", seg.query(1, 1, cnt), cnt);
    }
    return 0;
}

/*
6
2 1
1 2 20
2 2
1 2 -3
3
3
*/