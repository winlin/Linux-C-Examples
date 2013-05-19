#! /bin/bash
if(($#!=2))
then 
    echo $0  Name Score
    exit
fi
if(($2<0||$2>100))
then 
    echo Score Invaild
    exit
fi
if(($2>=90))
then 
    echo Congratulation!
elif(($2>=60))
then 
    echo Lucky Boy.
elif(($2<60))
then 
    echo Badly.
fi
