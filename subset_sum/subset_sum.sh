#! /bin/bash
#
cp subset_sum.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include subset_sum.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv subset_sum.o ~/libcpp/subset_sum.o
#
echo "Normal end of execution."
