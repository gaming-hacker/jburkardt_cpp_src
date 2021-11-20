#! /bin/bash
#
g++ -c function_pointer_array.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ function_pointer_array.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm function_pointer_array.o
#
mv a.out function_pointer_array
./function_pointer_array > function_pointer_array.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm function_pointer_array
#
echo "Normal end of execution."
