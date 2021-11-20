#! /bin/bash
#
cp blas2_d.hpp $HOME/include
#
g++ -c -Wall -I$HOME/include blas2_d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blas2_d.o ~/libcpp/blas2_d.o
#
echo "Normal end of execution."
