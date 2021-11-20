#! /bin/bash
#
cp toeplitz_cholesky.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include toeplitz_cholesky.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toeplitz_cholesky.o ~/libcpp/toeplitz_cholesky.o
#
echo "Normal end of execution."
