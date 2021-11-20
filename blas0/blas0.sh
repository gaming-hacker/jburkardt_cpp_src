#! /bin/bash
#
cp blas0.hpp /$HOME/include
#
g++ -c -Wall blas0.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blas0.o ~/libcpp/blas0.o
#
echo "Normal end of execution."
