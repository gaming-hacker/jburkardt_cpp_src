#! /bin/bash
#
cp log_normal.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include log_normal.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv log_normal.o ~/libcpp/log_normal.o
#
echo "Normal end of execution."
