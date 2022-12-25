#include "header2.h"
#include <stdbool.h>



typedef enum  {Comment,
                NewLine,
                Normal,
                Single_string,
                Double_string
                } State;

State state = Normal;



int c ,i = 0,j[3],k,normal_coll[2000],                 // an array to hold values starting form ' /* ' to */ or all
comment_coll[2000],                                   // an array to hold values that are not comment and space charactor
space = 32,count = 0,Line = 1,m,L;
int status = 0;
int intialcom = 0,d;
int  EXIT_SUCCESS = 0,EXIT_FAILURE = -1; 

bool isTrue = true; 
void state_set()
{
    c = getchar();
    while(c != EOF){

        normal_coll[count] = c;

         if(c == '\n'){
            Line++;
            state = NewLine;
            
        }

        else if(c == '\'') {

            state = Single_string;

        }

        else if(c == '\"'){

            state = Double_string;
        }
       
        else if(c == '/') {

            c = getchar();
            if(c == '*'){
                normal_coll[count] = space;
                count++;
                state = Comment;

            }

            else if(c == '/'){
                count++;
                continue;
             
            }

            
            else if(c == EOF){
                count++;
                continue;
            }
            else {
                if(c == '\n'){
                    count++;
                    Line++;
                    normal_coll[count] = c;

                }
                else if(c != EOF){
                count++;
                normal_coll[count] = c;
                }

            }
        }
        
        else {
            if(c != EOF){
                state = Normal;
            }
        }      
            switch (state) {

                    case Comment:
                        comment_set();
                        break;
                    
                    case Normal:
                        alpha_set();
                        break;
                    case NewLine:
                        alpha_set();
                        break;
                    case Single_string:
                        single_string_set();
                        break;
                    case Double_string:
                        double_string_set();
                        break;
                        }


if(c != EOF){
    c = getchar();
    continue;
}

    }
    
   

}

void comment_set(){

    c = getchar();
    
    intialcom = Line;
    while(c != EOF){
        // intialcom = Line;
        comment_coll[i] = c;
        i++;
        if(c == '*'){
            c = getchar();
            if(c == '/'){
                comment_coll[i] = c;
                // i++;
                
                state_set();
                continue;
            }
            else if(c == '*'){

                continue;
            }
            else if(c ==  EOF){

                break;
            }
            else if(c == '\n'){
                count++;
                normal_coll[count] = c;
                Line++;
                continue;
                
            }
            else if(c != EOF){
                continue;
            }
        }

       
        else {
             
            if(c == '/'){
               c = getchar();
                continue;
            }
           
            
            else if(c == '\n'){
                
                
                normal_coll[count] = c;
                count++;
                Line++;
                c = getchar();
                continue;
                
            }
            else if(c != EOF){
                c = getchar();
                continue;
            }
    
        }

    }
    if(c ==  EOF && state == Comment){
                isTrue = false;
                // printf("a in ");
               
            }
    
    
}

void alpha_set(){

    normal_coll[count] = c;
    count++;
    // printf("%c ",c);
    state_set();
    
}


void single_string_set(){
    normal_coll[count] = c;
    count++;
    c = getchar();
    while(c != EOF){
        if(c == '\''){
            normal_coll[count] = c;
            count++;
            state_set();
            break;
        }
       else{
            normal_coll[count] = c;
            count++;
            c = getchar();
       }

    }
    
}


void double_string_set(){
     normal_coll[count] = c;
    count++;
    c = getchar();
    while(c != EOF){
        if(c == '\"'){
            normal_coll[count] = c;
            count++;
            state_set();
            break;
        }
       else{
            normal_coll[count] = c;
            count++;
            c = getchar();
       }

    }
}

void print_char(){
 
    if(1){
        for (int z =0 ;z<count;z++){
        printf("%c",normal_coll[z]);
}
    }
}

void print_error(){
   
    if(!isTrue){

        status = EXIT_FAILURE;
        fprintf(stderr,"Error: line %d: unterminated comment ",intialcom);
    }
}

void check(){
    if(i > 0){
        
            if(comment_coll[i-1] == '*'  && comment_coll[i] == '/'){
                isTrue = true;
            }
            else{
                isTrue = false;
            }
}
return;
      }


