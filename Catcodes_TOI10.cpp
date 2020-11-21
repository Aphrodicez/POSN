/*
    TASK    : TOI10_Catcodes
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

#define HASH 500009

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

string s;

int testn, testlen, sum, i, j, temp, checker, testq, len, detected;

vector <int> ans;

int HASH_ARRAY[HASH], valueTELLER[100010], mark[100010];

int main(){
    setIO();
    cin >> testn >> testlen;
    for(i=1; i<=testn; i++){
        cin >> s;
        sum = (s[0] - '0');
        for(j=1; j<testlen; j++){
            sum <<= 1;
            sum += s[j] - '0';
        }
        /// hash
        temp = sum;
        temp %= HASH;
        checker = 1;
        while(HASH_ARRAY[temp] != 0){
            temp += checker;
            checker <<= 1;
            temp %= HASH;
        }
        HASH_ARRAY[temp] = i;
        valueTELLER[i] = sum;
    }

    cin >> testq;
    for(i=1; i<=testq; i++){
        detected = 0;
        ans.clear();
        cin >> len;
        cin >> s;
        if(testlen > len){
            cout << "OK\n";
            continue;
        }
        sum = s[0] - '0';
        for(j=1; j<testlen - 1; j++){
            sum <<= 1;
            sum += s[j] - '0';
        }

        for(j=testlen - 1; j < len ; j++){
            sum <<= 1;
            sum += s[j] - '0';
            ///cut with max - 1
            sum &= ((1<<testlen) - 1);
            temp = sum;
            temp %= HASH;
            checker = 1;
            while(HASH_ARRAY[temp] != 0){
                if(valueTELLER[HASH_ARRAY[temp]]==sum){
                    mark[HASH_ARRAY[temp]] = i;
                    detected = 1;
                    break;
                }
                else{
                    temp += checker;
                    checker <<= 1;
                    temp %= HASH;
                }
            }
        }
        if(detected==0){
            cout << "OK\n";
            continue;
        }
        for(j=1; j<=testn; j++){
            if(mark[j]==i)
                cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
5 5
01001
10110
11100
10100
11111
2
15
101010101010101
20
11110110011111000010
*/
