#include<stdio.h>//pending


struct book {
    char title[100];
    char author[100];
    float pr;
}book1,book2;

int main(){
printf("Enter book1  details please :\n");
printf("Title:");
scanf("%s",&book1.title);
printf("Author: ");
scanf(" %s",&book1.author);
printf("price:");
scanf("%f",&book1.pr);
printf("title: %s\nAuthor %s\nprice: %f",book1.title,book1.author,book1.pr);


}