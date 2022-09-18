#include <stdio.h>

int main(){
    int a = 0;
    int primeFlag = 1;

    printf("Enter number:\n");
    scanf("%i", &a);

    for(int i = 2; i < a; i = i + 1){
        if((a % i) == 0){
            primeFlag = 0;
            break;
        }
    }

    if(primeFlag == 1){
        printf("prime number\n");
    }else{
        printf("not prime number\n");
    }

    return 0;
}