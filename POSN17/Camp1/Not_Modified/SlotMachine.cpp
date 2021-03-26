#include <bits/stdc++.h>
using namespace std;

int a[20][10];

bool cmp (vector <int> &vec){
    int num = vec[0];
    for(int x: vec){
        if(x != num){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
    int n; 

    vector <int> vec;
    vector <vector <int>> ans;

    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 5; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                for(int l = 1; l <= n; l++){
                    for(int m = 1; m <= n; m++){
                        vec.assign({a[i][1], a[j][2], a[k][3], a[l][4], a[m][5]});
                        if(cmp(vec)){
                            ans.push_back({i, j, k, l, m});
                        }
                    }
                }
            }
        }
    }

    cout << ans.size() << "\n";

    for(auto &vecc: ans){
        for(auto &x: vecc){
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
/*
4
1 3 1 3 1
3 1 3 1 2
2 2 2 2 1
3 4 4 4 3
*/