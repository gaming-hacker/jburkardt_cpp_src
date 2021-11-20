#! /bin/bash
#
g++ -c dynamic_array_2d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o dynamic_array_2d dynamic_array_2d.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm dynamic_array_2d.o
#
./dynamic_array_2d > dynamic_array_2d.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm dynamic_array_2d
#
echo "Normal end of execution."
