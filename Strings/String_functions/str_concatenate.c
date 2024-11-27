/*  strcat() is a string function which takes two strings as input and adds up both the source string and the destination string.
The destination string is passed to the strcat() function first and then the source string is passed as arguments to the srtcat function.
The destination string should be a modifiable string in order to concatenate it with the source string. The source string should be a constant string.
<br>
 #include <string.h>
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);

This code concatenates two strings.
*/

#include<stdio.h>
#include<string.h>
char *my_str_cat(char *, const char *);
int main(){
        char src[100];
        const char dest[100];
        printf("Enter two strings : ");
        scanf("%[^\n] %[^\n]", src, dest);

        strcat(src, dest);
        printf("%s using built-in function\n", src);

        char *res = my_str_cat(src, dest);
        printf("%s using my_str_cat\n", res);

        return 0;
}
char *my_str_cat(char *src, const char *dest){
        int count =0, i;
        for(i=0; src[i]!='\0'; i++){
                count++;
        }
        for(i=count; dest[i] != '\0'; i++){
                src[i] = dest[i];
        }
        src[i] = '\0';
        return src;
}