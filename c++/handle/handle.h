#ifndef HANDLE_H
#define HANDLE_H

class Handle
{
    struct Cheshire;    //class declaration only
    Cheshire* smile;
public:
    void initialize();
    void cleanup();
    int read();
    void change(int);
};

#endif
