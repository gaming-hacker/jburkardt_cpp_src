#! /bin/bash
#
cp ubvec.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include ubvec.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ubvec.o ~/libcpp/ubvec.o
#
echo "Normal end of execution."
