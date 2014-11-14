#!/bin/sh -e
# while true
# do
#     uptime > while.log
#     sleep 2
# done
i=10
while ((i>0))
do
    echo $i
    ((i--))
done
