#! /bin/bash
#
cp subset_sum_serial.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include subset_sum_serial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv subset_sum_serial.o ~/libcpp/subset_sum_serial.o
#
echo "Normal end of execution."
