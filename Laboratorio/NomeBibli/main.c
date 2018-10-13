#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char Nome[20][20];
    int i=0;


    do{
        scanf("%c", *(Nome+i));
        if (**(Nome+i) == ' ') i++;
    } while (**(Nome+i) != EOF);

    do{
        printf("%s", *(Nome+i));
        if (**(Nome+i) == ' ') i++;
    } while (**(Nome+i) != EOF);











    return 0;
}
