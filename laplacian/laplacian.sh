#! /bin/bash
#
cp laplacian.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include laplacian.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv laplacian.o ~/libcpp/laplacian.o
#
echo "Normal end of execution."
