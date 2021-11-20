#! /bin/bash
#
g++ -c function_pointer_array_new.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ function_pointer_array_new.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm function_pointer_array_new.o
#
mv a.out function_pointer_array_new
./function_pointer_array_new > function_pointer_array_new.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm function_pointer_array_new
#
echo "Normal end of execution."
