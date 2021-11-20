#! /bin/bash
#
cp ihs.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include ihs.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ihs.o ~/libcpp/ihs.o
#
echo "Normal end of execution."
