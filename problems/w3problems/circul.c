// compute circule perimete and area. formuls pi=3.1415
#include<stdio.h>
#define pi 3.141
int main(){
 int radius = 6;
float perimeter = 2*(pi* radius );
 float area = pi* (radius*radius);
 printf("The perimeter: %f\n  The area :%f",perimeter,area);
} 