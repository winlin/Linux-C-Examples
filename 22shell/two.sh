#!/bin/bash
#说明引用的使用
myvar=2334
echo  ${myvar}
echo   "${myvar}"
echo   '${myvar}'
echo   "${myvar}'${myvar}'"
echo   '${myvar}"${myvar}"'
echo   "$*"

2334
2334
${myvar}
2334'2334'
${myvar}"${myvar}"
