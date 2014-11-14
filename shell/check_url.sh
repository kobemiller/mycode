#!/bin/sh -e
#比较专业的生产检查url地址的脚本（shell数组方法）
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
            action "${url_list[$i]}:    success" /bin/true
        else
            action "${url_list[$i]}:    failure" /bin/false
        fi
    done
}
check_url
