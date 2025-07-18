#include<stdio.h>
#include<stdlib.h>
void arithmatic();
void hexfun(char *var);
void fun_octal(char* actol);
void convert_binary(); 
void convert_hexdesimal();
void history();
void conversion();
void convert_octal();
void convert_decimal();
void bitwise();
void logicalshift();
void arithmeticshift();
void array_circulation();
void rotate_circulation();
void logical();
  
enum{
    addition = 1,
    subtraction,
    multiplcation,
    division,
    modulo ,
    Exit,
    
};

#define MAX 11
#define MIN 5
typedef unsigned int uint8_t;
struct count{
 unsigned int count_a ;
 unsigned int count_c ;
 unsigned int count_b ;
 unsigned int count_l ; 
 unsigned int d_t;
};
struct count h;
int main(){
 // while(1){

  
  while(1){
   printf("\tDigital Inputs Only Enable: \n");
   int operator = 0 ;
   printf("1.Arithmetic\t2.conversion\t3.Bitwise\t4.logical\t5.History \t6.Exit\n Enter your choice:");
   scanf("%d",&operator);
    switch(operator){
      case 1:
      h.count_a++;
        printf("Arithmetic Operation\n");
         arithmatic();
        break;
      case 2:
         h.count_c++;
         printf("conversion\n");
         conversion();   
         break;
      case 3:
        h.count_b++;
        printf("bitwise operator\n");
        bitwise();
        break;
      case 4:
      h.count_l++;
        printf("logical operation\n");
        logical();
        break;
        case 5 :
         history();
        break;
        case 6:
        printf("Your exit");
        exit(0);
         break;
             
              
        default:
        printf("Invalid input\n");
        }
      }
      }
  

void conversion(){  //conversion function
    
       int opt= 0;
       printf("1.binary --> hex,dec,oct\t2.decimal--> hex,bin,oct\t3.hexadicimal--> bin,dec,oct\t4.octal--> bin,dec,hex\t5.Exit\n");
       printf("Enter your choice:");
       scanf("%d",&opt);
       
        switch(opt){
           case 1:
             printf("Binary operation\n");
            convert_binary();
             break;
           case 2:
              printf("desimal operation\n");
              convert_decimal();
              break;
           case 3:
              printf("Hexadicimal operation\n");
              convert_hexdesimal();
              break;
           case 4:
              printf("octal operation\n");
              convert_octal();
              break;  
           case 5:
                printf("Your exit");
                exit(0);
               break;
              default :
              printf("invalid input\n");   
        } 
      }
void convert_binary(){  //Binary --> dec,hex,oct.
       int n = 0;                        //input
       printf("Enter binary :");
       scanf("%d",&n);
       int base = 1;
       int dec = 0;
       int octal[8];
    for(int i = 0 ; i <= 8 ; i++){
     
        int lase_n = n % 10;
         n = n / 10;   
         dec += lase_n * base;
        base = base * 2;

    }                                     //outputs
    printf("Decimal: %d\n",dec);
    printf("hexadecimal:%x\n ",dec);
    printf("octal: ");
    int ans = 0,f = 0,j = 0;
    for(;f < MIN ; f++){
      octal[f]= dec % 8;
      dec /= 8;
          }
    for(j = f - 1; j >= 0 ;j--){
       printf("%d",octal[j]);
        }
     }
void convert_hexdesimal() { //hexdesimal--> bin,dec,oct.
   printf("enter the hex input\n");
    char hex[50];
    scanf("%s",hex);
    printf("hex to Binary :");
    hexfun(hex);
    long val = strtol(hex,NULL,16);  //strtol convert hexadecimal to decimal.
    printf("\nHex to decimal: %d\n",val);
    printf("Hex to Octal: %lo\n", val);
 }
void hexfun(char *var){
    for(int i = 0;var[i]!='\0' ;i++){
     switch(var[i]){
         case '0':
         printf("0000");
         break;
        case'1':
         printf("0001");
         break;
        case '2':
        printf("0010");
        break;
        case '3':
        printf("0011");
        break;
        case '4':
        printf("0100");
        break;
        case '5':
        printf("0101");
        break;
        case '6':
        printf("0110");
        break;
        case '7':
        printf("0111");
        break;
        case '8':
        printf("1000");
        break;
        case '9':
        printf("1001");
        break;
        case 'A':
        case 'a':
        printf("1010");
        break;
        case 'b':
        case 'B':
        printf("1011");
        break;
         case 'c':
        case 'C':
        printf("1100");
        break;
         case 'd':
        case 'D':
        printf("1101");
        break;
         case 'e':
        case 'E':
        printf("1110");
        break;
         case 'f':
        case 'F':
        printf("1111");
        break;
        default :{
          printf("invalid input\n");}
        i++;
       }
     }
 }

