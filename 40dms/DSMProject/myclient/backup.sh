#!/bin/bash
#日志备份脚本，参数两个:原文件名，备份文件名
#判定参数是否传递充分
if (( $# < 2 ))
then
	exit 1
fi

#判定拷贝正确与否
if cp $1 $2 >&/dev/null 
then
#判定清空是否正确
#	if cat /dev/null >$1
#	then
		exit 0
#	else
#		exit 3	
#	fi
else
	exit 2	
fi

