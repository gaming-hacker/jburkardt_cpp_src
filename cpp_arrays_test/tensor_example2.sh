#! /bin/bash
#
g++ -c -Wall tensor_example2.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ tensor_example2.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm tensor_example2.o
#
mv a.out tensor_example2
./tensor_example2 > tensor_example2.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm tensor_example2
#
echo "Normal end of execution."
