#! /bin/bash
#
cp blas1_s.hpp $HOME/include
#
g++ -c -Wall -I $HOME/include blas1_s.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blas1_s.o ~/libcpp/blas1_s.o
#
echo "Normal end of execution."
