#! /bin/bash
#
cp chebyshev.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include chebyshev.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv chebyshev.o ~/libcpp/chebyshev.o
#
echo "Normal end of execution."
