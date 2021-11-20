#! /bin/bash
#
g++ -c -Wall -I/$HOME/include treepack_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ treepack_test.o /$HOME/libcpp/treepack.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm treepack_test.o
#
mv a.out treepack_test
./treepack_test > treepack_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm treepack_test
#
echo "Normal end of execution."
