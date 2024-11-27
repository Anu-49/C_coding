/*  strcpy() is a string function which takes two strings as input and copies the source string to the destination string. The destination string is passed to the strcpy() function first and then the source string is passed as arguments to the srtcpy function.
The destination string should be a modifiable string in order to copy the source string into destination. The source string should be a constant string.
<br>
#include <string.h>
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);

This code copies a string into another string just like the builtin strcpy function. In order to verify our results, the results of both builtin function and my_str_cpy() function have been compared.
*/

#include<stdio.h>
#include<string.h>
char *my_str_cpy(char *, const char *);
int main(){
        const char src[100];
        printf("Enter the string : ");
        scanf("%[^\n]", src);

        char dest[100], des[100];

        strcpy(dest, src);
        printf("%s copied using builtin function\n", dest);
        printf("length is %ld\n", strlen(dest));

        my_str_cpy(des, src);
        printf("%s copied using my_str_cpy\n", des);
        printf("length is %ld\n", strlen(des));

        return 0;
}
char *my_str_cpy(char *des, const char *src){
        int i;
        for(i=0; src[i] != '\0'; i++){
                des[i] = src[i];
        }
        des[i] = '\0';
        return des;
}