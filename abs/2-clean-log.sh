#!/bin/bash

LOG_DIR=/var/log
ROOT_UID=0  # $UID=0的时候，用户才具有根用户的权限
LINES=50    # 默认保存的行数
E_XCD=66    # 不能修改目录
E_NOTROOT=67    # 非根用户将以error退出

# 需要用root用户来运行
if [ "$UID" -ne "$ROOT_UID" ]
then
    echo "Must be root to run this script."
    exit $E_NOTROOT
fi

# 测试是否有命令行参数（非空）
if [ -n "$1" ]
then 
    lines=$1
else
    lines=$LINES    # 默认，如果不在命令行中执行
fi

#
# 更好的方法来检测命令行参数
#
# E_WRONGARGS=65    # 非数值参数
# 
# case "$!" in
# ""    ) lines=50;;
# *[!0-9]*) echo "Usage:`basename $0` file-to-cleanup"; exit $E_WRONGARGS;;
# *     ) lines=$1;;
# esac
# 

cd $LOG_DIR

# 在处理log file之前，再确认一遍当前目录是否正确
if [ `pwd` != "$LOG_DIR" ]  #不在/var/log中
then
    echo "Can't change to $LOG_DIR."
    exit $E_XCD
fi  

# 更有效率的做法
# cd /var/log || {
#    echo "cannot change to necessary directory." >& 2
#    exit $E_XCD;
# }

# 比cat /dev/null > messages 更安全的方法
tail -$lines messages > mesg.temp   # 保存log file 消息的最后部分
mv mesg.temp messages               # 变为新的log目录

cat /dev/null > wtmp    # ':>wtmp' 和 '>wtmp'具有相同的作用
echo "logs cleaned up."

exit 0  # 返回0表示成功
