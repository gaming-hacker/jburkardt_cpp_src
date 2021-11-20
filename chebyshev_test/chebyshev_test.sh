#! /bin/bash
#
g++ -c -Wall -I/$HOME/include chebyshev_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ chebyshev_test.o /$HOME/libcpp/chebyshev.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm chebyshev_test.o
#
mv a.out chebyshev_test
./chebyshev_test > chebyshev_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm chebyshev_test
#
echo "Normal end of execution."
