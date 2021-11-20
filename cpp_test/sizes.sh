#! /bin/bash
#
g++ -c sizes.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ sizes.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm sizes.o
#
mv a.out sizes
./sizes > sizes.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sizes
#
echo "Normal end of execution."
