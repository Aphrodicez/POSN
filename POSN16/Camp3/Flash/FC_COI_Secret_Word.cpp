/*
    TASK    : 0
    LANG    : CPP
    AUTHOR  : Aphrodicez
    SCHOOL  : RYW
*/
#include<bits/stdc++.h>
using namespace std;

void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

char a[1000010], b[1000010];

int KMP[1000010], jump[1000010];

char ans[1000010];

int main(){
    //setIO();
    int q, n, m, i, j, pt;
    scanf("%d", &q);
    while(q--){
        scanf(" %s %s", a + 1, b + 1);
        n = strlen(a+1), m = strlen(b+1);
        for(i=2, j=0; i <= m; i++){
            while(j > 0 && b[j+1] != b[i])
                j = KMP[j];
            if(b[j+1]==b[i])
                j++;
            KMP[i] = j;
        }
        for(i=1, j=0, pt = 0; i <= n; i++){
			while(j > 0 && b[j+1] != a[i])	
                j = KMP[j];
			if(b[j+1] == a[i])
                j++;
            pt++;
			ans[pt] = a[i];
			jump[pt] = j;
			if(j == m){
				pt-=m;
				j = jump[pt];
			}
        }
        ans[pt+1] = '\0';
        if(pt==0)
            printf("No COI Secret Code\n");
        else{
            /* code */
            printf("%s\n",ans+1);
        }
    }
    return 0;
}
/*
3
CodeCodecubeCodecubecute
Codecube
CodeCodecubecubeCodecube
Codecube
CasecaseSensitive191
case
*/