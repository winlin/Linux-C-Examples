#!/bin/bash
#bake file
if cp $1 $2
then
    if cat /dev/null > $1
    then
	  exit 0
     else
	  exit 1
    fi
fi
   