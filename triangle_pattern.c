// Print a triangle of numbers with spaces inside triangle as shown:
// if number of rows is 4 then:
//  1  2  3  4 
//  5     6
//  7  8
//  9
#include<stdio.h>
int main(){
    int rows, k=1;
    printf("Enter the number: ");
    scanf("%d", &rows);
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=rows; j++){
            if(i==1 || j==1 || i==(rows+1)-j){
                printf(" %d ", k);
                k++;
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }
}