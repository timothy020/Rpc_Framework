#!/bin/bash
# 该命令之后，当出现命令行返回值为非0的情况时，脚本直接退出，后续命令不再执行。
set -e

rm `pwd`/build/* -rf 
cd `pwd`/build &&
    cmake ..   &&
    make

cd ../
cp -r `pwd`/src/include `pwd`/lib