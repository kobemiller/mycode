/*
 * =====================================================================================
 *
 *       Filename:  block.cpp
 *
 *    Description:  俄罗斯方块的linux版 
 *
 *        Version:  1.0
 *        Created:  2015年03月20日 09时31分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define TABLE_SIZE      20
#define BLOCK_SIZE      4
#define SLEEP_TIME      500

struct grid
{
    int x;
    int y;
};

class Block
{
public:
    enum direct {UP, DOWN, LEFT, RIGHT};    //定义方向
    grid g[BLOCK_SIZE];                     //方块的坐标信息

    void def_block(grid g1, grid g2, grid g3, grid g4);
    void rotate();                          //旋转方块
    void move(int dir);
    void set_cen(grid g);
    grid get_cen();
    void set_type(int t);
    int get_type();
    void back();
    void creat_block(int x, int y);

private:
    grid center;
    int type;
};

void Block::def_block(grid g1, grid g2, grid g3, grid g4)
{
    g[0] = g1;
    g[1] = g2;
    g[2] = g3;
    g[3] = g4;
}

void Block::rotate()
{
    int x, y, i = 0;
    for ( i; i <= 3; i++ )
    {
        x = g[i].x - center.x;
        y = g[i].y - center.y;
        g[i].x = center.x + y;
        g[i].y = center.y - x;
    }
}

void Block::move(int dir)
{
    int d = dir, i = 0;

    switch ( d )
    {
        case UP:
            for ( i; i <= 3; i++ )
                g[i].y++;
            center.y++;
            break;
        case DOWN:
            for ( i; i <= 3; i++ )
                g[i].y--;
            center.y--;
            break;
        case LEFT:
            for ( i; i <= 3; i++ )
                g[i].x--;
            center.x--;
            break;
        case RIGHT:
            for ( i; i <= 3; i++ )
                g[i].x++;
            center.x++;
            break;
    }
}

void Block::set_cen(grid g)
{
    center = g;
}

grid Block::get_cen()
{
    return center;
}

void Block::set_type(int t)
{
    type = t;
}

int Block::get_type()
{
    return type;
}

void Block::back()
{
    int x, y, i;
    for ( i = 0; i <= 3; i++ )
    {
        x = g[i].x - center.x;
        y = g[i].y - center.y;
        g[i].x = center.x - y;
        g[i].y = center.y + x;
    }
}

void Block::creat_block(int x, int y) 
{   //随机创建方块  
    int ran;  
    grid g[BLOCK_SIZE];  
  
    ran = 1 + rand() % 7;  
    switch ( ran ) 
    {  
    //L  
    case 1: {  
        g[0].x=x/2; g[0].y=y-3;  
        g[1].x=g[0].x; g[1].y=g[0].y+1;  
        g[2].x=g[0].x; g[2].y=g[0].y+2;  
        g[3].x=g[0].x+1; g[3].y=g[0].y;   
        set_cen(g[0]); set_type(1); break;  
            }  
    //反L  
    case 2: {  
        g[0].x=x/2; g[0].y=y-3;  
        g[1].x=g[0].x; g[1].y=g[0].y+1;  
        g[2].x=g[0].x; g[2].y=g[0].y+2;  
        g[3].x=g[0].x-1; g[3].y=g[0].y;   
        set_cen(g[0]); set_type(2); break;  
            }  
    //Z  
    case 3: {  
        g[0].x=x/2; g[0].y=y-2;  
        g[1].x=g[0].x; g[1].y=g[0].y+1;  
        g[2].x=g[0].x+1; g[2].y=g[0].y+1;  
        g[3].x=g[0].x-1; g[3].y=g[0].y;   
        set_cen(g[0]); set_type(3); break;  
            }  
    //反Z  
    case 4: {  
        g[0].x=x/2; g[0].y=y-2;  
        g[1].x=g[0].x; g[1].y=g[0].y+1;  
        g[2].x=g[0].x+1; g[2].y=g[0].y+1;  
        g[3].x=g[0].x-1; g[3].y=g[0].y;   
        set_cen(g[0]); set_type(4); break;  
            }  
    //田  
    case 5: {  
        g[0].x=x/2; g[0].y=y-2;  
        g[1].x=g[0].x; g[1].y=g[0].y+1;  
        g[2].x=g[0].x+1; g[2].y=g[0].y+1;  
        g[3].x=g[0].x+1; g[3].y=g[0].y;   
        set_cen(g[0]); set_type(5); break;  
            }  
    //1  
    case 6: {  
        g[0].x=x/2; g[0].y=y-3;  
        g[1].x=g[0].x; g[1].y=g[0].y+1;  
        g[2].x=g[0].x; g[2].y=g[0].y+2;  
        g[3].x=g[0].x; g[3].y=g[0].y-1;   
        set_cen(g[0]); set_type(6); break;  
            }  
    //山  
    case 7: {  
        g[0].x=x/2; g[0].y=y-2;  
        g[1].x=g[0].x; g[1].y=g[0].y+1;  
        g[2].x=g[0].x-1; g[2].y=g[0].y;  
        g[3].x=g[0].x+1; g[3].y=g[0].y;   
        set_cen(g[0]); set_type(7); break;  
            }  
    default: ;  
    }  
    def_block(g[0], g[1], g[2], g[3]);  
}  

class Table
{
public:
    Table()
    {
        height = 20;
        width = 10; 
        count = 0;
        init_table();
    }

    Table(int x, int y);
    int set_block(Block bl);
    void clr_block(Block bl);
    int clr_line(int y);
    int get_h();
    int get_w();
    int if_full(int y);
    int get_table(int x, int y);
    void paint();
    void move_line(int y);
    void set_count(int c);
    int get_count();

private:
    int table[TABLE_SIZE][TABLE_SIZE];
    int height, width;
    int count;

    void init_table();
};

void Table::init_table()
{
    int i , j;

    for ( i = 0; i < width; i++ )
        for ( j = 0; j < height; j++ )
            table[i][j] = 0;
}

Table::Table(int x, int y)
{
    height = y;
    width = x;
    count = 0;
    init_table();
}

int Table::set_block(Block bl)
{
    int x, y;
    int i;
    for ( i = 0; i <= 3; i++ )
    {
        x = bl.g[i].x;
        y = bl.g[i].y;
        if ( table[x][y] != 0 || x >= width || x < 0 || y >= height || y < 0 )
            return 0;
    }
    for ( i = 0; i <= 3; i++ )
    {
        x = bl.g[i].x;
        y = bl.g[i].y;
        table[x][y] = 1;
    }

    return 1;
}

void Table::clr_block(Block bl)
{
    int x, y;
    for ( int i = 0; i <= 3; i++ )
    {
        x = bl.g[i].x;
        y = bl.g[i].y;
        table[x][y] = 0;
    }
}

int Table::clr_line(int y)
{
    if ( y < 0 || y >= height )
        return 0;
    for ( int i = 0; i < width; i++ )
        table[i][y] = 0;
    return 1;
}

int Table::get_h()
{
    return height;
}

int Table::get_w()
{
    return width;
}

int Table::if_full(int y)
{
    int i;
    for ( i = 0; i < width; i++ )
        if ( table[i][y] == 0 )
            return 0;
    return 1;
}

int Table::get_table(int x, int y)
{
    return table[x][y];
}

void Table::paint()
{
    int i, j;

    for ( i = 0; i < width + 2; i++ )
        std::cout << "-" << std::flush;
    std::cout << "\n" << std::flush;
    for ( i = height - 1; i >= 0; i-- )
    {
        std::cout << "|" << std::flush;
        for ( j = 0; j < width; j++ )
        {
            if ( table[j][i] == 0 )
                std::cout << " " << std::flush;
            else
                std::cout << "#" << std::flush;
        }
        if ( i == 10 )
            std::cout << "|     得分:" << get_count() << std::endl;
        else if ( i == 7 )
            std::cout << "|     Press 'q' to quit!" << std::endl;
        else
            std::cout << "|" << std::endl;
    }
    for ( i = 0; i < width + 2; i++ )
        std::cout << "-" << std::flush;
    std::cout << "\n" << std::flush;
}

void Table::move_line(int y)
{
    int i, j;

    for ( i = y; i < height - 1; i++ )
        for ( j = 0; j < width; j++ )
            table[j][i] = table[j][i+1];
}

void Table::set_count(int c)
{
    count += c;
}

int Table::get_count()
{
    return count;
}

class Mythread
{
public:
    void init();
    static void *getkey(void *arg);
    static void *paint_loop(void *arg);
};

void Mythread::init()
{
    pthread_t ntid, ntid2;
    int err, err2;
    err = pthread_create(&ntid, NULL, getkey, NULL);
    err2 = pthread_create(&ntid2, NULL, paint_loop, NULL);
    if ( err != 0 || err2 != 0 )
    {
        std::cout << "can't create thread" << std::endl;
        exit(0);
    }
}

unsigned char flag = 1, buf[2];
Table tab(15, 20);
Block bl;

void* Mythread::paint_loop(void *arg)
{
    while ( 1 )
    {
        system("clear");
        tab.paint();
        usleep(50000);
    }
}

void* Mythread::getkey(void *arg)
{
    struct termios saveterm, nt;
    fd_set rfds, rs;
    struct timeval tv;
    int i = 0, q, r, fd = 0;
    tcgetattr(fd, &saveterm);
    nt = saveterm;

    nt.c_lflag &= ~ECHO;
    nt.c_lflag &= ~ISIG;
    nt.c_lflag &= ~ICANON;

    tcsetattr(fd, TCSANOW, &nt);

    FD_ZERO(&rs);
    FD_SET(fd, &rs);
    tv.tv_sec = 0;
    tv.tv_usec = 0;

    while ( 1 )
    {
        read(0, buf, 1);
        r = select(fd + 1, &rfds, NULL, NULL, &tv);
        if ( r < 0 )
            write(1, "select() error\n", 16);
        rfds = rs;
        if ( flag == 2 || buf[0] == 113 )
        {
            tcsetattr(0, TCSANOW, &saveterm);
            exit(0);
        }
        if ( buf[0] <= 68 && buf[0] >= 65 )
            flag = 0;
        if ( flag == 0 )
        {
            if ( buf[0] == 65 )
            {
                if ( bl.get_type() == 5 )
                    continue;
                tab.clr_block(bl);
                bl.rotate();
                if ( !tab.set_block(bl) )
                {
                    bl.back();
                    continue;
                    tab.set_block(bl);
                }
            }

            if ( buf[0] == 66 )
            {
                tab.clr_block(bl);
                bl.move(bl.DOWN);
                if ( !tab.set_block(bl) )
                {
                    bl.move(bl.UP);
                    tab.set_block(bl);
                }
            }

            if ( buf[0] == 68 )
            {
                tab.clr_block(bl);
                bl.move(bl.LEFT);
                if ( !tab.set_block(bl) )
                {
                    bl.move(bl.RIGHT);
                    tab.set_block(bl);
                }
            }

            if ( buf[0] == 67 )
            {
                tab.clr_block(bl);
                bl.move(bl.RIGHT);
                if ( !tab.set_block(bl) )
                {
                    bl.move(bl.LEFT);
                    tab.set_block(bl);
                }
            }
            flag = 1;
        }
    }
    tcsetattr(0, TCSANOW, &saveterm);
}



int main()
{
    Mythread thread;
    thread.init();
    int dir, i, c;

    while ( true )
    {
        srand(time(0));
        bl.creat_block(tab.get_w(), tab.get_h());

        if ( !tab.set_block(bl) )
        {
            system("clear");
            std::cout << "Game Over!" << std::endl;
            flag = 2;
            std::cout << "Press any key to continue!" << std::endl;
            while ( 1 );
        }

        while ( true )
        {
            usleep(500000);
            tab.clr_block(bl);
            bl.move(bl.DOWN);
            if ( !tab.set_block(bl) )
            {
                bl.move(bl.UP);
                tab.set_block(bl);
                break;
            }
        }

        for ( i = 0; i < tab.get_h(); i++ )
            if ( tab.if_full(i) )
            {
                tab.clr_line(i);
                tab.move_line(i);
                i--;
                tab.set_count(100);
            }
    }
    return 0;
}
