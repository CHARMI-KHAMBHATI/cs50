
#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int key(char c);// function declaration

/**************** Main starts here******************/

int main(int argc, string argv[]){
    
    string key_string=argv[1];
   
// Check
    int l = strlen(key_string);
    
    for(int i=0;i<l; i++){
        
        if(!isalpha(key_string[i])){
         printf("Incorrect input \n");
        return 1;
        }
    }
   
    if(argc!=2){
        printf("Incorrect input \n");
        return 1;
        }
        
/*********************** CHECKS DONE ***************************************/

       
        
        string s= GetString();
        int len;
        len=strlen(s);
        int k;
        
        for(int i=0, j=0; i<len;i++ , j++){
            
            if(j>=l){
             j=0;
             }
            
            if(isupper(s[i])){
                
                k = key(key_string[j%l]);
             
                     printf("%c",  (((s[i]- 65) + k) % 26) + 65);
            }
             else
             if(islower(s[i])){  
                 
                 k = key(key_string[j%l]);
                 printf("%c", (((s[i] - 97) + k) % 26) + 97);
                 }
            
            else{
                
                printf("%c",s[i]);
                j--;
            }
            
            
        }
        printf("\n");
       return 0;
        
            
} // main ends
        
        
// Function to find key

int key(char c){
    int k;
   
   if(isupper(c)){
       k=c-65;
   } 
   else{
       k=c-97;
   }
   
   return k;
    
}// function ends