#!/bin/bash
echo 开始发牌
n=52
ps=1
 echo "第$ps个人的牌:"
while (($n!=0))
 do 
   num=$[$RANDOM%13]
   flower=$[$RANDOM%4]
   
   if((a[$num$flower]==1))
   then
     continue
   else
     case "$flower" in
       0) echo -n " 红桃";;
       1) echo -n " 方片";;
       2) echo -n " 梅花";;
       3) echo -n " 黑桃";;
       *) 
     esac    
     case "$num" in
       0)   echo  A;;
       10)  echo  J;;
       11)  echo  Q;;
       12)  echo  K;;
       *)   echo $[num+1]
      esac    
     a[$num$flower]=1
   fi
   n=$[n-1]
   if((n%13==0&&n!=0))
   then
     ps=$[$ps+1]
     echo "第$ps个人的牌:"
   fi
 done 
