#! /bin/bash
#
cp matrix_exponential.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include matrix_exponential.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv matrix_exponential.o ~/libcpp/matrix_exponential.o
#
echo "Normal end of execution."
