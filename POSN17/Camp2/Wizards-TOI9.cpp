/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang    : CPP
    Algo	: Hash Table
    Status	: Accepted
*/

#include <bits/stdc++.h>
using namespace std;

const int MxN = 1510;

#define hashsize 5000011

int hashtable[hashsize], keep[2][hashsize];

int x[4][MxN], y[4][MxN];

int makeKey(int sumx, int sumy) {
    return ((sumx + (3*sumy) % hashsize) % hashsize + hashsize) % hashsize;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int ansx, ansy, n, i, j, sumx, sumy, key, value;
	cin >> ansx >> ansy >> n;
	for(i = 0; i < 4; i++){
        for(j = 0; j < n; j++){
            cin >> x[i][j] >> y[i][j];
        }
	}
    for(i = 0;i < n; i++){           // Earth
        for(j = 0;j < n; j++){       // Water
            sumx = x[0][i] + x[1][j];
            sumy = y[0][i] + y[1][j];
            key = makeKey(sumx, sumy);
            while(hashtable[key]!=0){
                key++;
                key %= hashsize;
            }
            hashtable[key] = (1500*i) + j + 1;
            keep[0][key] = sumx, keep[1][key] = sumy;
        }
    }
    for(i=0;i<n;i++){           // Wind
        for(j=0;j<n;j++){       // Fire
            sumx = ansx - (x[2][i]+x[3][j]), sumy = ansy - (y[2][i]+y[3][j]);
            key = makeKey(sumx, sumy); //Hash Function
            while(hashtable[key]!=0){
                if(keep[0][key]==sumx&&keep[1][key]==sumy){
                    value = hashtable[key] - 1;
                    cout << x[0][value/1500] << " " << y[0][value/1500] << endl;
                    cout << x[1][value%1500] << " " << y[1][value%1500] << endl;
                    cout << x[2][i] << " " << y[2][i] << endl;
                    cout << x[3][j] << " " << y[3][j] << endl;
                    return 0;
                }
                key++;
                key %= hashsize;
            }
        }
    }
    return 0;
}