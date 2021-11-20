#! /bin/bash
#
cp sobol.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include sobol.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sobol.o ~/libcpp/sobol.o
#
echo "Normal end of execution."
