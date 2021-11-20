#! /bin/bash
#
g++ -c -Wall -I/$HOME/include table_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ table_io_test.o /$HOME/libcpp/table_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm table_io_test.o
#
mv a.out table_io_test
./table_io_test > table_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm table_io_test
#
echo "Normal end of execution."
