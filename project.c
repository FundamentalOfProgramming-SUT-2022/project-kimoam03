//In The Name Of Allah
#include "FunctionHeader.h"
//#Problems :
//createfile with space in folders 
//cat is ok
//insertstr "" for string
//remove  0 1 + Error EOF &0
//copy    0 1 + Error EOF &0
//cut     
//paste
//find
//greb
#define exists file_exists
int main(){
    FILE * fptr;
    //fptr =fopen("./root/m","r+");
    char try[1000];strcpy(try,"/root/m");
    cut(try,2,3,5,1);
    exit(1);
    char command[2000];char command_type[2000];char other[2000];char address[2000];char useless[2000];
    while(true)
    {
    scanf("%[^\n]%*c",command);
    sscanf(command,"%s %[^\n]%*c",command_type,other);
    //close command : default
    if(!strcmp(command ,"close")){
        break;
    }
    //case #number_1 : createfile 
    if(strcmp(command_type,"createfile")==0){
       sscanf(other,"%s %[^\n]%*c",useless,address);
       //printf("%s",address);
        createfile(address);
   }  
   //case #number_2 : insert
   else if(strcmp(command_type,"insertstr")==0){
       //printf("%d",1);
        sscanf(other,"%s %[^\n]%*c",useless,address);
        int line , pos;
        char esc;
        char str [100];
        char rest[100];
        if(address[0]=='"'){
            sscanf(address+1,"%[^\"] %*c %s %s %s %[^\n]",address+1,useless,str,other,rest);
            *(address)='"';
            strcat(address,"\"");
            }
        else if(address[0]=='/')
            sscanf(address,"%s %*c %s %s %s  %[^\n]",address,useless,str,other,rest);
        line = rest[0] -'0';
        pos = rest[2]-'0';
        //printf("%d%d\n",line,pos);
        //printf("%s\n%s\n%d\n%d\n",address,str,line ,pos);
        insertstr(address,str,line ,pos);
    
   }
   //case #number_3 : cat
   else if (!strcmp(command_type,"cat")){
        sscanf(other,"%s %[^\n]",useless,address);
        cat(address);
        //printf("%s",address);
        //printf("%s",address);
   } 
   
    //case #number_4 : remove
    if(!strcmp(command_type,"removestr")){
        sscanf(other,"%s %[^\n]",useless,address);
        int line , pos;
        char how;
        char useless_2[1000];char size;
        if(address[0]=='"'){
            /*sscanf(address+1,"%[^\"] %*c %s %s %s %[^\n]",address+1,useless,str,other,rest);
            *(address)='"';
            strcat(address,"\"");
            }*/}
        else if(address[0]=='/')
            sscanf(address,"%s%*s%s%*s %*c %c %*c %*c %c",address,other,size,how);
        line = other[0] -'0';
        pos = other[2] - '0';
        printf("%s\n%s\n%d\n%d\n%c\n%c\n",address,other,line,pos,size,how);
    }
}  
}

