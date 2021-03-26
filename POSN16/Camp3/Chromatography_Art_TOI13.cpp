/*
    TASK    : Chromatography_Art_TOI13
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

#define pb push_back

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int tree[1000010];

struct A{
    int idx, h, val, swp;
    bool operator < (const A& o) const{
        if(idx != o.idx)
            return idx < o.idx;
        return swp < o.swp;
    }
};

void update(int idx, int val){
    while(idx <= 1000003){
        tree[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx){
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= idx & -idx;
    }
    return sum;
}
int n, target, val, h, w, idx, i, l, r, mid, en, ans, sum;

vector <A> vec;

int main(){
    scanf("%d %d", &n, &target);
    for(i=1; i<=n; i++){
        scanf("%d %d %d %d", &idx, &h, &w, &val);
        vec.pb({idx, h, val, 1});
        vec.pb({idx + w, h, val*-1, -1});
    }    
    sort(vec.begin(), vec.end());
    for(i=0; i<vec.size() - 1; i++){
        while(i+1 < vec.size() && vec[i+1].idx==vec[i].idx){
            update(1, vec[i].val);
            update(vec[i].h + 1, -1 * vec[i].val);
            i++;
        }
        update(1, vec[i].val);
        update(vec[i].h + 1, -1*vec[i].val);
        l = 1, r = 1e6;
        while(l < r){
            mid = (l + r) / 2;
            if(query(mid) >= target)
                l = mid + 1;
            else
                r = mid;
        }
        en = l;
        l = 1, r = 1e6;
        while (l < r){
            mid = (l + r) / 2;
            if(query(mid) > target)
                l = mid + 1;
            else
                r = mid;
        }
        ans += (en-l) * (vec[i+1].idx-vec[i].idx);     
    }
    printf("%d", ans);
    return 0;
}
/*
3 3
1 1 4 1
2 2 2 2
3 3 1 3
*/