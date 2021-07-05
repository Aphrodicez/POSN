/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Closest Pair of Point
    Status	: Accepted
*/
#include <bits/stdc++.h>
using namespace std;

void setIO();

struct POINT {
    double x, y;
};

bool cmpx(POINT a, POINT b) {
    return a.x < b.x;
}

bool cmpy(POINT a, POINT b) {
    return a.y < b.y;
}

POINT a[100010];

double euclideanDistance(POINT a, POINT b) {
    double dist = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return sqrt(dist);
}
double brute(int l, int r) {
    double mn = 2e9;
    if(l >= r)
        return mn;
    for(int i = l; i < r; i++) {
        for(int j = i + 1; j <= r; j++) {
            mn = min(mn, euclideanDistance(a[i], a[j]));
        }
    }
    return mn;
}

double stripClosestPair(vector <POINT> vec, double dis) {
    double mn = 2e9;
    for(int i = 0; i < vec.size() - 1; i++) {
        for(int j = i + 1; j < vec.size() && vec[j].y - vec[i].y < dis; j++) {
            mn = min(mn, euclideanDistance(vec[i], vec[j]));
        }
    }
    return mn;
}

double closestPair(int l, int r) {
    if(r - l + 1 <= 3) {
        return brute(l, r);
    }
    int mid = (l + r) / 2;
    int nextl = mid, nextr = mid;
    double mn = min(closestPair(l, mid), closestPair(mid + 1, r));
    vector <POINT> vec;
    for(int i = l; i <= r; i++) {
        if(abs(a[i].x - a[mid].x) < mn)
            vec.push_back(a[i]);
    }
    sort(vec.begin(), vec.end(), cmpy);
    mn = min(mn, stripClosestPair(vec, mn));
    return mn;
}

void solve() {
    int n;
    double r, d;
    cin >> n >> r >> d;
    double mn = 2e9;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + n + 1, cmpx);
    if((double)closestPair(1, n) < (double)(d + 2*r)) {
        cout << "N\n";
    }
    else {
        cout << "Y\n";
    }
}
int main() {
    setIO();
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}
void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}