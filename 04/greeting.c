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
//    for (int i = 0; i < strlen(my_string); ++i) {
//        printf("%c\n",my_string[i]);
//    }
    my_print(my_string);
    my_print2(my_string);
   return 0;
}
void my_print(char *string){
    printf("The string is %s \n",string);
}
void my_print2(char *string){
    char *string2;
    int size,size2;//11 550
    size = strlen(string);//11
    //printf("size=%d\n",size);
    size2 = size -1;//11 550
    string2 = (char *) malloc(size+1);//
    for (int i = 0; i < size; ++i) {
        string2[size2-i] = string[i];// 11   0**10  1**9  2**8 3*7 4** 6 5*5 6*4 7*38*29*1 10
    }
    string2[size+1] = '\0';//12*
    for (int i = 0; i < size; ++i) {
        printf("The string printed backwand is %s\n",string2);
    }

}