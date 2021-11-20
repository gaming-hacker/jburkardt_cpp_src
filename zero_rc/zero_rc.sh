#! /bin/bash
#
cp zero_rc.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include zero_rc.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv zero_rc.o ~/libcpp/zero_rc.o
#
echo "Normal end of execution."
