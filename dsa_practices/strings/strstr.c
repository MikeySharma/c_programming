//Implement StrStr Function
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Hello! This is Mikey Sharma.";
    char str2[] = "This";
    char *p;

    p = strstr(str1, str2);

    if(p){
        printf("The Content \"%s\" is available in \"%s\".\n\"%s\".\n",str2, str1, p);
    }else{
        printf("Content Not Found!\n");
    }
    return 0;
}