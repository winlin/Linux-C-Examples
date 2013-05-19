#! /bin/bash
#列出一个路径下的文件和目录
if(($# != 1))
then 
    echo $0 path
    exit
fi

fcnt=0;
dcnt=0;
for file in $1/*
do
    if [ -f $file ]
	then
	fcnt=$[fcnt+1]
	echo "$fcnt F: $file"
     fi
done

for direct in $1/* 
do
    if [ -d $direct ]
	then
	dcnt=$[dcnt+1]
	echo "$dcnt D: $direct"
     fi
done

 