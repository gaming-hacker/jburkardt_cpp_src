#! /bin/bash
#
g++ -c -Wall tensor_example1.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ tensor_example1.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm tensor_example1.o
#
mv a.out tensor_example1
./tensor_example1 > tensor_example1.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm tensor_example1
#
echo "Normal end of execution."
