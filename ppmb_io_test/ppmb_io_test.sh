#! /bin/bash
#
g++ -c -Wall -I/$HOME/include ppmb_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ ppmb_io_test.o /$HOME/libcpp/ppmb_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ppmb_io_test.o
#
mv a.out ppmb_io_test
./ppmb_io_test > ppmb_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ppmb_io_test
#
echo "Normal end of execution."
