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
float calculate(float a, float b, float(*op)(float,float)){
    return op(a,b);
}
int main(){
    int choice;
    printf("Enter your choice : \n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    scanf("%d", &choice);
    float a, b, res;
    printf("Enter two numbers : ");
    scanf("%f %f", &a,&b);
    float (*fptr)(float,float)=NULL;
    switch(choice){
        case 1:
        fptr=add;
        break;
        case 2:
        fptr=sub;
        break;
        case 3:
        fptr=mul;
        break;
        case 4:
        if(b==0){
            printf("Error can't divide by zero!!");
            return 1;
        }
        fptr=div;
        break;
        default:
        printf("Enter correct choice\n exiting...\n");
        return 1;;
    }
    if(fptr!=NULL){
        res = calculate(a,b,fptr);
        printf("The result is %g\n",res);
    }
    return 0;
}