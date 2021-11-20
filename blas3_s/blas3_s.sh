#! /bin/bash
#
cp blas3_s.hpp /$HOME/include
#
g++ -c -Wall -I$HOME/include blas3_s.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blas3_s.o ~/libcpp/blas3_s.o
#
echo "Normal end of execution."
