#!/usr/bin/csh

for(( id=20000;id<30000;++id ))
do
    kill -9 $id
    echo $id
done