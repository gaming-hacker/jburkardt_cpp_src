#! /bin/bash
#
g++ -c -Wall -I/$HOME/include obj_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ obj_io_test.o /$HOME/libcpp/obj_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm obj_io_test.o
#
mv a.out obj_io_test
./obj_io_test > obj_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm obj_io_test
#
echo "Normal end of execution."
