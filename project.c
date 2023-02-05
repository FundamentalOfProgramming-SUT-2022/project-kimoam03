//In The Name Of Allah
#define exists file_exists
#include "FunctionHeader.h"
#define TAB "    "
int max(int a,int b){
    return a*(a>=b)+b*(b>a);
}
//#Problems :
//createfile is ok
//cat is ok
//cut   is ok   
//paste is ok 
//undo IS OK
//find is ok ?
//replace 
//insertstr "" for string
//remove  0 1 + Error EOF &0
//copy    0 1 + Error EOF &0

//CHECKS for phase_1 :
// INPUTS
// CHECK REMOVE
// GREB FOR '\N' NULL OR \N\N
// TEXT_COMPARATOR FOR '\N' NULL OR \N\N
// CHECK FIND -> CHECK REPLACE(END OF POSITION FOR A* B)
// CHECK ALL OF CODE


struct undoer {
    char* address_of_me;
    struct undore* before;
};
struct finder {
    int size;
    int* by_position;
    int* by_word;
    int count;
};
struct greber {
    int count ;
    char *lines[20000];
    int number_of_line[20000];
    char *files[20000];
};
struct comparator {
    int count ;
    char *lines[20000];
    int number_of_line[20000];};
void tree(char *address, const int root, int depth);
void autoindent(char * address);
int main(){
    //tree("/root",0,-1);exit(1);
    char command[2000];char command_type[2000];char other[2000];char address[2000];char useless[2000];
    while(true)
    {
    scanf("%[^\n]%*c",command);
    sscanf(command,"%s %[^\n]%*c",command_type,other);
    //close command : default
    if(!strcmp(command ,"close")){
        printf("HAVE A GOOD DAY\n");
        break;
    }
    else if(strcmp(command_type,"createfile")==0){
       sscanf(other,"%s %[^\n]%*c",useless,address);
        //printf("%s",address);exit(1);
        createfile(address);
   }  
    else if(strcmp(command_type,"insertstr")==0){
       //printf("%d",1);
       //insertstr -file /root/amin.txt -str salam -pos 200:5
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
        printf("%s\n",rest);//exit(1);
        int k =0;
        while(rest[k]!=':')++k;
        char *l= calloc(10,sizeof(char));
        strncpy(l,rest,k);
        strcat(l,"\0");
        printf("%s",l);
        line = atoi(l);
        printf("%d",l);
        exit(1);
        insertstr(address,str,line ,pos);
    
   }
    else if (!strcmp(command_type,"cat")){
        sscanf(other,"%s %[^\n]",useless,address);
        cat(address);
   } 
    else if (!strcmp(command_type,"removestr")){
            int line ,  pos ,  size;
            int invalid ;
            char c;
            invalid = sscanf(other, "--pos %d:%d -size %d -%c --file %[^\n]*c", &line, &pos, &size, &c, address);
            char* add = calloc(100,sizeof(char));
            int t;
            if(c=='f')t=0;
            else if(c=='b')t=1;
            if (invalid != 5){
                continue;
            }
            else if(*address=='"'){
                for (int i = 1; i < strlen(address)-1; i++){
                    *(add+i-1) = *(address+i);
                }
                removestr(add, line, pos, size,t);
            }
            else{
                removestr(address, line, pos, size,t);
            }
        }
    else if (!strcmp(command_type,"copystr")){
        int line ,  pos ,  size;
            int invalid ;
            char c;
            invalid = sscanf(other, "--pos %d:%d -size %d -%c --file %[^\n]*c", &line, &pos, &size, &c, address);
            char* add = calloc(100,sizeof(char));
            int t;
            if(c=='f')t=0;
            else if(c=='b')t=1;
            if (invalid != 5){
                continue;
            }
            else if(*address=='"'){
                for (int i = 1; i < strlen(address)-1; i++){
                    *(add+i-1) = *(address+i);
                }
                copy(add, line, pos, size,t);
            }
            else{
                copy(address, line, pos, size,t);
            }
    }
    else if (!strcmp(command_type,"cutstr")){
        int line ,  pos ,  size;
            int invalid ;
            char c;
            invalid = sscanf(other, "--pos %d:%d -size %d -%c --file %[^\n]*c", &line, &pos, &size, &c, address);
            char* add = calloc(100,sizeof(char));
            int t;
            if(c=='f')t=0;
            else if(c=='b')t=1;
            if (invalid != 5){
                continue;
            }
            else if(*address=='"'){
                for (int i = 1; i < strlen(address)-1; i++){
                    *(add+i-1) = *(address+i);
                }
                cut(add, line, pos, size,t);
            }
            else{
                cut(address, line, pos, size,t);
            }
    }
    else if (!strcmp(command_type,"pastestr")){
        int line ,  pos ;
            int invalid ;
            char c;
            invalid = sscanf(other, "--pos %d:%d --file %[^\n]*c", &line, &pos, address);
            char* add = calloc(100,sizeof(char));
            if(*address=='"'){
                for (int i = 1; i < strlen(address)-1; i++){
                    *(add+i-1) = *(address+i);
                }
                paste(add, line, pos);
            }
            else{
                paste(address, line, pos);
            }
            //printf("%s",address);exit(1);
    }
    else if (!strcmp(command_type,"find")){

    }
    else if (!strcmp(command_type,"replace")){

    }
    else if (!strcmp(command_type,"greb")){

    }
    else if (!strcmp(command_type,"undo")){
        sscanf(other,"%s %[^\n]",useless,address);
        undo(address);
    }
    else if (!strcmp(command_type,"auto")){
        sscanf(other,"%s %[^\n]",useless,address);
        autoindent(address);
    }
    else if (!strcmp(command_type,"compare")){
        char* first = calloc(100,sizeof(char));
        char* second = calloc(100,sizeof(char));
        sscanf(other,"%s %s",first,second);
        //printf("%s\n%s",first,second);exit(1);
        text_comparator(first,second);
    }
    else if (!strcmp(command_type,"tree")){
        //printf("%s",other);exit(1);
        int k ;
        k=atoi(other);
        //printf("%d\n",k);exit(1);
        if(k<-2)puts("Wrong Depth");
        else
            tree("./root",0,k);
    }
    else {
        puts("Invalid Input");
    }
}  
}

