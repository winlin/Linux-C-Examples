#!/bin/bash
#需要ctrl+d来结束输入数据
echo 
sum=0
while read -p 请输入要计算的整数: data
do 
    if ! expr 1 + $data >& /dev/null
    then 
	echo "您输入的不是整数，请重新输入"
	continue
    fi
    if [ $data -eq 0 ]            #if (($data==0))
    then break;
    fi
    sum=$[ sum+data ]
done
echo $sum