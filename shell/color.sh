#!/bin/bash
echo -e "\033[30m 黑色字 kobemiller \033[0m"
echo -e "\033[31m 红色字 kobemiller \033[0m"
echo -e "\033[32m 绿色字 kobemiller \033[0m"
echo -e "\033[33m 黄色字 kobemiller \033[0m"
echo -e "\033[34m 蓝色字 kobemiller \033[0m"
echo -e "\033[35m 紫色字 kobemiller \033[0m"
echo -e "\033[36m 天蓝字 kobemiller \033[0m"
echo -e "\033[37m 白色字 kobemiller \033[0m"
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
echo -e "\033[40;37m kobemiller\033[1m"
   echo -e "\033[41;37m kobemiller\033[4m"
      echo -e "\033[42;37m kobemiller\033[5m"
         echo -e "\033[43;37m kobemiller\033[7m"
            echo -e "\033[44;37m kobemiller\033[8m"
               echo -e "\033[45;37m kobemiller\033[2J"
                  echo -e "\033[46;37m kobemiller\033[0m"
                     echo -e "\033[47;37m kobemiller\033[0m"