void convert_decimal(){  //decimal--> hex,bin,oct
    int num;
   
                                   
    printf("Decimal operation:\n");
    printf("enter the input");
    scanf("%d",&num);
    if(num!=0){

    
    int temp =num;
    int de= temp;
    int octal[5];
    printf("---decimal to hexadecimal--\n");
    printf("Hexaformate: %x\n",num);
    int bin[MAX];
    int i = 0;
    for(; i <=MAX ;i++){
        bin[i]= num % 2;
        num= num / 2;
       
    }
     printf("\nBinary :");
    for(int d = i-1; d >= 0;d--){ // output
         printf("%d",bin[d]);
    }
   
     i = 0;
    for(;i <= 5 ;i++){
        octal[i]= de % 8;
        de /= 8;

    } 
    printf("octal :");            //output
    for(int j = i - 1; j >=0; j--){
          printf("%d",octal[j]);
    }
 
}
else{
printf("Invalid Input\n");
}}

void convert_octal(){ //octal --> dec,hex,bin.
    int octal;         //input
    printf("choice:");
    scanf("%o",&octal);
     char octal1[25];
     sprintf(octal1, "%o", octal);
  fun_octal(octal1);         //
    printf("\ndesimal: %d\n",octal);
    char hex[255];
    sprintf(hex,"%x",octal); 
    printf("hexa formate: %s\n",hex);
    }
void fun_octal(char* actol){
  printf("Binary: ");
     for(int i = 0 ;actol[i] !='\0';i++){
      switch(actol[i]){
        case '0':
        printf("000");
        break;
        case '1':
        printf("001");
        break;
        case '2':
        printf("010");
        break;
        case '3':
        printf("011");
        break;
        case '4':
        printf("100");
        break;
        case '5':
        printf("101");
        break;
        case '6':
        printf("110");
        break;
        case '7':
        printf("111");
        break;
        default :{
            printf("invalide input");
        }
        i++;
      }     
    }
}

void arithmatic(){  
  int input1 = 0, input2 = 0, operator = 0; //input
       printf("1.addition\t2.subtraction\t3.multiplcation\t4.division\n5.modulo\t6.Exit\n");
        printf("Choice: ");
         scanf("%d",&operator);
if(operator > 0 && operator < 6){
    printf("Enter the inputs\n");
      scanf("%d",&input1);
       scanf("%d",&input2);
}
          switch(operator){
              case addition:
           
              printf("Doing addition\n");
              printf("%d\n",input1 + input2);
              break;

              case subtraction :
              printf("Doing subtraction\n");
              printf("%d\n",input1 - input2);
              break;
              case multiplcation :
              printf("Doing Multiplcation\n");
              printf("%d\n",input1 * input2);
              break;
              case division :
              printf("Doing  Division\n");
              printf("%d\n",input1 / input2);
              break;
              case modulo :
              printf("Doing modulo\n");
              printf("%d\n",input1 % input2);
              break;
              case Exit:
              printf("Your exit");
              exit(0);
              break;
              default :
              printf("Invalied input\n"); 
          }  
       }

   
                
  
void bitwise(){
  int a = 0, b = 0,choice; 
  printf("1.And\t2.Or\t3.Not\t4.ex_or\t 5.Nand\t6.Nor\t7.Logical shift\t 8.Arithmetic shift\t9.Array_circulation\t10.rotate_circular\t11.Exit\n");
   printf("choice:");
    scanf("%d",&choice);
if(choice < 7){
  printf("\nEnter to binary input a b:"); //input
   scanf("%d",&a);
    scanf("%d",&b);
     printf("bit_wise operation\n");
   }
   
  switch(choice){
    case 1 :
    printf("And-operation: %d\n\n",(a&b));
    break;
    case 2:
    printf("Or-operation: %d\n",(a|b));
    break;
    case 3:
    printf("Not-operation: %d\n",~(a)); //bitwise
    break;
    case 4:
    printf("Ex_or-operation: %d\n",(a^b));
    break;
    case 5:
    printf("Nand-operation: %d\n",~(a&b));
    break;
    case 6:
    printf("Nor-operation%d\n",~(a|b));
    break;
    case 7:
    logicalshift();
    break;
    case 8:
    arithmeticshift();
    break;
    case 9:
    array_circulation();
    break;
    case 10:
    rotate_circulation();
    break;
     case 11:
        printf("Your exit");
        exit(0);
         break;
    default:
    printf("invalid choice \n");
    }
  
   
    }
 
void logicalshift(){
 printf("Logical shift:");
     while(1){
   int a = 0,n=0;                    //input 
   int d = 0;                        //direction of shift
    printf("enter the input: ");
     scanf("%d",&a);
      printf("direction of shift:1.left 2.right: ");
       scanf("%d",&d);
        if(d==1||d==2){
     printf("number of shift: ");
      scanf("%d",&n);
   }                                 //output
   if(n > 0 && d==1){
    int shif_r= a<<n;
     printf("leftshift: %d\n",shif_r);
} 
   else if(n > 0 && d==2){
      int left_r = a >> n;
       printf("Rightshift: %d\n",left_r);
    }
   
else{
  printf("invalid choice\n");
          }
        } 
      }
  
