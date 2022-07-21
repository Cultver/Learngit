//
// Created by ts on 2022/7/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void my_print(char *string);
void my_print2(char *string);
int main(){
   void my_print(char *string);
   void my_print2(char *string);
   char my_string[] = "hello there";
    my_print(my_string);
    my_print2(my_string);
   return 0;
}
void my_print(char *string){
    printf("The string is %s \n",string);
}
void my_print2(char *string){
    char *string2;
    int size,size2,i;
    size = strlen(string);
    size2 = size -1;
    string2 = (char *) malloc(size+1);
    for (int i = 0; i < size; ++i) {
        string2[size2-i] = string[i];
        string2[size+1] = '0';
        printf("The string printed backwand is %s\n",string2);
    }
}
