#include<stdio.h>
int main(){
  // read input char from the user
    char letter;
    printf("Enter a character: ");
    scanf("%c", &letter);
    // if-else checks if the character entered by the user is uppercase, lowercase, digit or none
    if((letter >= 'A') && (letter <='Z')){
        printf("Character is Uppercase");
    }
    else if((letter >= 'a') && (letter <='z')){
        printf("Character is Lowercase");
    }
    else if((letter >= '0') && (letter <= '9')){
        printf("Character is a digit");
    }
    else{
        printf("Not an alphabet or digit");
    }
    return 0;
}