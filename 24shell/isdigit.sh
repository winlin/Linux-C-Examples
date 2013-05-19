#!/bin/bash
#判断是否为数字
while true
do
    read -p 请输入 input
    num=`expr "$input" : '[0-9]*'`
    if((num==${#input}))
    then
	echo INT
    else
	echo NOT INT
    fi
done