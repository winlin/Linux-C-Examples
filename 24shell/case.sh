#!/bin/bash
echo 1---红烧肉
echo 2---水煮鱼
echo 3---老厨白菜
echo 4---担担面
read -p 请选择： var
case $var in
    *1*)
	echo HongShaoRou
	echo 23.45;;
    2*)
	echo ShuiZhuYu
	echo 34.3;;
    *3)
	echo LaoChuBaiCai
	echo 6.00;;
    4)
	echo DanDanMian
	echo 5.00;;
    *)
	echo Welcome !;;
esac

