#include <bits/stdc++.h>
using namespace std;

char s[10000];

int main(){
//    ios_base :: sync_with_stdio(0);
//    cin.tie(0);
    bool ch = false;
    int q, len;
    char *ptr;
    
    scanf("%d\n", &q);

    while(q--){
        ch = false;
        gets(s);
        len = strlen(s);
        if(s[len-1] == '\r')
            s[len-1] = '\0';
        ptr = strtok(s, " ");
        while(ptr != NULL){              
            if(ptr[0] == 'm' && (strlen(ptr)%4==0)){            
                ch = true;
                for(int i = 0; i < strlen(ptr); i += 4){
                    if(strncmp(ptr + i, "meow", 4)){
                        ch = false;
                        break;
                    }
                }
            }
            if(ch){
                printf("YES\n");
                break;
            }
            ptr = strtok(NULL, " ");
        }
        if(ch)
            continue;
        printf("NO\n");
    }

    return 0;
}
/*
3
iku iku iku iku meowmeow
meowwwwwwwwwww itte itte itte
mameow meow shinu shinu shinu
*/