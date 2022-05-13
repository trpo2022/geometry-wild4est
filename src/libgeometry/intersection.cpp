#include <libgeometry/intersection.h>

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cctype>
#include <cstring>


float intersection(float x1, float y1, float r1, float x2, float y2, float r2){
    if ((x2-x1)*(x2-x1) - (y2-y1)*(y2-y1) < (r1+r2)*(r1+r2)){
        return 1;
    }else{
        return 0;
    }
}
