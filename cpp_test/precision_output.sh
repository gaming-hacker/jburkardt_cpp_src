#! /bin/bash
#
g++ -c precision_output.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ precision_output.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm precision_output.o
#
mv a.out precision_output
./precision_output > precision_output.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm precision_output
#
echo "Normal end of execution."
