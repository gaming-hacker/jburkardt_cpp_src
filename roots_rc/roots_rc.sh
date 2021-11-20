#! /bin/bash
#
cp roots_rc.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include roots_rc.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv roots_rc.o ~/libcpp/roots_rc.o
#
echo "Normal end of execution."
