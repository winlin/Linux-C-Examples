#!/bin/bash
# $REPLY 代表用户输入的值
menu=(红烧肉 水煮鱼 过桥米线 疙瘩汤)
select  var in ${menu[*]} 
do
   [ -n "$var" ]&&break                        #输入为空/字符串时一直执行
done
echo Your choice $REPLY \: $var