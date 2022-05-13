#include <libgeometry/function.h>

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <cstring>





int main(){
	int n=3;
	int count=0;
	char str[n][50];
	char chiortov_str[50] = "a";
    	int z=0;
	
	while(strcmp(chiortov_str,"") && z!=n){
		std::cin.getline(chiortov_str, 50);
		strcpy(str[z],chiortov_str);
        	z++;
	}
	

	for (int a=0; a<z-1; a++){
		count = a + 1;
		printf("%d. ", count);
		read(str[a], 50);
	}
	
	return 0;
}
