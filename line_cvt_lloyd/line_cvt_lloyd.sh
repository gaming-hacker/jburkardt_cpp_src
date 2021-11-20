#! /bin/bash
#
cp line_cvt_lloyd.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include line_cvt_lloyd.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv line_cvt_lloyd.o ~/libcpp/line_cvt_lloyd.o
#
echo "Normal end of execution."
