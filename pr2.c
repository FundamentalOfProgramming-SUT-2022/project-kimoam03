#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rf refresh()
#define MX_H 2000
int numberofdecimal(int k){
    int i=1;
    while(k/10>0){
        ++i;
        k/=10;
    }
    return i;
}
void to_end_index(int end,WINDOW* index){
    for(int i=end;i<LINES-2;++i){
        mvwprintw(index,i,0,"   ~");
    }
}
void alter_index (int beg,int end,WINDOW*index){
    if(end>beg+LINES-3){
        char *spaces = calloc(10,sizeof(char));
        for(int i=beg;i<=beg+LINES-3;++i){
            spaces = calloc(10,sizeof(char));
            int c = 4-numberofdecimal(i);
            while(c--){
                strcat(spaces," ");
            }
            mvwprintw(index,i,0,"%s%d",spaces,i);
        }
    }
    else {
        char *spaces = calloc(10,sizeof(char));
        for(int i=beg;i<=end;++i){
            spaces = calloc(10,sizeof(char));
            int c = 4-numberofdecimal(i);
            while(c--){
                strcat(spaces," ");
            }
            mvwprintw(index,i,0,"%s%d",spaces,i);
        }
    }
    to_end_index(end,index);  
}
void alter_main(int beg,int end,WINDOW* main,int lines[],int n){
    return;
}

void move_right(WINDOW* main,int lines[],int n){
    int r,c;
    getyx(main,r,c);
    if(c<lines[r])wmove(main,r,c+1);
}

void move_left(WINDOW* main,int lines[],int n){
    int r,c;
    getyx(main,r,c);
    if(c>0)wmove(main,r,c-1);
}
void move_down(WINDOW* main , int lines[],int n){
    int max_r,max_c;
    int r ,c;
    getmaxyx(main,max_r,max_c);
    getyx(main,r,c);
    if(c<=lines[r+1])wmove(main,r+1,c);
    else if(c>lines[r+1]){
        wmove(main,r+1,lines[r+1]);
    }
}
void move_up(WINDOW* main,int lines[],int n){
    int max_r,max_c;
    int r ,c;
    getmaxyx(main,max_r,max_c);
    getyx(main,r,c);
    if(c<=lines[r-1])wmove(main,r-1,c);
    else if(c>lines[r-1]){
        wmove(main,r-1,lines[r-1]);
    }
}
int main () {
    char *buffer=calloc(1000,sizeof(char));
    initscr();
    cbreak();
    //noecho();
    if(has_colors()==FALSE){
        printf("color does not suppuroted\n");
    }

    char * MODE = calloc(40,sizeof(char));
    strcpy(MODE,"NORMAL");
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_CYAN);
    init_pair(2,COLOR_WHITE,COLOR_BLACK);
    init_pair(3,COLOR_BLUE,COLOR_WHITE);
    
    WINDOW* main=newwin(LINES-2,COLS-4,0,4);
    wbkgd(main,COLOR_PAIR(2));

    WINDOW* commandbar=newwin(1,COLS,LINES-1,0);
    wbkgd(commandbar,COLOR_PAIR(2));

    WINDOW* info= newwin(1,COLS-10,LINES-2,10);
    wbkgd(info,COLOR_PAIR(2));

    WINDOW* index=newwin(LINES-2,4,0,0);
    wbkgd(index,COLOR_PAIR(3));
    WINDOW* mode = newwin(1,10,LINES-2,0);wbkgd(mode,COLOR_PAIR(1));

    scrollok(main, TRUE);scrollok(index, TRUE);scrollok(mode, TRUE);scrollok(info, TRUE);scrollok(commandbar, TRUE);
    wrefresh(main);wrefresh(index);wrefresh(info);wrefresh(commandbar);wrefresh(mode);
    refresh();

    int written = 20;
    char* spaces =calloc(10,sizeof(char));
    alter_index(0,written,index);
    wrefresh(index);rf;
    mvwprintw(mode,0,0,"  %s",MODE);mvwprintw(info,0,0,"  amin.txt --unsaved  ");wrefresh(info);
    wrefresh(mode);
    int lines [20]= {0,1,2,3,4,5,6,7,8,9,9,8,7,6,5,4,3,2,1,0};
    noecho();
    while(1){
        char c = getch();
        if(c==27){
            wmove(main,0,0);wrefresh(main);
            while(c!=':'||c!='/' || c!='v' || c!='i'){
                c=getch();
                if(c=='l')move_right(main,lines,20);
                if(c=='k')move_up(main,lines,20);
                if(c=='j')move_down(main,lines,20);
                if(c=='h')move_left(main,lines,20);
                wrefresh(main);
            }
        }

    }
    endwin();
}