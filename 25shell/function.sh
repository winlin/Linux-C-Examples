#!/bin/bash
#有返回值但是不会输出
len()
{
     return ${#1}
}

a=`len good`
echo $a
#a的值为空，因为`的作用是获取执行命令的输出(字符串)，因为return不是输出所以a空值

