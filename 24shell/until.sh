#!/bin/bash
until [ -f file ]
do
    sleep 1
done
echo file已经存在