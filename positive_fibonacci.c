#include<stdio.h>
int main(){
  // read input integer until which the fibonacci series must be printed.
    int n1=0, n2=1, num, n3;
    printf("Enter a number: ");
    scanf("%d", &num);
    // prints first two numbers of fibonacci series.
    printf("%d %d ", n1, n2);

    // starting from 1 the num is incremented until it reaches num.
    if(num>0){
        for(int i=1; i<=num; i++){
            n3 = n1+n2;
            printf("%d ", n3);
            n1 = n2;
            n2 = n3;
            if(num <= n3){
                break;
            }
        }
    }
    // if the input is invalid number or any other character then error message is printed.
    else{
        printf("Invalid input");
    }
    return 0;
}