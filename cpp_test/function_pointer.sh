#! /bin/bash
#
g++ -c function_pointer.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ function_pointer.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm function_pointer.o
#
mv a.out function_pointer
./function_pointer > function_pointer.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm function_pointer
#
echo "Normal end of execution."
