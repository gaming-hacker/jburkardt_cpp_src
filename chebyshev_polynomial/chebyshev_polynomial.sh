#! /bin/bash
#
cp chebyshev_polynomial.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include chebyshev_polynomial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv chebyshev_polynomial.o ~/libcpp/chebyshev_polynomial.o
#
echo "Normal end of execution."
