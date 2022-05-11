#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cctype>
#include <cstring>

float pi = 3.14;
int error=0;

int P_and_S(float circle_x, float circle_y, float circle_r){
	float P, S;
	P = 2 * pi * circle_r;
	printf("perimeter = %f\n", P);
	S = pi * circle_r * circle_r;
	printf("area = %f\n", S);
	
	return 0;
}


int circle(char str[], int n, int i){
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
			error = 1;
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
			error = 1;
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
			error = 1;
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
			error = 1;
			printf("^\n");
			printf("6. Error at column %d: expected '<double>'\n", column);
			
			break;
		}
	}
	float circle_r = atof(c_r);

	
	if (not error){
		P_and_S(circle_x, circle_y, circle_r);
	}
	
	return 0;
}



int read(char str[], int n){
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
			error = 1;
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
	
	if(strcmp(chek, "circle ") == 0){
		circle(str, n, i);
	}else{
		error = 1;
		printf("^\n");
		printf("2.Error at column 0: expected 'circle'\n");
	}
	return 0;
	
}




int main(){
	int n=3;
	int count=0;
	char str[n][50];
    int z=0, ch=0;
	
	while(ch!=13 && z!=n){
		ch = getch();
		gets(str[z]);
        z++;
	}
	

	for (int a=0; a<z-1; a++){
		count = a + 1;
		printf("%d. ", count);
		read(str[a], 50);
	}
	
	return 0;
}
