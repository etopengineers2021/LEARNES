#include<stdio.h>
#include<stdlib.h>
void Fahrenheit();
void  Celsius();
struct data {
    float celsius  ;
    float fahrenheit  ;
    int option ;
    
};
struct data t1;
int main(){
    while(1){
    printf("choice operation\n1.Convert Fahrenheit to Celsius\n2.Convert Celsius to fahrenheit\n3.Exit: ");
    
    scanf("%d",&t1.option);
    switch(t1.option){
        case 1:
      
        Fahrenheit();
        break;
        case 2 :
      
     Celsius();
        break;
        case 3 :
        printf("Tata");
        exit(1);
        break;
        default :
        printf("invalid input");
     
    }
    printf("\n");
 
}
   return 0; 
}
void Fahrenheit(){
    printf("Enter the fahrenheit:");
    scanf("%f",&t1.fahrenheit); 
    t1.celsius = (t1.fahrenheit - 32.0) * (5.0/9.0);
    printf("Celsius:%.2f",t1.celsius);
   
}
void Celsius(){
    printf("Enter celsius:");
    scanf("%f",&t1.celsius);
    t1.fahrenheit = (t1.celsius * (9.0 / 5.0)) + 32.0;
    printf("fahrenheit: %.2f",t1.fahrenheit);
   
}