#!/bin/bash
#说明系统变量的使用
echo   $*
echo   $@
echo   $#
echo   $?
echo   $-
echo   $$
echo   $!
echo   $0
echo   $_


22dayshell$ sh one.sh as as dd
as as dd
as as dd
3
0
hB
13473

one.sh
one.sh
