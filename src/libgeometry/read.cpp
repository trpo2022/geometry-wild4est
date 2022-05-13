#include <libgeometry/read.h>
#include <libgeometry/P_and_S.h>

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <cstring>



int read(char str[]){
    puts(str);
    int i=0;
    int cheking_word = 0;
    char chek[10];
    while (cheking_word == 0){
        if (str[i]==')'){
            int column = i + 3;
            for (int l=0; l<column; l++){
                printf(" ");
            }
            printf("^\n");
            printf("1.Error at column %d: expected '('", column);
            cheking_word = 1;
        }else if (str[i]=='('){
            cheking_word = 1;
        }else{
            chek[i]=str[i];
            i++;
        }
    }

    chek[i] = ' ';
    //Я пыталась исправить эту ошибку, но не вышло
    //Переменная chek верно считывает символы, но по каким-то причинам даже если chek равно "circle ", функция strcmp(chek, "circle ") не равна нулю и как это исправить я не знаю


    //puts(chek);
    //printf("%d\n", strcmp(chek, "circle "));


    /*
    if(strcmp(chek, "circle ") == 0){
        circle(str, n, i);
    }else{
        error = 1;
        printf("^\n");
        printf("2.Error at column 0: expected 'circle'\n");
    }
    */

    int j=0, column;
    i++;
    char c_x[10];
    while (str[i]!=' '){
        if (isdigit(str[i]) || (str[i]=='.') || (str[i]=='-')){
            c_x[j]=str[i];
            i++;
            j++;
        }else{
            column = i + 3;
            for (int l=0; l<column; l++){
                printf(" ");
            }
            printf("^\n");
            printf("3. Error at column %d: expected '<double>'", column);
            break;
        }

    }
    j=0;
    float circle_x = atof(c_x);

    i++;


    char c_y[10];
    while (str[i]!=','){
        if (isdigit(str[i]) || (str[i]=='.') || (str[i]=='-')){
            c_y[j]=str[i];
            i++;
            j++;
        }else{
            column = i + 3;
            for (int l=0; l<column; l++){
                printf(" ");
            }
            printf("^\n");
            printf("4. Error at column %d: expected '<double>'", column);
            break;
        }
    }
	j=0;
    float circle_y = atof(c_y);
	
    i+=2;
    char c_r[10];
    while (str[i]!=')' || str[i]!='('){
        if (isdigit(str[i]) || (str[i]=='.')){
            c_r[j]=str[i];
            i++;
            j++;
        }else if (str[i]=='('){
            column = i + 3;
            for (int l=0; l<column; l++){
                printf(" ");
            }
            printf("^\n");
            printf("5. Error at column %d: expected ')'\n", column);
            break;
        }else if (str[i]==')'){
            break;
        }else{
            column = i + 3;
            for (int l=0; l<column; l++){
                printf(" ");
            }
            printf("^\n");
            printf("6. Error at column %d: expected '<double>'\n", column);

            break;
        }
    }
    float circle_r = atof(c_r);


	
    P_and_S(circle_r);

    return 0;

}


