#include <libgeometry/P_and_S.h>
#include <libgeometry/intersection.h>


#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <cstring>



int main(){
    int n=3, i=1;
    float x, y, r;
    int count=0;
    char str[n][50];
    char chiortov_str[50] = "a";
    float coords[n][3];
    int z=0;

    while(strcmp(chiortov_str,"") && z!=n){
        std::cin.getline(chiortov_str, 50);
        strcpy(str[z],chiortov_str);
        z++;
    }
    
    
    for (int a=0; a<z; a++){
        int i=0;
        int cheking_word = 0;
        char chek[10];
        while (cheking_word == 0){
            if (str[a][i]==')'){
                int column = i + 3;
                for (int l=0; l<column; l++){
                    printf(" ");
                }
                printf("^\n");
                printf("1.Error at column %d: expected '('", column);
                cheking_word = 1;
            }else if (str[a][i]=='('){
                cheking_word = 1;
            }else{
                chek[i]=str[a][i];
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
        while (str[a][i]!=' '){
            if (isdigit(str[a][i]) || (str[a][i]=='.') || (str[a][i]=='-')){
                c_x[j]=str[a][i];
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
        x = atof(c_x);

        i++;


        char c_y[10];
        while (str[a][i]!=','){
            if (isdigit(str[a][i]) || (str[a][i]=='.') || (str[a][i]=='-')){
                c_y[j]=str[a][i];
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
        y = atof(c_y);
	    
        i+=2;
        char c_r[10];
        while (str[a][i]!=')' || str[a][i]!='('){
            if (isdigit(str[a][i]) || (str[a][i]=='.')){
                c_r[j]=str[a][i];
                i++;
                j++;
            }else if (str[a][i]=='('){
                column = i + 3;
                for (int l=0; l<column; l++){
                    printf(" ");
                }
                printf("^\n");
                printf("5. Error at column %d: expected ')'\n", column);
                break;
            }else if (str[a][i]==')'){
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
        r = atof(c_r);
        
        
        coords[a][0] = x;
        coords[a][1] = y;
        coords[a][2] = r;
    }
    
    
    for (int a=0; a<z; a++){
        count = a + 1;
        printf("%d. ", count);
        printf("circle(%f %f, %f)\n", coords[a][0], coords[a][1], coords[a][2]);
        P_and_S(coords[a][2]);
        
        while (i!=z){
            if (intersection(coords[a][0], coords[a][1], coords[a][2], coords[i][0], coords[i][1], coords[i][2])){
                printf("%d and %d intersect\n", a+1, i+1);
            }
            i++;
        }
    }

    return 0;
}
