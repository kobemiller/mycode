#include <curses.h>

int main()
{
    
    initscr(); //初始化终端
    //border(0, 0, 0, 0, 0, 0, 0, 0);
    //另外一种方法
    //WINDOW *w = initscr();
    //box(w, 0, 0);
    box(stdscr, 0, 0);

    //水平线
    mvhline(2, 10, '*', 20); 
    //垂直线
    mvvline(2, 10, '&', 20);

    //刷屏
    refresh();

    getch();    //等待一个字符的输入
    endwin();   //释放终端

    return 0;
}
