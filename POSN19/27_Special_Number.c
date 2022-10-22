#include <stdio.h>
#include <math.h> // pow()
#include <string.h>
#include <stdlib.h> // atoi()

char s[10];

int main() {
    int q = 5;
    while(q--) {
        scanf(" %s", s + 1);
        int len = strlen(s + 1);
        int sum = 0;
        int i;
        for(i = 1; i <= len; i++) {
            sum += pow((s[i] - '0'), i);
            // s[i] - '0' เป็นการแปลง char '0' ถึง '9' ให้เป็น int
            // โดยการนำ ascii code ของ char นั้น ลบด้วย ascii code ของ char '0'
            // เช่น '1' - '0' = 49 - 48 = 1
        }
        int n = atoi(s + 1); // แปลง string s เป็น int
        if(sum == n)
            printf("Y");
        else
            printf("N");

    }
    return 0;
}