//General Functions
int number_of_charactars (FILE *fptr ){
    int c ;
    int   n =0;
    do {
        c = fgetc(fptr);
        if (c!=EOF)++n;
    }while(c!=EOF);
    return n;
}
void CopyFile (FILE * fptr ,FILE* sptr, int from , int to ) {
    int n = 0;
    int c;
    while (n<from){
        c = fgetc(fptr);++n;
    }
    while (n<=to) {
        c = fgetc(fptr);++n;
        fputc(c,sptr);
    }
}
int number_of_lines (FILE* fptr){
    int n = 1;
    char c ;
    c = fgetc(fptr);
    while ((int)c!= EOF) {
        if (c=='\n') n++;
        c = fgetc(fptr);
    }
    return n ;
}
int what_is_the_position(FILE* fptr, int line , int pos) {
    int n=0;
    int l =1;
    int p =0;
    int c = fgetc(fptr);
    while (c!=EOF) {
        if(l==line && p == pos)return n;
        else if ((char)c=='\n'){l++;p=0;n++;c=fgetc(fptr);}
        else {p++;n++;c=fgetc(fptr);}
    }
}
bool file_exists( char *fname)
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
int check_all (char* address ){
    //printf("1");
    char *str;str = (char*)malloc(2000*sizeof(char));
    char *sup ; sup = (char*)malloc(2000*sizeof(char));
    char *text ;text=(char*)malloc(2000*sizeof(char));
    //printf("%s\n",address);
    if(address[0] =='/'){
    sscanf(address,"%s %c %[^\n]",address,text,sup);
    //sscanf(text,"%s %[^\n]",sup,text);
    //printf("%s",sup);
    int j=0;
    for(int i=0;i<strlen(address);i++){
        if(address[i]=='/'){
            j=i;
        }
        }
        strcpy(str,".");
        strncat(str,&address[0],j);
        strcpy(address,str);
        //printf("%s",text);
    if(!folder_exists(str)){
        puts("Directory Does Not Exists");
        return -1;
        }  
    else {
    //printf("1");
        strcpy(str,".");
        strncat(str,&address[0],strlen(address));
        strcpy(address,str);
        if(!file_exists(str)){
            puts("File Does Not Exists");
            return -1;
        }
        return 0;
        }
    }
    else if (address[0] == '"') {
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
            strcpy(address,str);
            if(!folder_exists(str)){
                puts("Directory Does Not Exists");
                return-1;
            }
            else {
                strcpy(str,".");
                strncat(str,&address[1],strlen(address)-2);
                strcpy(address,str);
                if(!exists(str)){
                    puts("File Does Not Exists");
                    return -1;
                }
            }
            return 0;
        }
    }
void alter_to_address(char *address) {
    char buffer [100];
    strcpy(buffer,".");
    strcat(buffer,address);
    strcpy(address,buffer);
}

//Main Functions 