// General Functions

char* HiddenFile (char *address){
    int dash;
    char * NOF = calloc(2000,sizeof(char));
    for (int q =0;q<strlen(address);++q){if(address[q]=='/')dash=q;}
    strncpy(NOF,address,dash+1);
    strcat(NOF,".");
    strcat(NOF,address+dash+1);
    return NOF;
}
void createbackup(char* address,int t) {
    FILE* sptr ;
    char * add;
    add = HiddenFile(address);
    char *buff = calloc(1000,sizeof(char));
    sprintf(buff,"%d",t);
    strcat(add,buff);
    sptr = fopen(add,"w+");
    FILE* fptr ;fptr= fopen (address,"r+");
    int q = number_of_charactars(fptr)-1;
    fseek(fptr,0,SEEK_SET);
    CopyFile(fptr,sptr,0,q);
    fclose(fptr);
    fclose(sptr);
}
void CopyFile (FILE * fptr ,FILE* sptr, int from , int to ) {
    int n = 0;
    int c;
    while (n<from){
        c = fgetc(fptr);++n;
    }
    while (n<=to) {
        c = fgetc(fptr);
        fputc(c,sptr);
        ++n;
    }
}
void StringToFile (char* str,FILE*fptr,int max){
    fseek(fptr,0,SEEK_SET);
    char *buff=calloc(max,sizeof(char));
    //print_string(str,5);
    //exit(1);
    for(int i=0;i<max;++i){
        int c = atoi(buff[i]);
        fputc(c,fptr);
    }
    fseek(fptr,0,SEEK_SET);
    return ;
}
char* FileToString (FILE* fptr){

    char* str;
    int t = number_of_charactars(fptr)-1;
    fseek(fptr,0,SEEK_SET);
    str = calloc(t,sizeof(char));
    for(int i=0;i<t;++i){
        int c = fgetc(fptr);
        //printf("%d",c);
        str[i]= (char)c;
        //printf("%c",str[i]);
    }
    //exit(1);
    fseek(fptr,0,SEEK_SET);
    return str;

}
int number_of_charactars (FILE *fptr ){
    int c ;
    int n =0;
    do {
        c = fgetc(fptr);
        if (c!=EOF)++n;
    }while(c!=EOF);
    return n;
}
int number_of_lines (FILE* fptr){
    int n = 1;
    int c ;
    c = fgetc(fptr);
    //printf("%c",c);
    while (c!= EOF) {
        if (c =='\n') n++;
        c = fgetc(fptr);
        //printf("%c",c);
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
bool file_exists(char *fname)
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
    char *str;str = (char*)malloc(2000*sizeof(char));char text[2000];
    //printf("%s\n",address);
    if(address[0] =='/'){
    //sscanf(text,"%s %[^\n]",sup,text);
    //printf("%s",sup);
    int j=0;
    for(int i=0;i<strlen(address);i++){
        if(address[i]=='/'){
            j=i;
        }
        }
        strcpy(str,".");
        strncat(str,address,j);
        //printf("%s",str);
    if(!folder_exists(str)){
        puts("Directory Does Not Exists");
        return -1;
        }  
    else {
    //printf("1");
        strcpy(str,".");
        strncat(str,address,strlen(address));
        //printf("%s",str);
        //print_string(str,strlen(str));
        if(!file_exists(str)){
            puts("File Does Not Exists");
            return -1;
        }
        strcpy(address,str);
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
void print_array(int array[],int n){
    for(int i =0;i<n;++i){
        printf("%d",array[i]);
    }
    printf("\n");return;
}
void print_string(char array[],int n){
    for(int i =0;i<n;++i){
        printf("%c",array[i]);
    }
    printf("\n");return;
}
void assign_spaces (char *source, int spaces[]){
    for (int i=0;i<strlen(source);++i)spaces[i]=-1;
    for (int i=0;i<strlen(source);++i){
        //printf("%c",source[i]);
        if (source[i]==' ')
            spaces[i] = 0;
    }
    return;
}
void assign_arrays (char * before, char * after , char*  source, int befend[], int afterst[]) 
{
    for (int i=0;i<strlen(source);++i)befend[i]=-1;
    for (int i=0;i<strlen(source);++i)afterst[i]=-1;
    for (int i =0;i<strlen(source);++i){
        int k =0;
        for (int j=0;j<strlen(before);j++){
            if(before[j]==source[i+j])++k;
        }
        if (k==strlen(before)){
            befend[i+k-1]=0;
        }
    }
    for (int i =0;i<strlen(source);++i) {
        int k =0;
        for (int j=0;j<strlen(after);j++){
            if(after[j]==source[i+j])++k;
        }
        //printf("%d\n",k);
        if (k==strlen(after)){
            afterst[i]=0;
        }
    }
}
/*void print_find (struct finder* ptr,int mode[4]) {
    //count is ok with every thing
    //at != byword != all
    if(mode[1]+mode[2]+mode[3]>=2){
        printf("Conflicted Swithces\n");
        return;
    }
    if(mode[0]) {
        //count 
        if(ptr->count == 0){
            printf("%d\n",-1);
        }
        else {
            printf("%d\n",ptr->count);
        }
    }
    if(mode[1]){
        //at
        int at =mode[1];
        int k=0;
        for (int i =0;i<strlen(ptr->by_position);++i){
            if(ptr->by_position[i]!=-1)++k;
            if(k==at){
                printf("%d\n",ptr->by_position[i]);
            }
        }
        if(k<at){
            printf("%d\n",-1);
        }
    }
    if(mode[2]){
        //byword
        for (int i =0;i<strlen(ptr->by_position);++i){
            if(ptr->by_position[i]!=-1){printf("%d\n",ptr->by_word[i]);break;}
        }
    }
    if (mode [3]){
        //all
        for (int i =0;i<strlen(ptr->by_position);++i){
            if(ptr->by_position[i]!=-1){printf("%d\n",ptr->by_word[i]);}
        }
    }
    return;
}*/
void copy_str(char *det,char* origin,int size){
    for (int i =0;i<size;++i){
        *(det+i)=*(origin+i);
    }
    *(det+size) = '\0';
    return;
}
int largest_number_for_undo (char * address){
    char * NOF = HiddenFile(address);
    int k =0;
    char* buff = calloc(2000,sizeof(char));
    char* tuff= calloc(1000,sizeof(char));
    sprintf(tuff,"%d",k+1);
    strcpy(buff,NOF);
    strcat(buff,tuff);
    while (file_exists(buff)){
        ++k;
        sprintf(tuff,"%d",k+1);
        strcpy(buff,NOF);
        strcat(buff,tuff);
    }
    return k;
}

//Main Functions 

void createfile (char* address){
        if (address[0]=='"'){
                int j =0;
                char buffer [2000];
                for (int i =1;i<strlen(address)-2;++i){
                    if(address[i]=='/'){
                        strcpy(buffer,".");
                        strncat(buffer,address+1,i-1);
                        mkdir(buffer,0777);
                        //print_string(buffer,strlen(buffer));
                    }
                }
                strcpy(buffer,".");
                strncat(buffer,address+1,strlen(address)-2);
                if(file_exists(buffer)){
                    puts("File Already Existed!");return;
                }
                FILE *fptr;
                fptr = fopen(buffer,"w+");
                fclose(fptr);
                return;
        }
        else if (address[0] == '/'){
            int j =0;
            char buffer [2000];
            for (int i =1;i<strlen(address)-2;++i){
                if(address[i]=='/'){
                    strcpy(buffer,".");
                    strncat(buffer,address,i);
                    mkdir(buffer,0777);
                    }
            }
            strcpy(buffer,".");
            strncat(buffer,address,strlen(address));
            if(file_exists(buffer)){
                puts("File Already Existed!");return;
            }
            FILE *fptr;
            fptr = fopen(buffer,"w+");
            fclose(fptr);
            return;
         }
         }
void insertstr(char* address,char * str,int line ,int pos){
    //CHECK VALIDITY
    int check = check_all (address);
    if (check)return;
    //ADDRESS
    FILE * fptr;
    char add[1000];
    strcpy(add,address);
    //BACKUP
    int k = largest_number_for_undo(add);
    createbackup(add,k+1);
    //MAIN
    fptr = fopen (add,"r+");
    int n = what_is_the_position(fptr,line , pos);
    fseek(fptr,0,SEEK_SET);
    FILE * sptr ;
    sptr = fopen ("./root/clipboar" , "w+");
    if (pos==0){
    n--;
    CopyFile(fptr,sptr,0,n);
    fputs (str,sptr);
    fseek(fptr,0,SEEK_SET);
    int k = number_of_charactars(fptr);
    fseek(fptr,0,SEEK_SET);
    CopyFile(fptr,sptr,n+1,k-1);
    fseek(fptr,0,SEEK_SET);
    fseek(sptr,0,SEEK_SET);
    CopyFile(sptr,fptr,0,k+strlen(str)-1);
    fflush(fptr);  
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
    fseek(fptr,0,SEEK_SET);
    fseek(sptr,0,SEEK_SET);
    CopyFile(sptr,fptr,0,k+strlen(str)-1);
    fflush(fptr);  
    fclose (fptr);
    fclose (sptr);
    remove("./root/clipboar");
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
void removestr(char * address , int line , int pos, int size , int mode){
    int check = check_all (address);
    if (check)return;
    //ADDRESS
    char add[1000];
    strcpy(add,address);
    //BACKUP
    int k = largest_number_for_undo(add);
    createbackup(add,k+1);
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
    //BACKUP
    int k = largest_number_for_undo(add);
    createbackup(add,k+1);
    FILE* fptr ;FILE * sptr;
    if (mode ==0) {
        
        //FORWARD 
        fptr = fopen (add,"r+");
        sptr = fopen("./root/.CLIPBOARD","w+");
        int n = what_is_the_position(fptr,line,pos);
        //printf("%d\n",n);
        fseek(fptr,n,SEEK_SET);
        int a=0;
        while(a<size){
            ++a;
            int q=fgetc(fptr);
            //x =q-'0';printf("%d\n",x);
            //printf("%c",(char)q);
            fputc(q,sptr);
        }
        fclose (fptr);fclose(sptr);//exit(1);
    }
    else if (mode ==1){
        //BACKWARD
        fptr = fopen (add,"r+");
        sptr = fopen("./root/.CLIPBOARD","w+");
        int n = what_is_the_position(fptr,line,pos);
        //printf("%d",n);
        fseek(fptr,n-size+1,SEEK_SET);
        int a=size-1;
        while(a>=0){
            fseek(fptr,n-a,SEEK_SET);
            --a;
            int q=fgetc(fptr);
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
    //BACKUP
    int k = largest_number_for_undo(add);
    createbackup(add,k+1);
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
    //BACKUP
    int k = largest_number_for_undo(add);
    createbackup(add,k+1);
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
    fseek(clip,0,SEEK_SET);
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
    fseek(clip,0,SEEK_SET);
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
struct finder* find (char * address , char * text) {
    //DO THE ADDRESS
    int check = check_all (address);
    if (check)return NULL;
    //ADDRESS
    FILE * fptr;
    char add[1000];
    strcpy(add,address);
    //MAIN
    fptr = fopen (add,"r+");
    int t =number_of_charactars(fptr)-1;
    fseek(fptr,0,SEEK_SET);
    char * source = (char*)malloc (sizeof (char ) * t);
    for (int i=0;i<t-1;++i){
        char c = fgetc(fptr);
        char * l = &c;
        strcat(source,l);
    }
    //print_string(source,strlen(source));exit(1);
    //Creating Struct

    struct finder solver;
    struct finder *ptr = &solver;
    ptr->by_position=(int*)(malloc (sizeof(int) *t));
    ptr->by_word=(int *)(malloc(sizeof(int)*t));

    //Creating Struct Components

    int by_word [t];
    int by_position[t];

    //Spaces

    int spaces[t];
    assign_spaces(source,spaces);

    //Assigning Initial Structs Situations

    for(int i=0;i<t;++i){
        by_position[i] = -1;
        by_word[i] = -1;
        ptr->by_position[i] = 0;
        ptr->by_word[i] = 0;
    }
    int count =0;
    //ASSESS DIFFERENT TYPES OF INPUT
    bool two_part =false;
    bool star_exist = false;
    char * before ;char * after;

    //Before & After

    bool bf ;

    if(text[0]=='*') {
            after= (char*) malloc(sizeof(char)*t);
            star_exist= true;
            strncpy(after,text+1,strlen(text)-1);
            bf = true;
        }
        else if (text[strlen(text)-1]=='*') {
            before=(char*)malloc(sizeof(char)*t);
            star_exist= true;
            strncpy(before,text,strlen(text)-1);
            bf = false;
        }
    else {
    for (int i=0;i<strlen(text);++i){
            if(text[i]=='*' && text[i-1] !='\\') {
            star_exist= true;
            if(text[i-1] ==' ') {
                two_part=true;
                before = (char *) malloc(sizeof(char) *i);
                after = (char *) malloc(sizeof(char) *strlen(text)-i-1);
                strncpy(before,text,i);
                strncpy(after,text+i+1,strlen(text)-i-1);
                
            }
            else if (text[i+1] ==' '){
                two_part = true;
                before = (char *) malloc(sizeof(char) *i);
                after = (char *) malloc(sizeof(char) *strlen(text)-i-1);
                strncpy(before,text,i);
                strncpy(after,text+i+1,strlen(text)-i-1);
            }       
        }
        else if(text[i]=='*' && text[i-1] =='\\'){
            strncpy(text+i-1,text+i,strlen(text)-i);
        }
    }
    }

    //Befend and Afterst

    int befend[strlen(source)];
    int afterst [strlen(source)];
    if(two_part) assign_arrays(before,after,source,befend,afterst);
    else if (bf) {
        for (int i=0;i<strlen(source);++i)befend[i]=-1;
        for (int i=0;i<strlen(source);++i)afterst[i]=-1;
    //assigning befend
        for (int i =0;i<strlen(source);++i){
            befend[i]=0;
        }
        //assigning afterst
        for (int i =0;i<strlen(source);++i) {
            int k =0;
            for (int j=0;j<strlen(after);j++){
                if(after[j]==source[i+j])++k;
            }
            if (k==strlen(after)){
                afterst[i]=0;
            }
        }
    }
    else if (!bf){
         for (int i=0;i<strlen(source);++i)befend[i]=-1;
            for (int i=0;i<strlen(source);++i)afterst[i]=-1;
        //assigning afterst
        for (int i =0;i<strlen(source);++i){
            afterst[i]=0;
        }
        //assigning befend
        for (int i =0;i<strlen(source);++i){
            int k =0;
            for (int j=0;j<strlen(before);j++){
                if(before[j]==source[i+j])++k;
            }
            if (k==strlen(before)){
                befend[i+k-1]=0;
            }
        }
    }

    //Main Function

    int z=0;
    if (!two_part) {
        if(!star_exist) {
        //query with no *
            for (int i =0;i<strlen(source);++i) {
                int k =0;
                for (int j=0;j<strlen(text);j++){
                    if(text[j]==source[i+j])++k;
                }
                if (k==strlen(text)){
                    by_position[i] = 0;
                    ++count;
                    z=0;
                    for (int b=0;b<i;++b){if (!spaces[b])z++;}
                    by_word[z] = 0;
                }
             }
            for (int i =0;i<strlen(source);++i){
                ptr->by_position[i] = by_position[i];
                ptr->by_word[i] = by_word[i];
            }
            ptr->count = count;
        }
        else {
        //a*
            if(!bf){
                
                //a*()
                    //printf("%s",before);
                    //print_array(befend,strlen(source));exit(1);
                    int max_after[strlen(source)];
                    for (int i=0;i<strlen(source);++i)max_after[i]=0;
                    int c =0;
                    for (int i =0;i<strlen(source);++i) {
                        c=0;
                        if (!befend[i]){
                            max_after[i]=i;
                            for(int j=i+1;j<strlen(source);j++){
                                if(spaces[j]){max_after[i]=j;c=j;}
                                if(!spaces[j])break;
                            }
                        if(c)i=c;
                        }          
                    }
                    for (int i =0;i<strlen(source);++i) {
                        if(max_after[i]) {
                            ptr->by_position[i]=max_after[i];
                            for (int b=0;b<i;++b){if (!spaces[b])z++;}
                            ptr->by_word[i]=z;
                            ++count;
            }
        }
                    ptr->count = count;

                }
            
        //*a
            else if (bf){
                //find 
                //printf("%s",before);
                int max_after[strlen(source)];
                bool pass;int c=0;
                for (int i=0;i<strlen(source);++i)max_after[i]=0;
                for (int i =0;i<strlen(source);++i) {
                pass = false;
                if (!befend[i]){
                for(int j=i+1;j<strlen(source);j++){
                    if(!afterst[j]){max_after[i]=j;c=j;pass= true;}
                    if(!spaces[j]) break;
                }
            }
            if(pass){
                i=c-1;
            }   
        }
                    for (int i =0;i<strlen(source);++i) {
                        if(max_after[i]) {
                            ptr->by_position[i]=max_after[i];
                            for (int b=0;b<i;++b){if (!spaces[b])z++;}
                            ptr->by_word[i]=z;
                            ++count;
                         }
                    }
                    ptr->count = count;
            }
        }   
    }
    else {
        int maximal_after[strlen(source)];
        for(int i=0;i<strlen(source);++i) {maximal_after[i] = 0;}
        int c =0;
        bool pass ;
        for (int i =0;i<strlen(source);++i) {
            pass = false;
            if (!befend[i]){
                for(int j=i+1;j<strlen(source);j++){
                    if(!afterst[j]){maximal_after[i]=j;c=j;pass= true;}
                    if(!spaces[j]) break;
                }
            }
            if(pass){
                i=c-1;
            }   
        }
        for (int i =0;i<strlen(source);++i) {
            if(maximal_after[i]) {
                ptr->by_position[i]=maximal_after[i];
                for (int b=0;b<i;++b){if (!spaces[b])z++;}
                ptr->by_word[i]=z;
                ++count;
            }
        }
        ptr->count = count;
    }
    return ptr;
}
char* do_replace (char *source , char * pre ,char* after,int mode[2]){
    char * answer ;answer = (char*)malloc(sizeof(char)*strlen(source));
    struct finder * ptr = find(source,pre);
    if(mode[0]&&mode[1]){
        printf("You Can Not Give Both AT & ALL\n");return;
    }
    if (mode[0]){
        //at 
        int at =mode[0];
        int k=0;
        bool enough = false;
        for (int i=0;i<strlen(source);++i){
            if(ptr->by_position[i]!=-1)++k;
            if(k==at){
                enough = true;
                k=i;
            }
        }
        if(!enough){
            printf("Index Is High\n");return;
        }
        else {
            char buffer[strlen(source)];
            char secbuff[strlen(source)];
            strcpy(buffer,source+ptr->by_position[k]+1);
            strncpy(secbuff,source,k);
            copy_str(answer,secbuff,k);
            copy_str(answer+k,after,strlen(after));
            copy_str(answer+k+strlen(after),buffer,ptr->by_position[k]-k+1);
            printf("SUCCESS\n");return answer;
        }
    }
    else if(mode[1]){
        //all
        int j=0;
        for (int i =0;i<strlen(source);++i){
            if(ptr->by_position[i]!=-1){
                copy_str(answer+j,after,strlen(after));j+=strlen(after);
                i=ptr->by_position[i];
            }
            else {
                answer[j]=source[i];++j;
            }
        }
    printf("SUCCESS\n");
    return answer;   
    }
    else {
        int at = 1;
        int k=0;
        bool enough = false;
        for (int i=0;i<strlen(source);++i){
            if(ptr->by_position[i]!=-1)++k;
            if(k==at){
                enough = true;
                k=i;break;
            }
        }
        if(!enough){
            printf("Index Is High\n");return NULL;
        }
        else {
            char buffer[strlen(source)];
            char secbuff[strlen(source)];
            strcpy(buffer,source+ptr->by_position[k]+1);
            strncpy(secbuff,source,k);
            copy_str(answer,secbuff,k);
            copy_str(answer+k,after,strlen(after));
            copy_str(answer+k+strlen(after),buffer,ptr->by_position[k]-k+1);
            printf("SUCCESS\n");return answer;
        }
    }
}
void import_replace_to_file (char * address,char*final){
    FILE * fptr ;
    fptr = fopen(address,"w+");
    int t = strlen(final);int c;
    for (int i =0;i<t;++i){
        c = final[i];
        fputc(c,fptr);
    }
    fclose (fptr);
    //BACKUP
    int k = largest_number_for_undo(address);
    createbackup(address,k+1);
    return;
}
struct greber* greb (char *text , char* address[],int n) {
    struct greber *ptr;
    struct greber test;
    ptr = &test;
    ptr->count=0;
    for(int j=0;j<20000;++j){
    ptr->files[j]=calloc(strlen(address[0])*n*100,sizeof(char));
    ptr->lines[j]=calloc(n*2000,sizeof(char));
    ptr->number_of_line[j]=-1;
    }
    for (int i =0;i<n;++i) {
        FILE * fptr ;
        fptr = fopen(address[i],"r+");
        char* NOF;int dash;
        NOF = calloc(strlen(address[i]),sizeof(char));
        for (int q =0;q<strlen(address[i]);++q){if(*(address[i]+q)=='/')dash=q;}
        strcat(NOF,address[i]+dash+1);
        int line = 1;int t =number_of_charactars(fptr)-1;
        fseek(fptr,0,SEEK_SET);
        char * source;int c;
        int j =1;
        int lines[t];for(int i =0;i<t;++i) lines[i] =-1;
        for (int i=0;i<t;++i){
            c=fgetc(fptr);
            if (c=='\n'){lines[j]=i;++j;}
        }
        if(lines[0])lines[0]=0;int aftln;
        lines[j]=t;
        for (int q=0;q<j;++q){
            struct finder* find_ptr;
            aftln=lines[q];
            if(!aftln)aftln=-1;
            aftln++;
            fseek(fptr,aftln,SEEK_SET);
            source=calloc(t,sizeof(char));
            for(int i=0;i<lines[q+1]-lines[q];++i){
                c=fgetc(fptr);
                source[i]=c;
            }
            find_ptr = find(source,text);
            if (find_ptr->count>0){
                strcat(ptr->lines[ptr->count],NOF);
                strcat(ptr->lines[ptr->count],": ");
                strcat(ptr->lines[ptr->count],source);
                strcat(ptr->files[ptr->count],NOF);
                ptr->number_of_line[ptr->count] = q+1;
                ptr->count +=1;
            }
        }
        fclose(fptr);
    }
    return ptr;
}
void print_greb_lines(struct greber* ptr){
    char c;
    int k=0;
    c=*(ptr->lines[0]);
    while(c!='\0'){
            fputs(ptr->lines[k],stdout);
            printf("\n");
            ++k;
            c = *(ptr->lines[k]);
    }
    return ;
}
void print_greb_files(struct greber* ptr){
    char c;
    int k=0;
    c=*(ptr->files[k]);
    while(c!='\0'){
            fputs(ptr->files[k],stdout);
            printf("\n");
            ++k;
            c= *(ptr->files[k]);
    }
    return ;
}
void undo (char * address){
    int check = check_all (address);
    if (check)return;
    //ADDRESS
    char add[1000];
    strcpy(add,address);
    FILE* fptr ;
    int k = largest_number_for_undo(address);
    if (k==0)return;
    char* buff=HiddenFile(address);
    char * tuff = calloc(1000,sizeof(char));
    sprintf(tuff,"%d",k);
    strcat(buff,tuff);
    rename(buff,address);
    printf("Undo Terminated With Success\n");
    return;
}
struct comparator* text_comparator (char* first , char* second){
                            //Assign Struct
//=========================================================================
    struct comparator test;
    struct comparator * ptr ; ptr =&test;
    ptr->count=0;
    for(int j=0;j<20000;++j){
        ptr->lines[j]=calloc(20000,sizeof(char));
        ptr->number_of_line[j]=-1;
    }
                            //Check Input
//=========================================================================
    //printf("%s",second);exit(1);
    int check = check_all (first);
    if (check)return;
    //ADDRESS
    char frs[1000];
    strcpy(frs,first);
    check = check_all (second);
    if (check)return;
    //ADDRESS
    char scn[1000];
    strcpy(scn,second);
    strcpy(first,frs);strcpy(second,scn);  
                            //Number of characters and lines
//=========================================================================   
    FILE * fptr ; FILE * sptr ;
    fptr = fopen (first,"r+");sptr =fopen(second,"r+");
    fseek(fptr,0,SEEK_SET);
    fseek(sptr,0,SEEK_SET);
    int t_1 = number_of_charactars(fptr)-1;fseek(fptr,0,SEEK_SET);
    int t_2 = number_of_charactars(sptr)-1;fseek(sptr,0,SEEK_SET);
    int l_1 = number_of_lines(fptr)-1;fseek(fptr,0,SEEK_SET);
    int l_2 = number_of_lines(sptr)-1;fseek(sptr,0,SEEK_SET);
                            //Fixed Strings
//=========================================================================

    int c;
    char before [100]={'\0'};strcpy(before,"============ #");
    char after [100]={'\0'};strcpy(after," ============");
    char before_nxt [100] = {'\0'};strcpy(before_nxt,">>>>>>>>>>>> #");
    char after_nxt[100] =  {'\0'};strcpy(after_nxt," >>>>>>>>>>>>");
    
                            //Line Array Of First File
//=========================================================================

    fseek(fptr,0,SEEK_SET);
    int f =1;
    ++l_1;
    int lines_first[l_1];for(int i =0;i<l_1;++i) lines_first[i] =-1;

    for (int i=1;i<t_1;++i){
        c=fgetc(fptr);
        if (c=='\n'){lines_first[f]=i;++f;}
    }
    lines_first[f]=t_1;

    
    
                            //Line Array Of Second File
//==========================================================================
    fseek(sptr,0,SEEK_SET);
    ++l_2;
    int s =1;
    int lines_second[l_2];for(int i =0;i<l_2;++i) {lines_second[i] =-1;}
    for (int i=1;i<t_2;++i){
        c=fgetc(sptr);
        if (c=='\n'){lines_second[s]=i;++s;}
    }
    //if(lines_second[0])lines_second[0]=-1;
    lines_second[f]=t_2;

                            //Assign Files To Strings
//========================================================================= 

    fseek(fptr,0,SEEK_SET);fseek(sptr,0,SEEK_SET);
    char* fstfile =calloc(t_1,sizeof(char)); fstfile=FileToString(fptr);
    char* scndfile =calloc(t_2,sizeof(char)); scndfile= FileToString(sptr);
    //printf("%s",scndfile);exit(1);
    char* buffer = calloc(2000,sizeof(char));

                            //Comparasion
//==========================================================================
    //print_array(lines_second,l_2);exit(1);
    //printf("%d%d",l_1,l_2);exit(1);
    char* buff_first = calloc(t_1,sizeof(char));
    char* buff_second = calloc(t_2,sizeof(char));
    for(int i =0;i<l_1;++i){
        printf("%d ",lines_first[i]);
    }//exit(1);
    //print_string(scndfile,strlen(scndfile));exit(1);
    if (l_1>=l_2){
        for(int i =0;i<l_2-1;++i){
            if(i==0){
                buff_first = calloc(t_1,sizeof(char));
                buff_second = calloc(t_2,sizeof(char));
                strncpy(buff_first,fstfile,lines_first[1]);
                strncpy(buff_second,scndfile,lines_second[1]);
                //printf("%s",buff_first);exit(1);
            //print_string(buff_first,strlen(buff_first));
            }
            else {
            buff_first = calloc(t_1,sizeof(char));
            buff_second = calloc(t_2,sizeof(char));
            strncpy(buff_first,fstfile+lines_first[i],lines_first[i+1]-lines_first[i]);
            strncpy(buff_second,scndfile+lines_second[i],lines_second[i+1]-lines_second[i]);
            //printf("%c",(buff_first[0]));
            }
            //print_string(buff_first,lines_first[i+1]-lines_first[i]);
            if(strcmp(buff_first,buff_second)){
                strcpy(ptr->lines[ptr->count],before);
                sprintf(buffer,"%d",i);
                strcat(ptr->lines[ptr->count],buffer);
                strcat(ptr->lines[ptr->count],after);
                //strcat(ptr->lines[ptr->count],"\0");
                ptr->count +=1;
                strcpy(ptr->lines[ptr->count],buff_first);
                ptr->count +=1;
                strcpy(ptr->lines[ptr->count],buff_second);
                ptr->count +=1;
            }
        }
        buff_first = calloc(t_1,sizeof(char));
        buff_second = calloc(t_2,sizeof(char));
        l_1--;l_2--;
        strncpy(buff_first,fstfile[lines_first[l_2]+1],lines_first[l_1]-lines_first[l_2]);
        sprintf(buffer,">>>>>>>>>>>> #%d - #%d >>>>>>>>>>>>",l_2+1,l_1);
        strcpy(ptr->lines[ptr->count],buff_first);
        ptr->count +=1;
        print_comparator_lines(ptr);
        //exit(1);
    }
    else {
        for(int i =0;i<l_2-1;++i){
            if(i==0){
            strncpy(buff_first,fstfile[lines_first[i]+1],lines_first[1]);
            strncpy(buff_second,scndfile[lines_second[i]+1],lines_second[1]);
            }else {
            strncpy(buff_first,fstfile[lines_first[i]+1],lines_first[i+1]-lines_first[i]);
            strncpy(buff_second,scndfile[lines_second[i]+1],lines_second[i+1]-lines_second[i]);
            }
            if(!strcmp(buff_first,buff_second)){
                strcpy(ptr->lines[ptr->count],before);
                sprintf(buffer,"%d",i+1);
                strcat(ptr->lines[ptr->count],buffer);
                strcat(ptr->lines[ptr->count],after);
                ptr->count +=1;
                strcpy(ptr->lines[ptr->count],buff_first);
                ptr->count +=1;
                strcpy(ptr->lines[ptr->count],buff_second);
                ptr->count +=1;
            }
        }
        if(l_1==l_2)
        strncpy(buff_second,scndfile[lines_second[l_1]+1],lines_second[l_2]-lines_second[l_1]);
        sprintf(buffer,">>>>>>>>>>>> #%d - #%d >>>>>>>>>>>>",l_1+1,l_2);
        strcpy(ptr->lines[ptr->count],buffer);
        ptr->count +=1;       
        strcpy(ptr->lines[ptr->count],buff_first);
        ptr->count +=1;
    }
}
void print_comparator_lines(struct comparator* ptr){
    char c;
    int k=0;
    c=*(ptr->lines[1]);
    int mode =0;
    while(c!='\0'){
            print_string(ptr->lines[k],strlen(ptr->lines[k]));
            //printf("\n");
            ++k;
            c = *(ptr->lines[k]);
    }
    return ;
}
void autoindent(char *address)
{
    int check = check_all (address);
    if (check)return;
    //ADDRESS
    char add[1000];
    strcpy(add,address);
    int k = largest_number_for_undo(add);
    createbackup(add,k+1);
    FILE* fptr = fopen(address,"r+");
    int t= number_of_charactars(fptr)-1;
    char *file = calloc(2000,sizeof(char));
    fseek(fptr,0,SEEK_SET);
    file= FileToString(fptr);
    fseek(fptr,0,SEEK_SET);
    int level = 0;
    char buffer[] = {};
    char *ptr = file;char *sptr = buffer;
    int non = 0, spaces = 0;
    int newline = 1;
    while (*(ptr))
    {
        switch (*(ptr))
        {
        case '\n':
            if (newline){
                *(sptr) = '\n';
                sptr+=1;
            }
            newline = 1;
            non=0;
            spaces=0;
            break;
        case ' ':
            spaces+=1;
            break;
        
        case '\t':  
            spaces += 4;
            break;
        case '{':
            int t;
            if(non)t=1;
            else{t=4*level;}
            for (int i = 0; i < t; i++)
            {
                *(sptr) = ' '; 
                sptr++;
            }
            *(sptr) = '{', sptr++;
            *(sptr) = '\n', sptr++;
            level++;
            spaces = non = 0, newline = 0;
            break;
        case '}':
            level--;
            level = max(level, 0);
            if (non)
                *(sptr) = '\n', sptr++;
            for (int i = 0; i < 4 * level; i++)
                *(sptr) = ' ', sptr++;
            *(sptr) = '}', sptr++;
            *(sptr) = '\n', sptr++;
            spaces = non = 0, newline = 0;
            break;
        default:
            t;
            if(non)t=spaces;
            else{t=4*level;}
            for (int i = 0; i < t; i++)
            {
                *(sptr) = ' '; 
                sptr++;
            }
            *(sptr) = *(ptr), sptr++;
            spaces = 0;
            non=1 ;
            newline = 1;
            break;
        }
        ptr++;
    }
    fseek(fptr,0,SEEK_SET);
    fputs(buffer,fptr);
    fseek(fptr,0,SEEK_SET);
    fclose(fptr);
    //printf("%s\n",buffer);
}
void tree(char *address, const int root, int depth){
    int i;
    char final[1000];
    struct dirent *dp;
    DIR *dir = opendir(address);
    if (!dir){
        return;
    }
    while ((dp = readdir(dir)) != NULL){
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){
            for (i=0; i<root; i++){
                if (i%2 == 0 || i == 0){
                    printf("%c",179);
                }
                else{
                    printf(" ");
                }
            }
            printf("%c%c%s\n", 195, 196, dp->d_name);
            if((depth==-1)||(depth>=root/2+1)){
                strcpy(final, address);
                strcat(final, "/");
                strcat(final, dp->d_name);
                tree(final, root + 2, depth);
            }
        }
    }
    closedir(dir);
}

