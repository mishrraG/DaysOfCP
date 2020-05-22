#include<stdio.h>
int main(){
    int n ;
    scanf("%d" , &n);
    printf((n%4 && n%7 && n%47 && n%74 && n%477)?"NO":"YES");
    return 0;
}