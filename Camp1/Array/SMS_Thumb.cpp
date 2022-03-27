/*
    Author	: ~Aphrodicez
    Center	: BUU
    Lang	: CPP
    Algo	: Modulo
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

char a[1010];

int mod[] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4}; /// 0 -> 9

char add[] = {0, 0, 'A', 'D', 'G', 'J', 'M', 'P', 'T', 'W'}; /// 0 -> 9

int main(){
    int n, i, j, num, times, cnt = 0, di, dj;
    scanf("%d", &n);
    n--;
    scanf("%d %d", &num, &times);
    i = (num-1) / 3;
    j = (num-1) % 3;
    if(num != 1){
        times--;
        times %= mod[num];
        a[cnt] = times + add[num];
        cnt++;
    }
    while(n--){
        scanf("%d %d %d", &dj, &di, &times);
        i += di;
        j += dj;
        i = max(i, 0);
        i = min(i, 2);
        j = max(j, 0);
        j = min(j, 2);
        num = (i * 3) + j + 1;
        if(num == 1){
            cnt -= times;
            cnt = max(cnt, 0);
            continue;
        }
        times--;
        times %= mod[num];
        a[cnt] = times + add[num];
        cnt++;
    }
    if(cnt == 0){
        printf("null");
        return 0;
    }
    for(int i = 0; i < cnt; i++){
        printf("%c", a[i]);
    }
    return 0;
}

/*
4
5 3
1 0 3
-1 1 3
1 -2 2

2
9 6
-2 -2 5

5
3 3
0 0 2
-2 0 1
2 1 3
0 1 2
*/