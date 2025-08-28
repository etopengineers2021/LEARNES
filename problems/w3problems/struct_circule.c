#include<stdio.h>
struct circle{
    float radise;
    
};
double calculate_area(int c){
    return 3.14 *c*c;
}
double calculate_perimeter(int x){
    return 2 * 3.14 *x;
}
struct circle t1, t2;
float main(){
    printf("Input details RADIES for Circule 1:"); scanf("%f",&t1.radise);
    printf("Input details RADIES for Circule 2:"); scanf("%f",&t2.radise);
    
     puts("THE circule 1");
     printf("ARES:%.2lf\n",calculate_area(t1.radise));
     printf("permimeter :%.2lf\n",calculate_perimeter(t1.radise));
       puts("THE circule 2");
    printf("ARES:%.2lf\n",calculate_area(t2.radise));
    printf("permimeter :%.2lf\n",calculate_perimeter(t2.radise));

    return 0 ; 

}