//In The Name Of Allah

#include "FunctionHeader.h"
#define TAB "    "
//#Problems :
//createfile is ok
//cat is ok
//insertstr "" for string
//remove  0 1 + Error EOF &0
//copy    0 1 + Error EOF &0
//cut     
//paste
//find
//replace
//greb
//undo
struct finder {
    int size;
    int* by_position;
    int* by_word;
    int count;
};

void print_array(int array[],int n);
void assign_spaces (char *source, int spaces[]);
void assign_arrays (char * before, char * after , char*  source, int befend[], int afterst[]);
struct finder* find (char * source , char * text);
#define exists file_exists

int main(){
    FILE * fptr;
    //fptr =fopen("./root/m","r+");
    char try[1000];strcpy(try,"/root/m");
    char text[1000];
    strcpy(text,"abcd");
    //find(try,text);
    //exit(1);
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
        //printf("%s\n%s\n%d\n%d\n%c\n%c\n",address,other,line,pos,size,how);
    }
}  
}

// General Functions

int number_of_charactars (FILE *fptr ){
    int c ;
    int n =0;
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

// Main Functions 

void createfile (char* address){
        if (address[0]=='"'){
            //exit(1);
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
                        //print_string(buffer,strlen(buffer));
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
    ptr->by_position=(int*)(malloc (sizeof(int) *strlen(source)));
    ptr->by_word=(int *)(malloc(sizeof(int)*strlen(source)));

    //Creating Struct Components

    int by_word [strlen(source)];
    int by_position[strlen(source)];

    //Spaces

    int spaces[strlen(source)];
    assign_spaces(source,spaces);

    //Assigning Initial Structs Situations

    for(int i=0;i<strlen(source);++i){
        by_position[i] = -1;
        by_word[i] = -1;
        ptr->by_position[i] = -1;
        ptr->by_word[i] = -1;
    }
    int count =0;
    //ASSESS DIFFERENT TYPES OF INPUT
    bool two_part =false;
    bool star_exist = false;
    char * before ;char * after;

    //Before & After

    bool bf ;

    if(text[0]=='*') {
            after= (char*) malloc(sizeof(char)*strlen(source));
            star_exist= true;
            strncpy(after,text+1,strlen(text)-1);
            bf = true;
        }
        else if (text[strlen(text)-1]=='*') {
            before=(char*)malloc(sizeof(char)*strlen(source));
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
                    for (int i =0;i<strlen(source);++i) {
                        if (!befend[i]){
                            max_after[i]=i;
                            for(int j=i+1;j<strlen(source);j++){
                                if(spaces[j]){max_after[i]=j;}
                                if(!spaces[j])break;
                            }
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