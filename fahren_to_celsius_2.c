#include<stdio.h>
int main(){
    float celsius;
    int fahrenheit;
    // take input temperature in fahrenheit from the user.
    printf("Enter the temperature in fahrenheit: ");
    scanf("%d", &fahrenheit);
    // explicit type conversion of fahrenheit from int to float.
    celsius = (((float)fahrenheit-32)*5/9);
    printf("%f", celsius);
}