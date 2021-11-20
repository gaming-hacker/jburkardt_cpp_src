#! /bin/bash
#
cp hankel_cholesky.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include hankel_cholesky.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hankel_cholesky.o ~/libcpp/hankel_cholesky.o
#
echo "Normal end of execution."
