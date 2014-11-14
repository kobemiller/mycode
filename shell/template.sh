#!/bin/bash
#judge num
[ -n "`echo $1|sed 's/[0-9]//g'`" -a -n "`echo $2|sed 's/[0-9]//g'`" ] && echo "两个参数都必须是数字"
#思路：如果参数内容长度不为0，把参数内容中的非数字部分删除，然后看结果是不是空$#，来判断是不是数字
[ -n "`echo $1|sed 's/[0-9]//g'`" ] && echo "第一个参数必须是数字" && exit 1
[ -n "`echo $2|sed 's/[0-9]//g'`" ] && echo "第二个参数必须是数字" && exit 1
#(特殊思路)如果num长度不为0，并且把num中的非数字部分删除，然后看结果是不是等于num本身，如果两者都成立就是数字
[ -n "$num" -a "$num"="${num//[^0-9]/}" ] && echo "it's a number"

#判断参数个数
if [ $# -ne 2 ]
then
    echo "Usage: $0 num1 num2"
    exit 1
fi
[ -n "`echo $1|sed 's/[0-9]//g'`" -a -n "`echo $2|sed 's/[0-9]//g'`" ] && echo "第一个参数必须是数字" && exit 1

#生产环境监控MYSQL服务的实战例子
#监控MYSQL的服务是否正常启动，如果未正常启动，就启动MYSQL服务。
#!/bin/bash
port=`netstat -lnt|grep 3306|awk -F ' [: ]+ ' '{print $5}'`  #这不是最佳思路
if [ "$port" != "3306" ]
then
    /data/3306/mysql start
fi
#通过端口判断实现更简易脚本
portNum=`netstat -lnt|grep 3306|wc -l`
if [ $portNum -eq 1 ]
then
    echo "db is running"
else
    /data/3306/mysql restart
fi

#本方法的实现思路是如果MYSQL端口和进程同时存在，即认为MYSQL服务正常
#首先写脚本前人工检查MYSQL服务是否OK
portNum=`netstat -lnt|grep 3306|wc -l`
if [ $portNum -eq 1 -a $mysqlPrcessNum -eq = 2 ]
then
    echo "db is running"
else
    /data/3306/mysql start
fi
#特别强调：如果过滤MYSQL进程数，不要让脚本名中带MYSQL（过滤是用kill命令，脚本名带MYSQL的话，脚本的执行也会中断）
#实际脚本的写法
MySQLSTARTUP="/data/3303/mysql"
DbProcessCount=`ps -ef|grep mysql|grep -v grep|wc -l`
DbPortCount=`netstat -lnt|grep 3306|wc -l`
if [ $DbProcessCount -eq 2 ] && [ $DbPortCount -eq 1 ]
then
    echo "mysql is running"
else
    $MySQLSTARTUP start >/tmp/mysql.log
    sleep 10
    DbProcessCount=`ps -ef|grep mysql|grep -v grep|wc -l`
    DbPortCount=`netstat -lnt|grep 3306|wc -l`
    if [ $DbProcessCount -ne 2 ] || [ $DbPortCount -ne 1 ]
    then
        pkill mysqld >/dev/null 2>&1
        sleep 5
        pkill mysqld >/dev/null 2>&1
        sleep 5
        [ $DbPortCount -eq 0 ] && $MySQLSTARTUP start >>/tmp/mysql.log
        [ $? -eq 0 ] && echo "mysql is started"
    fi
    mail -s "mysql restarted" 731544404@qq.com < /tmp/mysql.log
fi

#更专业的写法
#!/bin/bash
MYUSER="root"
MYPASS="kobemiller"
MYSOCK="/data/3306/mysql.sock"
MySQL_STARTUP="/data/3306/mysql"
LOG_PATH=/tmp
LOG_FILE=${LOG_PATH}/mysqllogs_`date + %F`.log
MYSQL_PATH=/application/mysql/bin
MYSQL_CMD="$MYSQL_PATH/mysql -u$MYUSER -p$MYPASS -S $MYSOCK"

$MYSQL_CMD -e "select version();" >/dev/null 2>&1
if [ $? -eq 0 ]
then
    echo "MySQL is running"
    exit 0
else
    $MySQL_STARTUP start >$LOG_FILE
    sleep 5
    $MYSQL_CMD -e "select version();" >/dev/null 2>&1
    if [ $? -ne 0 ]
    then
        for ((i=1; i<1001;i++))
        do
            killall -9 mysqld >/dev/null 2>&1
            [ $? -ne 0 ] && break
            sleep 1
        done
        [ -x $MySQL_STARTUP ] && $MySQL_STARTUP start >>$LOG_FILE
    fi
    $MYSQL_CMD -e "select version();" >/dev/null 2>&1 && Status="restarted" || Status="unknown"
    echo "MySQL status is $Status" >>$LOG_FILE
    mail -s "MySQL status is $Status" 731544404@qq.com < $LOG_FILE
fi
exit
#通过php/java程序url方式监控MySQL,最接近用户访问，效果最好。报警的最佳方式不是服务是否开启了，而是网站的用户是否还访问正常

#监控apache&&nginx
#远程端口监控：监控机和web不在一个服务器上
#！/bin/bash
HttpPortNum=`nmap 10.0.0.7 -p 80|grep open|wc -l`
if [ $HttpPortNum -eq 1 ]
then
    echo "httpd is running"
else
    echo "httpd is not running"
    /application/apache/bin/apachectl start
fi
#通过进程数监控
#!/bin/bash
HttpProcessNum=`ps -ef|grep httpd|grep -v grep|wc -l`
if [ $HttpProcessNum -gt 4 ]
then
    echo "httpd is running"
else
    echo "httpd is not running"
    /application/apache/bin/apachectl start
fi
#通过url地址远程监控
#!/bin/bash
wget -T 10 -q --spider http://10.0.0.7 >/dev/null
#curl -s http://10.0.0.7 >/dev/null
if [ $? -eq 0 ]
then
    echo "httpd is running"
else
    echo "httpd is not running"
    /application/apache/bin/apachectl start
fi
#通过获取http url的header code监控
#!/bin/bash
HttpHeader=`curl -I -s www.baidu.com|head -1|cut -d " " -f2`
if [ "$HttpHeader" == "200" ]
then
    echo "httpd is running"
else
    echo "httpd is not running"
    /application/apache/bin/apachect1 start
fi

#生产环境常见的http状态码列表
    200K---ok，服务器成功返回网页
    301----Moved Permanently(永久跳转)，请求的网页已永久跳转到新的位置
    403----Forbidden(禁止访问)，服务器拒绝请求
    404----Not Found,服务器找不到请求的网页
    500----Internal Server error(内部服务器错误)
    502----Bad Gateway(坏的网关)，一般是网关服务器请求后端服务时，后端服务没有按照http协议正确返回结果
    503----Service Unavailable(服务当前不可用)，可能因为超载或停机维护
    504----Gateway Timeout(网关超时)。一般是网关服务器请求后端服务时，后端服务没有在特定的时间内完成服务
#根据rul地址加系统函数实现监控（生产常用）
#!/bin/bash
LOG_FILE=/tmp/httpd.log
apachectl="/application/apache/bin/apachect1"
wget --quiet ==spider http://10.0.0.179:8000 && RETVAL=$?
[ ! -f $LOG_FILE ] && touch $LOG_FILE
if [ "$RETVAL" != "0" ]
then
    echo -e "httpd is not running\n" >$LOG_FILE
    while true
    do
        killall httpd >/dev/null 2>&1
        [ $? -ne 0 ] && {
        echo "httpd is killed" >>$LOG_FILE
        break
        }
        sleep 2
    done
    $apachect1 restart >/dev/null 2>&1 && Status="rstarted" || Status="unknown"
    [ "$Status" = "restarted" ] && action "httpd is restarted" /bin/true||\
        action "httpd is restarted" /bin/false
    mail -s "`uname -n`'s httpd status is $Status" 731544404@qq.com <$LOG_FILE
    exit
else
    action "httpd is running" /bin/true
    exit 0
fi

#如何查看远端web服务是否开通tcp80端口
#方法1：此法常用来检测远端端口是否通畅
echo -e "\n"|telnet www.baidu.com 80|grep Connected
#用nc命令
nc -w 10 www.baidu.com 80 && echo "ok" || echo "no"
#通过nc检查端口并监控memcache服务
export kmTimestampMemcachedIo=$1
export kmTimestampMemcachedPort=$2
export kmTitle=NAGIOS
export kmTimestampMD5=4ED06F8D41B92640KM30BE5212BB7E34
export wwwServerIp=$3
export wwwServerPort=$4

printf "delete $kmTimestampMD5\r\n"|nc $kmTimestampMemcachedIp
$kmTimestampMemcachedPort >/dev/null 2>&1
sleep 1
judge=($(printf "HEAD /km/$kmTitle HTTP/1.1\r/nHost:$5\r\n\r\n"|nc $wwwServerPort|head -nl|tr "\r" "\n"))

#通过定义变量的方式给字体加颜色
#!/bin/bash
RED_COLOR='\E[1;31m'
GREEN_COLOR='\E[1;32m'
YELLOW_COLOR='\E[1;33m'
BLUE_COLOR='\E[1;34m'
PINK='\E[1;35m'
RES='\E[0m'
echo -e "${RED_COLOR}=====red color=====${RES}"
echo -e "${YELLOW_COLOR}=====yellow color=====${RES}"
echo -e "${GREEN_COLOR}=====green color=====${RES}"
echo -e "${BLUE_COLOR}=====blue color=====${RES}"
echo -e "${PINK_COLOR}=====pink color=====${RES}"
#系统用的
SETCOLOR_SUCCESS="echo -en \\033[1;32m"
SETCOLOR_FAILURE="echo -en \\033[1;31m"
SETCOLOR_WARNING="echo -en \\033[1;33m"
SETCOLOR_NORMAL="echo -en \\033[1;39m"
echo ----kobemiller---- && $SETCOLOR_SUCCESS
echo ----kobemiller---- && $SETCOLOR_FAILURE
echo ----kobemiller---- && $SETCOLOR_NORMAL
echo ----kobemiller---- && $SETCOLOR_WARNING
#背景色
echo -e "\033[40;37m kobemiller\033[0m"
echo -e "\033[41;37m kobemiller\033[0m"
echo -e "\033[42;37m kobemiller\033[0m"
echo -e "\033[43;37m kobemiller\033[0m"
echo -e "\033[44;37m kobemiller\033[0m"
echo -e "\033[45;37m kobemiller\033[0m"
echo -e "\033[46;37m kobemiller\033[0m"
echo -e "\033[47;37m kobemiller\033[0m"
#控制选项说明
\033[0m             #关闭所有属性
\033[1m             #设置高亮度
\033[4m             #下划线
\033[5m             #闪烁
\033[7m             #反显
\033[8m             #消隐
\033[30m - \033[37m #设置前景色
\033[40m - \033[47m #设置背景色
\033[nA             #光标上移n行
\033[nB             #光标下移n行
\033[nC             #光标右移n行
\033[nD             #光标左移n行
\033[y,xH           #设置光标位置
\033[2J             #清屏
\033[K              #清除从光标到行尾的内容
\033[s              #保存光标位置
\033[u              #恢复光标位置
\033[?25l           #隐藏光标
\033[?25h           #显示光标

#9*9乘法表
#!/bin/sh -e
 for a in `seq 1 9`
 do
    for b in `seq 1 9`
    do
        if [ $a -ge $b ]
        then
            echo -en "$a * $b = $(expr $a \* $b) "
        fi
    done
    echo " "
 done

#批量添加用户并设置密码
#!/bin/sh -e
for n in $(seq -w 10)
do
    useradd kobemiller-$n
    #userdel -r kobemiller-$n
    echo "$n"|passwd --stdin kobemiller-$n
done
#密码为8位随机数
#!/bin/sh -e
for n in $(seq -w 10)
do
    passwd=`echo $(date +%t%N)$RANDOM|md5sum|cut -c 2-9`
    useradd kobemiller-$n
    echo "$passwd"|passwd --stdin kobemiller-$n
    echo -e "user:\tkobemiller-$n pass:$passwd" >>./user.log
done
#更牛逼的版本
#!/bin/sh -e
. /etc/init.d/functions

for n in $(seq -w 10)
do
    passwd=`echo $(date +%t%N)$RANDOM|md5sum|cut -c 2-9`
    useradd kobemiller-$n >&/dev/null && user_status=$?
    echo "$passwd"|passwd --stdin kobemiller-$n >&/dev/null && pass_status=$?

    if [ $user_status -eq 0 -a $pass_status -eq 0 ]
    then
        action "adduser kobemiller-$n" /bin/true
        echo -e "user:\tkobemiller-$n pass:\t$passwd" >>./user.log
    else
        action "adduser kobemiller-$n" /bin/false
        echo -e "user:\tkobemiller-$n pass:\t$passwd" >>./fail_user.log
    fi
done
#
#!/bin/sh -e
RE=0
case "$1" in
    up)
        for ((i=0; i<=16; i++))
        do
            if [ $i -eq 10 ]
            then
                continue;
            fi
            ifconfig eth0:$i 10.0.2.$i netmask 255.255.240.0 $1
        done
        ;;
    down)
        for ((i=0; i<=16; i++))
        do
            if [ $i -eq 10 ]
            then
                continue;
            fi
            ifconfig eth0:$i 10.0.0.$i netmask 255.255.240.0 $1
        done
        ;;
    *)
        echo "Usage: $0 {up|down}"
        exit
esac
exit RE
[km@localhost shell]$ cat km_functions
#!/bin/sh -e
function km()
{
        echo "I'm kobemiller"
}

[km@localhost shell]$ cat func_exe.sh
#!/bin/sh -e
[ -x ./km_functions ] && . ./km_functions||exit
km
[km@localhost shell]$ bash func_exe.sh
I'm kobemiller
#数组的使用
#!/bin/sh -e
dir=($(ls))
for ((i=0; i<${#dir[@]}; i++))
do
        echo "dir[$i]:  ${dir[$i]}"
done
echo "the length of dir is: ${#dir[@]}"

 #比较专业的生产检查url地址的脚本（shell数组方法）
 #!/bin/sh -e
 . /etc/init.d/functions

 url_list=(
 http://www.baidu.com
 http://www.google.com.cn
 https://www.github.com/helight/openflow.git
 http://oldboy.blog.51cto.com
 )
 function wait()
 {
     echo -n '3秒后，执行该操作'
     for ((i=0; i<3; i++))
     do
         echo -n "."
         sleep 1
     done
     echo
 }
 function check_url()
 {
     wait
     echo 'check url...'
     for ((i=0; i<${#url_list[@]}; i++))
     do
         #HTTP/1.1 200 OK
         judge=($(curl -I -s ${url_list[$i]}|head -1))
         #judge=($(curl -o /dev/null -s -w "%{http_code}" "${url_list[$i]}"))
         if [ "${judge[1]}"=="200" -a "${judge[2]}"=="OK" ]
         then
             action "${url_list[$i]}" /bin/true
         else
             action "${url_list[$i]}" /bin/false
         fi
     done
 }
 check_url
 echo "`cat /etc/os-release |grep "PRETTY_NAME"|sed -n '1p'|gawk -F '"' '{ print [ }'`"
 ]
