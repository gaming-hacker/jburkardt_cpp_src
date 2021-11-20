#! /bin/bash
#
cp c4lib.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include c4lib.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv c4lib.o ~/libcpp/c4lib.o
#
echo "Normal end of execution."
