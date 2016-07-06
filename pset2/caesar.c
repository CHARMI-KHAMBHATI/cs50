#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

/************ Main body******************/

int main(int argc, string argv[]){

 // Check
  if(argc!=2){
      printf(" Enter correct Input ! \n");
       return 1;
   }
   
    
   
        int k=atoi(argv[1]);
        string s= GetString();
        int l;
        l=strlen(s);
       
   
        for(int i=0; i<l; i++){
         
           
            if(isupper(s[i])){
             
                     printf("%c",  (((s[i] - 65) + k) % 26) + 65);
            }
             else if(islower(s[i])){  
                 
                 printf("%c", (((s[i] - 97) + k) % 26) + 97);
                 }
            
            
        else{
            
            printf("%c",s[i]);
            }
        } // for loop ends here
        
       printf("\n");
       return 0;
  
}// main ends here