void arithmeticshift(){
 printf("Arithmetic shift\n");
    int d = 0,a= 0,n =0;                           //inputs
     printf("direction of shift: 1.left 2.right: ");
     scanf("%d",&d);
 if(d==1 || d==2){  
 if(d==1){
     printf("enter the input: ");
     scanf("%d",&a);
     printf("number of shift: ");
     scanf("%d",&n);
     int shif_l= a<<n;
     printf("leftshift: %d\n",shif_l);
} 
    if(d==2){                                  //input
       printf("only postive value allow");
       printf("enter the input: ");
       scanf("%d",&a);
       printf("number of shift: ");
       scanf("%d",&n);
                                           //output
       int shif_r= a>> n;
       printf("Rightshift: %d\n",shif_r);

    }
}
   else{
  printf("invalid input \n");
          }
      }
 
void  array_circulation(){
         printf("Array circulation: "); 
         int SIZE;                                //inputs
         int index=0;
         int run =  0;
         printf("Enter the size");
         scanf("%d",&SIZE);
         printf("Enter the elements:");
         int *array=malloc(SIZE * sizeof(int));

        for(int i = 0; i < SIZE;i++){
          scanf("%d",&array[i]);
        }
        printf("How many times circulate:");
        scanf("%d3",&run);
        run= SIZE * run;
    for(int i= 0; i < run ;i++){                   //output
        printf("array[%d]=%d\n",index,array[index]);
        index =(index + 1) % SIZE;
    }

}
void rotate_circulation(){
  int dum = 0 ;
  printf("1.clock wise \t2.Anticlock wise");
  printf("choice");
  scanf("%d",&dum);
  if(dum==1 || dum==2 ){
  if(dum==1)
  {   
    int SIZE;
    
     printf("Enter the size: ");
     scanf("%d",&SIZE);
     int array[SIZE];
       
     printf("Enter the elements: ");
     for(int i = 0; i < SIZE;i++){
     scanf("%d",&array[i]);
        }
        int temp = array[SIZE - 1]; 
        for( int i = SIZE - 1; i > 0; i--){
            array[i]=array[i - 1];
        }
        array[0]= temp;
        int y= 0;
        printf("Rotate clockwise: ");
        for(; y < SIZE ;y++ ){
            printf("%d ",array[y]);
        }
        printf("\n");
       
    }
    if(dum==2){
       printf("anticlock");
       int SIZE;
       printf("Enter the size: ");
       scanf("%d",&SIZE);
       int array[SIZE];
       printf("Enter the elements: ");
       for(int i = 0; i < SIZE ;i++){
          scanf("%d",&array[i]);
        }
        int temp = array[0]; 
      
        for( int i = 0; i < SIZE - 1; i++){
            array[i] = array[i + 1];
        }
        array[SIZE -1]= temp;
        int y = 0;
        printf("Rotate anti clockwise: ");
        for(; y < SIZE ; y++ ){
            printf("%d ",array[y]);
        }
        printf("\n");
}
    }
    else {
      printf("invalid input\n");
    }
  }
void logical(){   //logical operation 
    
       printf("Logical operation: ");
      int input1 = 0,input2 = 0;
      int choice = 0;
      printf("1.And\t2.Or\t3.Not\t4.Exit\n");
      printf("choice: ");
       scanf("%d",&choice);
if(choice==1||choice==2){
      printf("Enter the inputs a b(0 or 1)only:");
      scanf("%d",&input1);
      scanf("%d",&input2);
                }
if((input1 !=0 && input1!=1 )||(input2 !=0 && input2 !=1)){
  printf("invalid input:");
  
}
      switch(choice){
        
            case 1:
               printf("And: %d\n",input1 && input2);
            break;
            case 2:
               printf("Or: %d\n",input1 || input2);
            break;
            case 3:
               printf("enter the input: ");
               scanf("%d",&input1);
               printf("Not: %d\n",!(input1));
            break;
            case 4:
            printf("Your exit");
             exit(0);
             default :
        printf("invalid input\n");
        }
       }
 void history(){
  int op = 0;
            printf(" history\n1.Arithmetic\t2.conversion\t3.Bitwise\t4.logical\t5.Exit\n");  //history
            printf("choice:");
            scanf("%d",&op);
              switch(op){
              case 1 :
              printf(" Arithmetic count%d\n",h.count_a);
              break;
              case 2:
              printf("Conversion count%d\n",h.count_c);
              break;
              case 3 :
              printf("Bitwise:  %d\n",h.count_b);
              break;
              case 4 :
              printf("logical: %d\n",h.count_l);
              break;
              case 5:
              printf("Your exit");
              exit(0);
              break;
              default :
              printf("Invalid input\n");
              }
 }

