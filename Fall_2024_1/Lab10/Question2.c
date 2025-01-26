#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;


double distance(point x1, point y1) {
    return sqrt((y1.x - x1.x,2) + pow(y1.y - x1.y,2));
}

int isPointInsideRectangle(point p, point bottomLeft, point topRight) {
    return (p.x >= bottomLeft.x && p.x <= topRight.x && p.y >= bottomLeft.y && p.y <= topRight.y);
}

int main() {
    point x1 = {1,4};
    point y1 = {5,6};
    double dist = distance(x1,y1);
    printf("%f \n", dist);
    point bottomLeft = {0,0};
    point topRight = {5,5};
    if (isPointInsideRectangle(x1,bottomLeft,topRight)) {
        printf("Inside rectangle.");
    } else {
        printf("Outside rectangle.");
    }
}