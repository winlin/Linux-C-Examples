#!/bin/bash
result=0
fact()
{
    if(($# !=1 ));then return 0;fi
    if(($1==1||$1==0))
    then result=1
    else
	fact $[$1-1]
	result=$[$1*$result]
    fi
}
fact 9
echo $result

