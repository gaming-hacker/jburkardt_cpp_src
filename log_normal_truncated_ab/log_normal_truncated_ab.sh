#! /bin/bash
#
cp log_normal_truncated_ab.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include log_normal_truncated_ab.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv log_normal_truncated_ab.o ~/libcpp/log_normal_truncated_ab.o
#
echo "Normal end of execution."
