#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int ch = 0;
    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if(!val)
            ch = 1;
    }
    printf(ch ? "Have\n" : "Don't have\n");
}