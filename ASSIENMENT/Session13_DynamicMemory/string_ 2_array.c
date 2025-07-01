#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char name[]={"hari","vijay","indhren","venkat"};
    for(int i=0; name[i]<'\0';i++){
     printf("name%d=%s",i,name[i]);
     }
   
   /* char *namee[][4]={{"hariravi","boss"}
    ,{
     "two diamension array"
        
    }};
    
    printf("%s",namee[0][1]);
   ; */
    return 0;
    
}