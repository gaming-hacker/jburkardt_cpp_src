#! /bin/bash
#
cp wathen.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include wathen.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv wathen.o ~/libcpp/wathen.o
#
echo "Normal end of execution."
