#!/bin/bash
#说明运算符号的使用
arr=(1 2 3 4)
echo ${arr[*]}
a=hello
echo ${#a}
echo ${#arr}
echo ${#arr[*]}
echo ${a:-shell}
echo ${b:-${a}}

echo ${b:-不存在}
b=存在
echo ${b:-不存在}
echo ${b:=不存在}
echo ${c:=c不存在}
echo ${c:=c还是不存在}

#$(())算术运算
s1=$((1+3+4))
echo $s1
v=20
echo $((v>10))
echo $((v++))
echo $v
echo $((v**2))
let d=v**2
echo $d
let "t2=((t1=9,15/3))" #t2=5 t1=9
echo $t2 $t1

#进制
let t3=023
let t4=0xff

let t5=2#10101
echo $t3 $t4 $t5
echo $((t6=023,16/4))

#比较运算
#注意[ ]之间的空格
[ "3" -ne "4" ]
[[ "3" -gt "4" ]]

