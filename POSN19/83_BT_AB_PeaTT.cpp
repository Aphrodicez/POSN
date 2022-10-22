#include <bits/stdc++.h>
using namespace std;

char s[100010];
queue <int> qu;

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        int k;
        scanf(" %s %d", s + 1, &k);
        int ans = 0;
        int before_st = 0;
        int len = strlen(s + 1);
        for(int i = 1; i <= len; i++) {
            if(s[i] == 'B') {
                qu.push(i);
            }
            while(qu.size() > k) {
                before_st = qu.front();
                qu.pop();
            }
            ans = max(ans, i - before_st); // i - before_start = จำนวนตัวตั้งแต่ st ถึง i
        }
        printf("%d\n", ans);
        while(!qu.empty())
            qu.pop();
    }
    return 0;
}

/*
2
AAABBBAAAAB 2
BBAABBAAABAABBBAAAA 3
*/