void createfile (char* address){
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
                            mkdir(str,0777);
                            strcpy(str,"./root/");
                            //          /root/dir1/dir2/kiani.txt
                            int j =7;
                            for (int i=7;i<strlen(address)-1;i++){
                                if (address[i]=='/'){
                                    strncpy(sup,address+j,i-j);
                                    strncat(str,sup,i-j);
                                    mkdir(str,0777);
                                    strncat(str,&address[i],1);
                                    j=i+1;
                                                     }
                                                                }
                            strcpy(sup,".");
                            strncat(sup,&address[0]+1,strlen(address)-2);
                            if(exists(sup)==true){
                                printf("File Existed\n");
                                return ;
                                                }
                            else {
                                FILE *file;
                                file = fopen(sup,"w");
                                fclose(file);
                                }
                            }
                            else {
                                printf("Invalid Input\n");
                                 return;
                                    }
         }
         }
                    else {
                        printf("Invalid Input\n");
                        return;
                        }
        }     
        else {printf("Invalid Input\n");return;}
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
                mkdir(str,0777);
                strcpy(str,"./root/");
                //          /root/dir1/dir2/kiani.txt
                int j =6;
                for (int i=6;i<strlen(address);i++){
                if (address[i]=='/'){
                strncpy(sup,address+j,i-j);
                strncat(str,sup,i-j);
                mkdir(str,0777);
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
               //printf("%s",sup);
               file = fopen(sup,"w");
               fclose(file);}
         }
         else {
             printf("Invalid Input\n");
             return;
         }
         }
   }
}
void cat (char*address){
    int check = check_all(address);
    char buff [100] ;
    //printf("%s",address);
    FILE* fptr ;
    fptr = fopen(address,"r");
    if (fptr == NULL) {perror("ERROR OPENING FILE");return;}
    int c;
    do {
    c=fgetc(fptr);
    if(c!=EOF)printf("%c",(char)c);
    }while(c!=EOF);
    //printf("\n");
    fclose(fptr);
        
}
void insertstr(char* address,char * str,int line ,int pos){
    //CHECK VALIDITY
    int check = check_all (address);
    if (check)return;
    //ADDRESS
    FILE * fptr;
    char add[1000];
    strcpy(add,address);
    //MAIN
    fptr = fopen (add,"r+");
    int n = what_is_the_position(fptr,line , pos);
    fseek(fptr,0,SEEK_SET);
    FILE * sptr ;
    sptr = fopen ("./root/clipboar" , "w+");
    /*int ret = system("chmod 777 ~/project/root/CLIPBOARD");
    sscanf(address,"chmod 777 ~/project%s",address);
    ret = system(address);*/
    if (pos==0){
    n--;
    CopyFile(fptr,sptr,0,n);
    fputs (str,sptr);
    fseek(fptr,0,SEEK_SET);
    int k = number_of_charactars(fptr);
    fseek(fptr,0,SEEK_SET);
    CopyFile(fptr,sptr,n+1,k-1);
    //exit(1);
    fseek(fptr,0,SEEK_SET);
    fseek(sptr,0,SEEK_SET);
    //exit(1);
    CopyFile(sptr,fptr,0,k+strlen(str)-1);
    //exit(1);
    fflush(fptr);
    //exit(1);  
    fclose (fptr);
    fclose (sptr);
    remove("./root/clipboar");
    }
    else {
    CopyFile(fptr,sptr,0,n-1);
    fputs (str,sptr);
    fseek(fptr,0,SEEK_SET);
    int k = number_of_charactars(fptr);
    fseek(fptr,0,SEEK_SET);
    
    CopyFile(fptr,sptr,n,k-1);
    //exit(1);
    fseek(fptr,0,SEEK_SET);
    fseek(sptr,0,SEEK_SET);
    //exit(1);
    CopyFile(sptr,fptr,0,k+strlen(str)-1);
    //exit(1);
    fflush(fptr);
    //exit(1);  
    fclose (fptr);
    fclose (sptr);
    remove("./root/clipboar");
}
}
void removestr(char * address , int line , int pos, int size , int mode){
    int check = check_all (address);
    if (check)return;
    //ADDRESS
    char add[1000];
    strcpy(add,address);
    FILE* fptr ;FILE * sptr;FILE* tptr;
    if (mode ==0) {
        //FORWARD 
        fptr = fopen (add,"r+");
        sptr = fopen("./root/clipboar","w+");
        //tptr = fopen("./root/TEMPORARY","w+");
        int n = what_is_the_position(fptr,line,pos);
        fseek(fptr,0,SEEK_SET);
        int k = number_of_charactars(fptr);
        fseek(fptr,0,SEEK_SET);
        CopyFile(fptr,sptr,0,n-1);
        fseek(fptr,0,SEEK_SET);
        CopyFile(fptr,sptr,n+size,k-1);
        rename ("./root/clipboar",add);
        fclose (fptr);fclose(sptr);
    }
    else if (mode ==1){
        //BACKWARD
        fptr = fopen (add,"r+");
        sptr = fopen("./root/clipboar","w+");
        //tptr = fopen("./root/TEMPORARY","w+");
        int  n = what_is_the_position(fptr,line,pos);
        fseek(fptr,0,SEEK_SET);
        int k = number_of_charactars(fptr);
        fseek(fptr,0,SEEK_SET);
        CopyFile(fptr,sptr,0,n-size);
        fseek(fptr,0,SEEK_SET);
        CopyFile(fptr,sptr,n+1,k-1);
        rename ("./root/clipboar",add);
        fclose (fptr);fclose(sptr);
    }
}
void copy(char * address , int line , int pos, int size , int mode){
    int check = check_all (address);
    if (check)return;
    //ADDRESS
    char add[1000];
    strcpy(add,address);
    FILE* fptr ;FILE * sptr;
    if (mode ==0) {
        //FORWARD 
        fptr = fopen (add,"r+");
        sptr = fopen("./root/.CLIPBOARD","w+");
        int n = what_is_the_position(fptr,line,pos);
        //printf("%d\n",n);
        fseek(fptr,n,SEEK_SET);
        int x ;
        //printf("%d\n",x);
        int a=0;
        while(a<size){
            ++a;
            int q=fgetc(fptr);
            //x =q-'0';printf("%d\n",x);
            fputc(q,sptr);
        }
        fclose (fptr);fclose(sptr);
    }
    else if (mode ==1){
        //BACKWARD
        fptr = fopen (add,"r+");
        sptr = fopen("./root/.CLIPBOARD","w+");
        int n = what_is_the_position(fptr,line,pos);
        //printf("%d",n);
        fseek(fptr,n-size+1,SEEK_SET);
        int a=0;
        while(a<size){
            fseek(fptr,n-a,SEEK_SET);
            ++a;
            int q=fgetc(fptr);
            printf("%d",q-'0');
            fputc(q,sptr);
        }
        fclose (fptr);fclose(sptr);
    }
}
void cut (char * address , int line , int pos, int size , int mode){
    int check = check_all (address);
    if (check)return;
    //ADDRESS
    char add[1000];
    strcpy(add,address);
    FILE* fptr ;FILE * sptr;FILE* tptr;
    if (mode ==0) {
        //FORWARD 
        fptr = fopen (add,"r+");
        sptr = fopen("./root/.CLIPBOARD","w+");
        //tptr = fopen("./root/TEMPORARY","w+");
        int n = what_is_the_position(fptr,line,pos);
        fseek(fptr,0,SEEK_SET);
        int k = number_of_charactars(fptr);
        fseek(fptr,0,SEEK_SET);
        CopyFile(fptr,sptr,0,n-1);
        fseek(fptr,0,SEEK_SET);
        CopyFile(fptr,sptr,n+size,k-1);
        rename ("./root/.CLIPBOARD",add);
        fclose(sptr);
        sptr = fopen("./root/CLIPBOARD","w+");
        fseek(fptr,0,SEEK_SET);
        CopyFile(fptr,sptr,n,n+size-1);
        fclose (sptr);fclose (fptr);
    }
    else if (mode ==1){
        //BACKWARD
        fptr = fopen (add,"r+");
        sptr = fopen("./root/.CLIPBOARD","w+");
        int n = what_is_the_position(fptr,line,pos);
        fseek(fptr,0,SEEK_SET);
        int k = number_of_charactars(fptr);
        fseek(fptr,0,SEEK_SET);
        CopyFile(fptr,sptr,0,n-size);
        fseek(fptr,0,SEEK_SET);
        CopyFile(fptr,sptr,n+1,k-1);
        rename ("./root/.CLIPBOARD",add);
        fclose(sptr);
        sptr = fopen("./root/.CLIPBOARD","w+");
        fseek(fptr,0,SEEK_SET);
        CopyFile(fptr,sptr,n-size+1,n);
        fclose (sptr);fclose (fptr);
    }
}
void paste (char* address,int line , int pos ) {
    int check = check_all (address);
    if (check)return;
    //ADDRESS
    FILE * fptr;
    char add[1000];
    strcpy(add,address);
    //MAIN
    fptr = fopen (add,"r+");
    int n = what_is_the_position(fptr,line , pos);
    fseek(fptr,0,SEEK_SET);
    FILE * sptr ;
    sptr = fopen ("./root/clipboar" , "w+");
    /*int ret = system("chmod 777 ~/project/root/CLIPBOARD");
    sscanf(address,"chmod 777 ~/project%s",address);
    ret = system(address);*/
    FILE * clip;
    clip = fopen ("./root/.CLIPBOARD","r+");
    int q= number_of_charactars(clip);
    if (q==0) return ;
    if (pos==0){
    
    n--;
    CopyFile(fptr,sptr,0,n);
    
    for (int i=0;i<q;++i){
        int c = fgetc(clip);
        fputc(c,sptr);
    }
    fseek(fptr,0,SEEK_SET);
    int k = number_of_charactars(fptr);
    fseek(fptr,0,SEEK_SET);
    
    CopyFile(fptr,sptr,n+1,k-1);
    //exit(1);
    fseek(fptr,0,SEEK_SET);
    fseek(sptr,0,SEEK_SET);
    //exit(1);
    CopyFile(sptr,fptr,0,k+q-1);
    //exit(1);
    fflush(fptr);
    //exit(1);  
    fclose (fptr);
    fclose (sptr);
    remove("./root/clipboar");
    }
    else {
    CopyFile(fptr,sptr,0,n-1);
    for (int i=0;i<q;++i){
        int c = fgetc(clip);
        fputc(c,sptr);
    }
    //fputs (str,sptr);
    fseek(fptr,0,SEEK_SET);
    int k = number_of_charactars(fptr);
    fseek(fptr,0,SEEK_SET);
    
    CopyFile(fptr,sptr,n,k-1);
    //exit(1);
    fseek(fptr,0,SEEK_SET);
    fseek(sptr,0,SEEK_SET);
    //exit(1);
    CopyFile(sptr,fptr,0,k+q-1);
    //exit(1);
    fflush(fptr);
    //exit(1);  
    fclose (fptr);
    fclose (sptr);
    remove("./root/clipboar");
}
}
