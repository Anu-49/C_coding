#include<stdio.h>
int main(){
  // based on age the discount is given, so read age input from the user.
    int age;
    printf("Enter the age : ");
    scanf("%d", &age);
// declare a variable (i.e, tp) to store original ticket price with 0% discount
    float tp = 100;
    // NO price for kids 
    if (age<5){
        printf("Children under 5 years old get in free!\n");
        printf("Ticket price: Rs. %.2f", tp * 0);
    }
    // 50% discount offer for children between age 5 & 12
    else if(age>=5 && age<=12){
        printf("Ticket price: Rs. %.2f", tp*0.5);
    }
    // NO discount for people between age 12 & 65
    else if(age>12 && age<65){
        printf("Ticket price: Rs. %.2f", tp);
    }
    // 20% discount offer for elderly people of age 65 and above
    else if (age>=65){
        printf("Ticket price: Rs. %.2f", tp*0.8);
    }
    return 0;
}