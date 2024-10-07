// declare preprocessor directive, that tells the compiler to include the standard input output libraray i.e, stdio.h before compilimng the code.
#include<stdio.h>
int main(){
  // declare a variable of int datatype to store value taken from the user.
  int num;
  // instruct user to print a number.
  printf("Enter a number: ");
  // read the value entered by the user.
  scanf("%d", &num);

  // The logic to find a number is even or odd is by checking whether it is divisible by 2 completely or not. Hence use if-else conditional statement.
  if(num % 2 ==0){
    printf("%d number entered is an even number.", num);
  }
  else{
    printf("%d number entered is an odd number.", num);
  }
  return 0;
}