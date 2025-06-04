#include<stdio.h>
float add(float a, float b){
    return a+b;
}
float sub(float a, float b){
    return a-b;
}
float mul(float a, float b){
    return a*b;
}
float div(float a, float b){
    return a/b;
}
int main(){
    int choice;
    printf("Enter your choice : \n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    scanf("%d", &choice);
    float a, b;
    printf("Enter two numbers : ");
    scanf("%f %f", &a,&b);
    float (*fptr)(float,float);
    switch(choice){
        case 1:
        fptr=add;
        printf("Sum is %g\n",fptr(a,b));
        break;
        case 2:
        fptr=sub;
        printf("Difference is %g\n",fptr(a,b));
        break;
        case 3:
        fptr=mul;
        printf("Result is %g\n",fptr(a,b));
        break;
        case 4:
        fptr=div;
        printf("Quotient is %g\n",fptr(a,b));
        break;
        default:
        printf("Enter correct choice\n exiting...\n");
        break;

    }
    return 0;
}