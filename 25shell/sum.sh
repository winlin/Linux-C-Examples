#!/bin/bash
#shell脚本里面的函数要想在上一层shell中可用，必须要使用source shellname.sh / . shellname.sh
#让它在上层shell中生效
#一个函数的返回值仅占1B的大小，超过255就会从0开始
#我们可以使用一个全局的变量来保存结果，比如$REPLY
#函数里面定义的变量也是本地全局变量，不同函数中同名变量会出错
#如果定义一个变量只许在函数内部使用要使用 local定义
sum()
{
    for data in $*
    do
	((REPLY+=data))
	: echo $s     #命令前使用 冒号+空格 表示不执行该语句
    done
}
