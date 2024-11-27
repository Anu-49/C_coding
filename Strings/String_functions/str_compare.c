#include<stdio.h>
#include<string.h>
int my_str_cmp(char * , char *);
int main(){
        char str1[100], str2[100];
        printf("Enter two strings : ");
        scanf("%[^\n] %[^\n]", str1, str2);
        int builtin;
        builtin = strcmp(str1, str2);
        printf("After comparison using built-in function : %d\n", builtin);
        if(builtin==0){
                printf("Strings are equal\n");
        }
        else{
                printf("Strings are not equal\n");
        }
        int res;
        res = my_str_cmp(str1, str2);
        printf("After comparison using my_str_cmp : %d\n", res);
        if(res==0){
                printf("Strings are equal\n");
        }
        else{
                printf("Strings are not equal\n");
        }
        return 0;
}
int my_str_cmp(char str1[], char str2[]){
            int integer = 0;
            int i=0;
            while(str1[i] != '\0' || str2[i] != '\0'){
                    if(str1[i]!=str2[i]){
                            integer = str1[i]-str2[i];
                            break;
                    }
                    i++;
            }
            return integer;
}