#!/bin/bash
RED_COLOR='\E[1;31m'
GREEN_COLOR='\E[1;32m'
YELLOW_COLOR='\E[1;33m'
BLUE_COLOR='\E[1;34m'
RES='\E[0m'
read -p "Please input the fruit name you like: " ans
case "$ans" in
    apple|APPLE)
        echo -e "the fruit name you like is ${RED_COLOR}"$ans."${RES}"
        ;;
    banana|BANANA)
        echo -e "the fruit name you like is ${YELLOW_COLOR}"$ans."${RES}"
        ;;
    pear|PEAR)
        echo -e "the fruit name you like is ${GREEN_COLOR}"$ans."${RES}"
        ;;
    *)
        echo -e "here is not the fruit name you like--${BLUE_COLOR}"$ans."${RES}"
        exit
        ;;
esac
