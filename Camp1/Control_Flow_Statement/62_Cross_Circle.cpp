#include <stdio.h>
#include <math.h>

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        double hs, ks, rs, hb, kb, rb;
        scanf("%lf %lf %lf %lf %lf %lf", &hs, &ks, &rs, &hb, &kb, &rb);
        double dist = sqrt((hs - hb) * (hs - hb) + (ks - kb) * (ks - kb));
        if(rs > rb) {
            double tmp = rs;
            rs = rb;
            rb = tmp;
        }
        if(rb <= dist) {
            if(rs + rb == dist)
                printf("One\n");
            else if(rs + rb > dist)
                printf("More\n");
            else if(rs + rb < dist)
                printf("None\n");
        }
        else {
            if(rb == rs + dist)
                printf("One\n");
            else if(dist + rs > rb)
                printf("More\n");
            else if(dist + rs < rb)
                printf("None\n");
        }
    }
    return 0;
}

/*
3
0 0 3 0 5 2
0 0 3 0 3 2
0 0 3 -10 -10 3
*/