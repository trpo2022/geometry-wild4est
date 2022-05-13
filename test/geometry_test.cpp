#include <ctest.h>
#include <stdlib.h>
#include <stdio.h>
#include <libgeometry/intersection.h>
#include <libgeometry/P.h>
#include <libgeometry/S.h>

CTEST(P, test1){
	float r = 3.7;
	const float exp = 2 * 3.14 * r;
    float real = P(r);
    ASSERT_DBL_NEAR(exp, real);

}

CTEST(S, test2){
	float r = 3.7;
	const float exp = r * r * 3.14;
    float real = S(r);
    ASSERT_DBL_NEAR(exp, real);

}

CTEST(intersection, test3){
	float x1 = 1, y1 = 1, r1 = 5, x2 = 2, y2 = 2, r2 = 5;
	float exp = 0;
    if ((x2-x1)*(x2-x1) - (y2-y1)*(y2-y1) < (r1+r2)*(r1+r2)){
        exp = 1;
    }
    float real = intersection(x1, y1, r1, x2, y2, r2);
    ASSERT_DBL_NEAR(exp, real);
}
