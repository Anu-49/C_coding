/*  strclen() is a string function which calculates the length of a string as and returns the length of the string as an integer output, excluding the terminating null byte ('\0').
The strlen() function returns the number of bytes in the string pointed to by s(base address of a string).
<br>
 #include <string.h>
size_t strlen(const char *s);
*/

#include<stdio.h>
#include<string.h>
int my_str_len(char *);
int main(){
        char str[100];
        printf("Enter the string : ");
        scanf("%[^\n]", str);

        int num, res;
        num= strlen(str);
        printf("length of the string using builtin function is %d\n", num);

        res = my_str_len(str);
        printf("length of the string using my_str_len is %d\n", res);

        return 0;
}
int my_str_len(char *str){
        int count;
        for(int i=0; str[i] != '\0'; i++){
                count++;
        }
        return count;
}