#! /bin/bash
#
g++ -c -Wall -I/$HOME/include ccs_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ ccs_io_test.o /$HOME/libcpp/ccs_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ccs_io_test.o
#
mv a.out ccs_io_test
./ccs_io_test > ccs_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ccs_io_test
#
echo "Normal end of execution."
