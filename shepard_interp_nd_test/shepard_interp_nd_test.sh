#! /bin/bash
#
g++ -c -Wall -I/$HOME/include shepard_interp_nd_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ shepard_interp_nd_test.o /$HOME/libcpp/shepard_interp_nd.o \
                            /$HOME/libcpp/test_interp_nd.o \
                            /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm shepard_interp_nd_test.o
#
mv a.out shepard_interp_nd_test
./shepard_interp_nd_test > shepard_interp_nd_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm shepard_interp_nd_test
#
echo "Normal end of execution."
