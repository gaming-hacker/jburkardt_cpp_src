#! /bin/bash
#
g++ -c -Wall -I/$HOME/include pgmb_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pgmb_io_test.o /$HOME/libcpp/pgmb_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pgmb_io_test.o
#
mv a.out pgmb_io_test
./pgmb_io_test > pgmb_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pgmb_io_test
#
echo "Normal end of execution."
