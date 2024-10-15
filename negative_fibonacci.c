
#include <stdio.h>
int main(){
  // read input integer until which the fibonacci series must be printed.
    int n1=0, n2=1, n3, num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if(num<0){
      // prints first two numbers of fibonacci series.
        printf("%d %d ", n1, n2);
        // starting from 0 the num is decremented until it reaches num.
        for(int i=0; i>=num; i--){
            n3 = n1-n2;
            printf("%d ", n3);
            n1=n2;
            n2=n3; 
            if(n3 <= num){
                break;
            }
        }
    }
    else if(num == 0){
        printf("0");
    }
    // if input is invalid gives error message.
    else{
        printf("Error : Invalid input");
    }
    return 0;
}


