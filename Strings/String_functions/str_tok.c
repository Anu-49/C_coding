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