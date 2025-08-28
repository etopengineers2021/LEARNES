//String Space check..
#include<stdio.h>
#include<string.h>
#define SIZE 50
int main(){
     char name[SIZE];
     int num= 0;
     fgets(name,SIZE,stdin);// to get the input of string one line .
      // printf("%s\n",name); // this line for check the inputs .
       char * track=strtok(name,"  " ); //don at this strtok
    while(track !=NULL){
    printf("%s\n",track);
    track = strtok(NULL,"  ");
    num++;
}
printf("count of spaces %d",num);
return 0;
   
}