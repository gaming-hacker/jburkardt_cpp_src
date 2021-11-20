#! /bin/bash
#
cp blas2_s.hpp $HOME/include
#
g++ -c -Wall -I$HOME/include blas2_s.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blas2_s.o ~/libcpp/blas2_s.o
#
echo "Normal end of execution."
