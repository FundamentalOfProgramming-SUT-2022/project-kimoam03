#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <cstdio>
void insertstr(char *fname ,char *text,int line,int position){
    FILE *file ;
    file =fopen(fname,"w+");
    //file!=NULL
    int pos =0;
    char c;
    if(file){
        
    }
}
bool exists( char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return true;
    }
    return false;
}
bool folder_exists(char *fname){
DIR* dir = opendir(fname);
if (dir) {
    /* Directory exists. */
    closedir(dir);
    return true;
} else if (ENOENT == errno) {
    /* Directory does not exist. */
    return false;
}
}
int main(){
    char*command;char *command_type;char *other;char *address;char* useless;
    command=(char*)malloc(2000*sizeof(char));
    other=(char*)malloc(2000*sizeof(char));
    command_type=(char*)malloc(2000*sizeof(char));
    useless=(char*)malloc(2000*sizeof(char));
    address=(char*)malloc(2000*sizeof(char));
    while(true)
    {
       scanf("%[^\n]%*c",command);
       sscanf(command,"%s %[^\n]%*c",command_type,other);
       if(command =="close"){
        break;
       }
    //case #number_1 : createfile 
    if(strcmp(command_type,"createfile")==0){
       sscanf(other,"%s %[^\n]%*c",useless,address);
       if(strcmp(useless , "--file") !=0){
           printf("Invalid Input\n");
         }
       else {
            if (address[0]=='"'){
                if (address[1]=='/'){
                    if(address[strlen(address)-1]=='"'){
                        char *str;str = (char*)malloc(2000*sizeof(char));
                        char *sup ; sup = (char*)malloc(2000*sizeof(char));
                        //printf("%s",address);
                        //printf("%s",strncpy(str,address,6));
                        if(strcmp(strncpy(str,address+1,6),"/root/")==0){
                        //printf("%d",strlen(address));
                            if(strlen(address)>8){
                            strcpy(str,"./root");
                            //printf("%s",str);
                            mkdir(str);
                            strcpy(str,"./root/");
                            //          /root/dir1/dir2/kiani.txt
                            int j =7;
                            for (int i=7;i<strlen(address)-1;i++){
                                if (address[i]=='/'){
                                    strncpy(sup,address+j,i-j);
                                    strncat(str,sup,i-j);
                                    mkdir(str);
                                    strncat(str,&address[i],1);
                                    j=i+1;
                                                     }
                                                                }
                            strcpy(sup,".");
                            strncat(sup,&address[0]+1,strlen(address)-2);
                            if(exists(sup)==true){
                                printf("File Existed\n");
                                continue;
                                                }
                            else {
                                FILE *file;
                                file = fopen(sup,"w");
                                }
                            }
                            else {
                                printf("Invalid Input\n");
                                 continue;
                                    }
         }
         }
                    else {
                        printf("Invalid Input\n");
                        continue;
                        }
        }   
             
        else {printf("Invalid Input\n");continue;}
        }
         else if (address[0] == '/'){
            char *str;str = (char*)malloc(2000*sizeof(char));
            char *sup ; sup = (char*)malloc(2000*sizeof(char));
            //printf("%s",address);
            //printf("%s",strncpy(str,address,6));
            if(strcmp(strncpy(str,address,6),"/root/")==0){
                //printf("%d",strlen(address));
                if(strlen(address)>6){
                strcpy(str,"./root");
                //printf("%s",str);
                mkdir(str);
                strcpy(str,"./root/");
                //          /root/dir1/dir2/kiani.txt
                int j =6;
                for (int i=6;i<strlen(address);i++){
                if (address[i]=='/'){
                strncpy(sup,address+j,i-j);
                strncat(str,sup,i-j);
                mkdir(str);
                strncat(str,&address[i],1);
                j=i+1;
            }
         }
           strcpy(sup,".");
           strcat(sup,address);
           if(exists(sup)==true){
               printf("File Existed\n");}
           else {
               FILE *file;
               file = fopen(sup,"w");}
         }
         
         
         else {
             printf("Invalid Input\n");
             continue;
         }
         }
   }
   }
   }
   //case #number_2 : insert
   else if(strcmp(command_type,"insertstr")==0){
       //printf("%d",1);
       sscanf(other,"%s %[^\n]%*c",useless,address);
       if(strcmp(useless , "--file") !=0){
           printf("Invalid Input\n");
         }
       else {
        if(address[0]=='"'){
            char *str;str = (char*)malloc(2000*sizeof(char));
            char *sup ; sup = (char*)malloc(2000*sizeof(char));
            char *text ; text = (char*)malloc(2000*sizeof(char));
            sscanf(address+1,"%[^\"]%*c %[^\n]%*c",address+1,text);
            int j=1;
            for(int i=0;i<strlen(address);i++){
                if(address[i]=='/'){
                    j=i;
                }
            }
            strncat(address,&address[0],1);
            strcpy(str,".");
            strncat(str,&address[1],j);
            if(!folder_exists(str)){
                printf("Directory Does Not Exists\n");continue;
            }
            else {
                strcpy(str,".");
                strncat(str,&address[1],strlen(address)-2);
                if(!exists(str)){
                    printf("File Does Not Exists\n");continue;
                }
                else{

                }

            }
        }
        else if(address[0]=='/'){
            char *str;str = (char*)malloc(2000*sizeof(char));
            char *sup ; sup = (char*)malloc(2000*sizeof(char));
            char *text ;text=(char*)malloc(2000*sizeof(char));
            sscanf(address,"%s %[^\n]%*c",address,text);
            int j=0;
            for(int i=0;i<strlen(address);i++){
                if(address[i]=='/'){
                    j=i;
                }
            }
            strcpy(str,".");
            strncat(str,&address[0],j);
            //printf("%s",str);
            if(!folder_exists(str)){
                printf("Directory Does Not Exists\n");continue;
            }  
            else {
                strcpy(str,".");
                strncat(str,&address[0],strlen(address));
                if(!exists(str)){
                    printf("File Does Not Exists\n");continue;
                }
                else {

                }
            } 
        }
        else {
            printf("Invalid Input\n");
            continue;
        }
   }
   }
   }
   }






