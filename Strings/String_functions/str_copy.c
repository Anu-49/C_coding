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