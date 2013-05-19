#!/bin/bash
func()
{
    a=123
    local b=4567
}
a=5
func
echo a=$a
echo b=$b     #在函数外部不可使用