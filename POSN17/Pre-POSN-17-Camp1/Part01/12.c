#include <stdio.h>

int main(){
    char c, type;
    scanf(" %c", &c);
    if(c >= 'A' && c <= 'Z'){
        type = 'A'; /// Big
    }
    else if(c >= 'a' && c <= 'z'){
        type = 'a'; /// Small
    }
    c -= type; /// Change to pos 0-25
    c += 2; /// Add 2 positions
    c %= 26; /// Reduce to pos 0-25 In Case Y -> A (24 -> 0)
    c += type; /// Change back to Original type

    printf("%c", c);
    return 0;
}