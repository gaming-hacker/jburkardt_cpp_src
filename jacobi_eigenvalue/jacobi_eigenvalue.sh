#! /bin/bash
#
cp jacobi_eigenvalue.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include jacobi_eigenvalue.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv jacobi_eigenvalue.o ~/libcpp/jacobi_eigenvalue.o
#
echo "Normal end of execution."
