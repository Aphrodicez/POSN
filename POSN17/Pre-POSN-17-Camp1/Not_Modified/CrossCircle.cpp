#include <bits/stdc++.h>
using namespace std;

struct A{
    int h, k, r;
};

bool isSamePoint(A a, A b){
    if((a.h == b.h) && (a.k == b.k))
        return true;
    return false;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    int q, ra2, rb2, d2, rarb2;
    A a, b;

    cin >> q;

    while(q--){
        cin >> a.h >> a.k >> a.r >> b.h >> b.k >> b.r;
        if(b.r > a.r)
            swap(b, a);
        d2 = (a.h - b.h) * (a.h - b.h) + (a.k - b.k) * (a.k - b.k);
        ra2 = a.r * a.r;
        rb2 = b.r * b.r;
        rarb2 = ra2 * rb2;
        if(4 * rarb2 < (ra2 + rb2 - d2) * (ra2 + rb2 - d2)){
            cout << "None\n";
        }
        else if((d2 - ra2 - rb2) * (d2 - ra2 - rb2) > 4*rarb2){
            cout << "None\n";
        }
        
        else if(((d2 - ra2 - rb2) * (d2 - ra2 - rb2) == 4*rarb2) && !isSamePoint(a, b)){
            cout << "One\n";
        }
        
        else if((4*rarb2 == (ra2 + rb2 - d2) * (ra2 + rb2 - d2)) && (a.r != b.r)){
            cout << "One\n";
        }
        
        else{
            cout << "More\n";
        }
        //cout << d2 << " " << ra2 << " " << rb2 << " " << 2*rarb2 << "\n";
    }

    return 0;
}