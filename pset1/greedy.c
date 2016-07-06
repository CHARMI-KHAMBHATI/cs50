#include<cs50.h>
#include<stdio.h>

int main(void){

    float value;
    int a=0,b=0,c=0,d=0,e;
    
     printf("Please Enter The value of change \n");
     
     do{
        printf("Please Enter a positive value : ");
        value=GetFloat();
    }while(value<0);
    
    value=value*100;
    
    while(value>=25){
        value=value-25;
        a++;
    }
    
     while(value>=10){
        value=value-10;
        b++;
    }
    
     while(value>=5){
        value=value-5;
        c++;
    }
    
     while(value>=1){
        value=value-1;
        d++;
    }
    
    e=a+b+c+d;
    
    printf("%d\n",e);
    
}