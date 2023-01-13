#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
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
    if(strcmp(command_type,"createfile")==0){
       sscanf(other,"%s %[^\n]%*c",useless,address);
       if(strcmp(useless , "--file") !=0){
           printf("Invalid Input");
         }
       else {
         if (address[0]=='"'){
             if (address[1]=='/'){
             
             }
             else {printf("Invalid Input");}
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
             printf("Invalid Input");
         }
         }
   }
   }
   }
}
}


