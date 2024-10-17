#include<stdio.h>
#include<locale.h>

int main(){
    double num=84.5;
    setlocale(LC_ALL,"de_DE.UTF-8");
    printf("%f",num);
    return 0;
}
