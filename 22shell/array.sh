#!/bin/bash
#说明数组的使用
arr[1]=20;
arr[2]=30;
echo ${arr[*]}
echo $arr[*]

declare -a arr2
arr2[1]=20;
arr2[2]=20;
echo ${arr2[*]}

arr3=(hello shell programming)
echo ${arr3[*]}

unset arr3
echo  ${arr3[*]}

echo please input number
read -a arr4
echo ${arr4[0]}
echo ${arr4[*]}

22dayshell$ sh array.sh 
20 30
[*]
20 20
hello shell programming

please input number
1 2 3 4 54 
1
1 2 3 4 54
22dayshell$ 
