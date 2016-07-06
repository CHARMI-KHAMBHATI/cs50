#include<cs50.h>
#include<stdio.h>

int main(void){
    
    int time;
    int no_of_bottles;
    
    printf("WELCOME ! \n");
    printf("Please Enter The Time in minutes \n");
    
    do{
        printf("Please Enter a positive no. : ");
       time=GetInt();
        
    }while(time<0);
    
    no_of_bottles= time*12;
    
    printf(" So You wasted %d Bottles of water today, \n WATCH OUT !\n", no_of_bottles);
    return 0;
    
}
