#!/bin/sh -e
report_status()
{
    echo "os-release: `cat /etc/os-release |grep "PRETTY_NAME"|sed -n '1p'|gawk -F '"' '{ print $2 }'`"
    echo "kernel-release: `uname -a|awk '{print $1"  "$3}'`"
    echo "cpu info: `cat /proc/cpuinfo |grep "model name"|uniq|awk -F':' '{print $2}'`"
    echo "cpu空闲率: `vmstat |sed -n '3p'|awk '{print $(NF-1)}'`%"
    echo "cpu负载: ` uptime |awk -F': ' '{print $2}'`"
    echo "memory total: `free -h|grep Mem|awk -F" " '{print $2}'`"
    echo "memory used: `free -h|grep Mem|awk -F" " '{print $3}'`"
    echo "memory free: `free -h|grep Mem|awk -F" " '{print $4}'`"
}
report_status > hardware_info
