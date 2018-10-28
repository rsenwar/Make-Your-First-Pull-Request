//rotates alphabets in a word left or right by number of "key" entered by user.
//example //hello //rotate left by 2 //llohe // rotate right by 2 // lohel

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int main (){
    char sent [1000];
    gets(sent);
    int z = strlen(sent); //length of string
    int i =0;
    printf("\nEnter Key: ");
    int key = 0;
    scanf("%d", &key);
    int catalyst =0;
    char dir ='a' ;

    printf("Enter 'l' for left 'r' for right\n");
    scanf(" %c", &dir);

//re-enter key if key>=z
    while (key>=z){
        printf("re-enter key: ");
        scanf("%d", &key);
    }
//for left
        if (dir == 'l'){
            for (i=0; i<z ; i++){
                int move = i + key;
                if (move<z){
                   printf("%c", sent[move]);
                }
                else{
                        printf("%c", sent[catalyst]);
                        catalyst++;
                }
            }
        }
//for right
        else if (dir == 'r'){
            int move = z - key;
            while (move<z){
               printf("%c", sent[move]);
               move++;
            }
            if (move>=z){
            for (catalyst = 0; catalyst<z-key; ){
                printf("%c", sent[catalyst]);
                catalyst++;
            }
            }
            printf("\n");
        }

        else {
          printf("Please enter 'l' ot 'r'. TRY AGAIN.");
            return 0;
        }
}
