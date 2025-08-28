#include<stdio.h>
#define age 18
int main(){
    
    int ip = 0, count = 0;
    while(1){
    printf("Enter the age:");
    scanf("%d",&ip);
    if(ip >= age){
    printf("Congratulation! you are eligible for vote\n");
    }
    else if(age >= ip){
        for(int i = 0; age >= ip;i++  ){

        ip++;
        count = i;
    }
     printf("wait for %d year:\n",count);

}
    else printf("not eligible for vote\n");
}
    return 0;
}