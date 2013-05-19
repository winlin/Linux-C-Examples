#!/bin/bash
if(($#!=1))
then 
        echo $0 directory
        exit
fi
cntf=0
cntd=0
a[0]=目录
b[0]=文件
for file in $1/*
do
        if [ -d $file ]
        then
                cntd=$[cntd+1]
                a[$cntd]="$cntd:$file"
        else
                cntf=$[cntf+1]
                b[$cntf]="$cntf:$file"
        fi
done
i=-1
while (($i<$cntd))
do
        i=$[i+1]
        echo ${a[$i]}
done
i=-1
while (($i<$cntf))
do
        i=$[i+1]
        echo ${b[$i]}
done