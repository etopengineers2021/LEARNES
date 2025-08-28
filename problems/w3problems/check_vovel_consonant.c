/*********************************************************************************************************
FIND vovel or consonant.
*********************************************************************************************************** */
#include<stdio.h>
int main(){
    char let ;
    printf("Enter a alphabet: ");
    scanf("%c",&let);
    if(let =='a'||let =='e'||let =='i'||let =='o'|| let =='u'){ // vovel condition 
        printf("the alphabet is vovel ");
    }
    else if( let >='a' && let <= 'z' || let >= 'A'  && let <= 'Z'){ //consonant condition 
        printf("The alphabet is a consonant.");
    }
     else {
        printf("The character is not alphabet.");
     }
    return 0;

}