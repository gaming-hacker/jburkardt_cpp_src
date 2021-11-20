#! /bin/bash
#
g++ -c -Wall -I/$HOME/include fem2d_pack_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fem2d_pack_test.o /$HOME/libcpp/fem2d_pack.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem2d_pack_test.o
#
mv a.out fem2d_pack_test
./fem2d_pack_test > fem2d_pack_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fem2d_pack_test
#
echo "Normal end of execution."
