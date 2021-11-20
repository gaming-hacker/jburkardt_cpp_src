#! /bin/bash
#
cp truncated_normal.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include truncated_normal.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv truncated_normal.o ~/libcpp/truncated_normal.o
#
echo "Normal end of execution."
