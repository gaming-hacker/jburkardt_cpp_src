#! /bin/bash
#
cp lagrange_approx_1d.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include lagrange_approx_1d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv lagrange_approx_1d.o ~/libcpp/lagrange_approx_1d.o
#
echo "Normal end of execution."
