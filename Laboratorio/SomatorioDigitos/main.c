#include <stdio.h>
#include <stdlib.h>

int main(){
    int a;
    int Res=0;

    scanf("%d", &a);

    while(a>0){
    Res = Res + a%10;
    a = a/10;
    }

    printf("%d", Res);
    return 0;
}
