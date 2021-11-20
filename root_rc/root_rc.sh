#! /bin/bash
#
cp root_rc.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include root_rc.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv root_rc.o ~/libcpp/root_rc.o
#
echo "Normal end of execution."
