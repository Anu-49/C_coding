#include<stdio.h>
int main(){
    // declaring variables of float datatype.
    float fahren, celsius;
    // take input temperature in fahrenheit from the user.
    printf("Enter the temperature in fahrenheit: ");
    scanf("%f", &fahren);

    // to convert fahren to celsius subtract 32 from fahren and multiply by 5/9.
    celsius = ((fahren-32) * 5/9);
    printf("%f", celsius);
    return 0;
}