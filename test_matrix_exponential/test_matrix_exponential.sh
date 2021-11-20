#! /bin/bash
#
cp test_matrix_exponential.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_matrix_exponential.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv test_matrix_exponential.o ~/libcpp/test_matrix_exponential.o
#
echo "Normal end of execution."
