#! /bin/bash
#
g++ -c -Wall -I$HOME/include file_name_sequence_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ file_name_sequence_test.o /$HOME/libcpp/file_name_sequence.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm file_name_sequence_test.o
#
mv a.out file_name_sequence_test
./file_name_sequence_test > file_name_sequence_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm file_name_sequence_test
#
echo "Normal end of execution."
