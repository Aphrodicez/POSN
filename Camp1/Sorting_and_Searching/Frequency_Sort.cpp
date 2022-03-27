/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Sorting
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

struct A {
    int idx, val, freq;
    bool operator < (const A &o) const {
        if(freq != o.freq)
            return freq > o.freq;
        return idx < o.idx;
    }
};

const int MaxN = 1e3 + 10;

int a[MaxN];
A sorted[MaxN];

map <int, int> mp;

int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        mp[a[i]]++;
    }
    for(int i = 1; i <= n; i++) {
        sorted[i] = {i, a[i], mp[a[i]]}; 
                 // {idx, val, freq}
    }
    sort((sorted + 1), (sorted + 1) + n);
    for(int i = 1; i <= n; i++) {
        while(mp[sorted[i].val]--)
            printf("%d ", sorted[i].val);
        mp[sorted[i].val] = 0;
    }
    return 0;
}

/*
5 4
4 3 4 3 4

8 10
7 9 9 8 8 8 7 7
*/