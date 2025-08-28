#include<stdio.h>
#include<string.h>
int main(){
//  char  arry1[10] = "HAR";
  //char  arry2[10] = "HAR";
  int  arry1[10] ={100,20,30};

  int arry2[10] ={200,20,30};
  int result = memcmp( arry1, arry2, 10);

  if(result <0 ){
    printf("Nagtive array 1 < arry2\n");
  }
  else if(result > 0){
    printf("postive array1 > arry2");
  }
  else printf("array are equal");
return 0;
}
