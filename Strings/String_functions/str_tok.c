/*
The strtok() function breaks a string into a sequence of zero or more nonempty tokens. On the first call to strtok(), the string to be parsed should be specified in str. In each subsequent call that should  parse  the same string, str must be NULL. The  delim  argument specifies  a  set of bytes that delimit the tokens in the parsed string.  The caller may specify different strings in delim in successive calls that parse the same string.
Each call to strtok() returns a pointer to a null-terminated string containing the next token. This string does not include the delimiting byte. If no more tokens are found, strtok() returns NULL.
<br>
#include <string.h>
char *strtok(char *str, const char *delim);
char *strtok_r(char *str, const char *delim, char **saveptr);
*/
       
#include <stdio.h>
#include <string.h>

char *my_strtok(char str[], const char delim[]);

int main()
{
    char str[50], delim[50];
    
    printf("Enter the string  : ");
    scanf("%s", str);
 
    printf("Enter the delimeter : ");
    scanf("\n%s", delim);
    
    char *token = my_strtok(str, delim);
    printf("Tokens :\n");
    
    while (token)
    {
        printf("%s\n", token);
        token = my_strtok(NULL, delim);
    }
}
char *my_strtok(char str[], const char delim[]){
    static char *ch = NULL;
    if(str!=NULL){
        ch = str;
    }
    if(ch==NULL){
        return NULL;
    }
    while(*ch && strchr(delim, *ch)){
        ch++;
    }
    if(*ch == '\0'){
        return NULL;
    }
    char *res = ch;
    while(*ch){
        if(strchr(delim, *ch)){
            *ch = '\0';
            ch++;
            break;
        }
        ch++;
    }
    while(*ch && strchr(delim, *ch)){
        ch++;
    }
    return res;
}