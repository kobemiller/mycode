#!/bin/bash
read -p "please input a number:" ans
case "$ans" in
[1-9])
echo "the number you input is $ans"
;;
*)
echo "the number you input is not between 1-9"
exit
;;
esac
