#! /bin/bash
#
g++ -c complex_values.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ complex_values.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm complex_values.o
#
mv a.out complex_values
./complex_values > complex_values.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm complex_values
#
echo "Normal end of execution."
