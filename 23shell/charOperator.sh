#!/bin/bash
#说明字符运算符号的使用
str="hello shell programming"
echo ${str:5}
echo ${str:5:5}
arr=(hello shell programming)
echo ${arr[*]##p*}
echo ${str%%pro*}
