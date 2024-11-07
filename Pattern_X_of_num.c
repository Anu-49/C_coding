/* based on number of rows print the numbers in 'X' pattern i.e, 
  => if num = 6: 
    1    6
     2  5
      34 
      34
     2  5
    1    6 
  => if num = 5
    1   5
     2 4
      3
     2 4
    1   5     */

#include<stdio.h>
int main(){
    int num;
    // read the number of rows
    printf("Enter the number: ");
    scanf("%d", &num);
    for(int i=1; i<=num; i++){
        for(int j=1; j<=num; j++){
            if(i==j || i == (num+1)-j){
                printf("%d", j);
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}