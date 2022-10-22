#include <bits/stdc++.h>
using namespace std;

vector <int> ans;

int main() {
    int n;
    scanf("%d", &n);
    if(n < 0) {
        printf("-1");
        return 0;
    }
    if(n == 0) {
        printf("10");
        return 0;
    }
    if(n <= 9) {
        printf("%d", n);
        return 0;
    }
    for(int i = 9; i >= 2; i--) { // ตัวหารมาก จำนวนหลักคำตอบน้อย
        while(n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
    }
    if(n > 1) { // ตัวประกอบเฉพาะ มีมากกว่าเลขโดด จึงทำไม่ได้
        printf("-1");
        return 0;
    }
    sort(ans.begin(), ans.end()); // ให้เลขเรียงตำแหน่งจากน้อยไปมาก
    for(auto x : ans) { // วน x ไปทุกตัวใน ans
        printf("%d", x);
    }
    return 0;
}

/*
10
12
13
*/