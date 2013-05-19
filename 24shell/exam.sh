#!/bin/bash
score=0
times=1
#MENU
echo   1---ADD
echo   2---SUB
echo   3---Multiplacation
echo   4---Division

while [ $times -le 5 ]
do
    echo Please input your choice:
    read choose
    a=$[RANDOM%100]
    b=$[RANDOM%100]
    case $choose in 
	1)
	    echo "$a+$b=?"
	    read result
	    if(($result ==`expr $a + $b`))
	    then 
		score=$[score+5]
	    fi;;
	2)
	    echo "$a-$b=?"
	    read result
	    if(($result ==`expr $a - $b`))
	    then
	    score=$[score+5]
	    fi;;
	3)
	    echo "$a*$b=?"
	    read result
	    if((result ==`expr $a \* $b` ))
	    then 
	    score=$[score+5]
	    fi;;
	4)
	    while (($b==0))
	    do
		b=$RANDOM%100
	    done
	    echo "$a/$b=?"
	    read result
	    if((result ==`expr $a / $b` ))
	    then
		score=$[score+5]
	    fi;;
	*)
	    echo ERROR:Your choice out of range;;
    esac
    times=$[times+1]
done
echo "Score is: $score"


	
	
	