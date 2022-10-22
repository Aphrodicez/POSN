#include <stdio.h>
#include <math.h>

int main() {
    int q;
    scanf("%d", &q);
    while(q--) {
        double hs, ks, rmin, hb, kb, rmax;
        scanf("%lf %lf %lf %lf %lf %lf", &hs, &ks, &rmin, &hb, &kb, &rmax);
        double dist = sqrt((hs - hb) * (hs - hb) + (ks - kb) * (ks - kb)); // ระยะห่างระหว่างจุดศูนย์กลางวงกลม

        if(rmin > rmax) {
            // สลับค่า rmin กับ rmax ถ้า rmin > rmax
            double tmp = rmin;
            rmin = rmax;
            rmax = tmp;
        }

        if(dist == 0) {
            if(rmax == rmin)
                printf("More\n"); // (1) วงกลมเดียวกัน
            else
                printf("None\n"); // (2) วงแหวน
        }
        else if(rmax == dist) {
            printf("More\n"); // (3) จุดศูนย์กลางวงกลมเล็กอยู่บนเส้นรอบวงกลมใหญ่
        }
        else if(rmax < dist) {
            if(rmin + rmax == dist)
                printf("One\n"); // (4) สัมผัสกันนอกวงใหญ่
            else if(rmin + rmax > dist)
                printf("More\n"); // (5) ตัดกันมากกว่า 1 จุด โดยที่จุดศูนย์กลางวงกลมเล็กอยู่นอกวงกลมใหญ่
            else if(rmin + rmax < dist)
                printf("None\n"); // (6) อยู่ห่างกันมาก ไม่มีจุดที่ตัดกัน
        }
        else if(rmax > dist) {
            if(rmax == rmin + dist)
                printf("One\n"); // (7) สัมผัสกันในวงใหญ่
            else if(dist + rmin > rmax)
                printf("More\n"); // (8) ตัดกันมากกว่า 1 จุด โดยที่จุดศูนย์กลางวงกลมเล็กอยู่ในวงกลมใหญ่
            else if(dist + rmin < rmax)
                printf("None\n"); // (9) วงกลมเล็กอยู่ในวงกลมใหญ่ โดยไม่มีจุดที่ตัดกัน
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