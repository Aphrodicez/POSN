#include <bits/stdc++.h>
using namespace std;

char phone[10][5];

vector <char> ans;

void press(int i, int j, int times){
    int button = i * 3 + j + 1, type;
    if(button == 1){
        while(times-- && !ans.empty()){
            ans.pop_back();
        }
    }
    else{
        if(button == 7 || button == 9)
            type = 4;
        else
            type = 3;
        times = ((times - 1) % type) + 1;
        ans.push_back(phone[button][times]);
    }
}

int main(){
    //ios_base :: sync_with_stdio(0);
    //cin.tie(0);
    
    int n, button, times, nowi, nowj, di, dj;
    char alphabet = 0;

    for(int i = 2; i <= 9; i++){
        if(i == 7 || i == 9){
            times = 4;
        }
        else{
            times = 3;
        }
        for(int j = 1; j <= times; j++, alphabet++){
            phone[i][j] = char(alphabet + 'A'); 
        }
    }

    cin >> n;
    cin >> button >> times;

    nowi = (button - 1) / 3;
    nowj = (button - 1) % 3;

    n--;

    press(nowi, nowj, times);

    while(n--){    
        /*
        for(char &x : ans){
            cout << x;
        }
        cout << "\n";
        */
        cin >> dj >> di >> times;
        nowi += di;
        nowj += dj;
        //cout << nowi << " " << nowj << " " << times << "\n";
        nowi = max(nowi, 0);
        nowi = min(nowi, 2);
        nowj = max(nowj, 0);
        nowj = min(nowj, 2);
        press(nowi, nowj, times);
        
    }

    if(ans.empty()){
        cout << "null";
    }

    for(char &x : ans){
        cout << x;
    }

    return 0;
}
/*
4
5 3
1 0 3
-1 1 3
1 -2 2
*/
/*
2
9 6
-2 -2 5
*/
/*
5
3 3
0 0 2
-2 0 1
2 1 3
0 1 2
*/