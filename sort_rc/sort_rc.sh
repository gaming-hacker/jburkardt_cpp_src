#! /bin/bash
#
cp sort_rc.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include sort_rc.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sort_rc.o ~/libcpp/sort_rc.o
#
echo "Normal end of execution."
