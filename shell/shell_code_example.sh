#!/bin/bash
function filetype()
{
    #判断文件类型，如果是链接文件，则将其移动到/etc目录下
    local FILENAME=
    echo "Input file name: "
    read FILENAME
    if [ -L $FILENAME ]
    then
        mv $FILENAME /etc
    fi
}

function menu_if()
{
    echo "Please choose: (1-3, or ctrl-c)"
    echo "1 vi"
    echo "2 X-window"
    echo "3 print-file"
    echo "ctrl-c quit"
    read xyz
    if [ $xyz = 1 ]
    then 
        vim
        exit 1
    elif [ $xyz = 2 ]
    then 
        startx
        exit 1
    elif [ $xyz = 3 ]
    then 
        echo "  //Please enter filename:"
        read filename
        lp $filename &
        exit 1
    else
        echo "-----------------------------"
        /bin/sh $0
    fi
}

function menu_while()
{
    local i=1
    while [ "$i" -eq 1 ]
    do
        RESPONSE=
        echo "-----------------------------------------------"
        echo "Please choose:"
        echo "input --start     -start program files"
        echo "input --stop      -kill myfiles"
        echo "input --status    -view status of myfiles process"
        echo "input --quit      -exit"
        echo "-----------------------------------------------"
        read RESPONSE
        case $RESPONSE in
            start)  ./$0 ;;
            stop)   killall $0 ;;
            status) ps aux|grep $0 ;;
            quit)   i=0 
                    echo "Quit, thanks" ;;
        esac
    done
}

menu_while
