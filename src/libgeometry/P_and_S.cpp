#include <libgeometry/P_and_S.h>

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <cstring>



int P_and_S(float circle_r){
    float P, S;
    float pi = 3.14;
    P = 2 * pi * circle_r;
    printf("perimeter = %f\n", P);
    S = pi * circle_r * circle_r;
    printf("area = %f\n", S);
	
    return 0;
}
