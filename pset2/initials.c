#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

/**************** Main body********************/

int main(void){
    
    string s;
    int l;
    
    s=GetString();
    l=strlen(s);
    
// logic for printing initials;
    
    printf("%c",toupper(s[0]));   // Prints the first letter as it is with uppercase
    
    // logic for other letters
    for(int i=0; i<=l;i++){
    
          if(s[i]==' '){
            printf("%c", toupper(s[i+1]));
        }
        
    }// for loop ends
    
    printf("\n");
    
}// main ends here