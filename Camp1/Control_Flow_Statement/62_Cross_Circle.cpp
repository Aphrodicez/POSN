#include <stdio.h>
#include <math.h>

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        double hs, ks, rmin, hb, kb, rmax;
        scanf("%lf %lf %lf %lf %lf %lf", &hs, &ks, &rmin, &hb, &kb, &rmax);
        double dist = sqrt((hs - hb) * (hs - hb) + (ks - kb) * (ks - kb)); // Distance between the Centres

        if(rmin > rmax) {
            // Swap rmin and rmax if rmin > rmax
            double tmp = rmin;
            rmin = rmax;
            rmax = tmp;
        }

        if(dist == 0) {
            if(rmax == rmin)
                printf("More\n"); // (1) Same circle
            else
                printf("None\n"); // (2) Ring
        }
        else if(rmax == dist) {
            printf("More\n"); // (3) Small circle's centre on big circle's circumference
        }
        else if(rmax < dist) {
            if(rmin + rmax == dist)
                printf("One\n"); // (4) 
            else if(rmin + rmax > dist)
                printf("More\n"); // (5)
            else if(rmin + rmax < dist)
                printf("None\n"); // (6)
        }
        else if(rmax > dist) {
            if(rmax == rmin + dist)
                printf("One\n"); // (7)
            else if(dist + rmin > rmax)
                printf("More\n"); // (8)
            else if(dist + rmin < rmax)
                printf("None\n"); // (9)
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