#! /bin/bash
#
cp blas3_d.hpp /$HOME/include
#
g++ -c -Wall -I$HOME/include blas3_d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blas3_d.o ~/libcpp/blas3_d.o
#
echo "Normal end of execution."
