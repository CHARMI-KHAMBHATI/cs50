#include<cs50.h>
#include<stdio.h>

int main(void){
 
    int height;
    int i,j;
     printf("Please Enter The Height \n");
    
    do{
        printf("Please Enter a positive no. : ");
       height= GetInt();
       
    }while(height<0);
 
    for(i=1;i<=height;i++){
        for(j=0;j<(height-i);j++){
            printf(" ");
        }
        
        for(j=0;j<=i;j++){
            printf("#");
        }
        
        printf("\n");
    }
   
   return 0; 
}
