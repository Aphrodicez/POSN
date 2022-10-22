#include <bits/stdc++.h>
using namespace std;

const int MaxN = 1e3 + 10;

struct A {
    int idx, val, freq;
    bool operator < (const A &o) const {
        if(freq != o.freq)
            return freq > o.freq;
        return idx < o.idx;
    }
};

A a[MaxN];

map <int, int> mp;

int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i].val);
        a[i].idx = i;
        mp[a[i].val]++;
    }
    for(int i = 1; i <= n; i++)
        a[i].freq = mp[a[i].val];
    
    sort(a + 1, (a + 1) + n);
    for(int i = 1; i <= n; i++) {
        while(mp[a[i].val]--)
            printf("%d ", a[i].val);
        
        mp[a[i].val] = 0;
    }
    return 0;
}

/*
5 4
4 3 4 3 4

8 10
7 9 9 8 8 8 7 7
*/