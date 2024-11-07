// Print pattern of a pyramid using two loops. If the number of rows i.e, n is 5 then total number of rows contributing to form a pyramid is 10.
// example: if num = 5 then pattern shown below is printed:
// 5 
// 4 5
// 3 4 5
// 2 3 4 5
// 1 2 3 4 5
// 2 3 4 5
// 3 4 5
// 4 5
// 5

#include<stdio.h>
int main(){
    int n, k;
    // read number of rows
    printf("Enter the number: ");
    scanf("%d", &n);
    if(n>0){
      // upper right angled triangle
        for(int i=0; i<n; i++){
            for(int j=n-i; j<=n; j++){
                printf("%d ", j);
            }
            printf("\n");
        }
        // lower right angled triangle
        for(int i=0; i<n; i++){
            for(int j=i+2; j<=n; j++){
                printf("%d ", j);
            }
        printf("\n");
        }  
    }
    return 0;
}