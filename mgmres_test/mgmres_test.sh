#! /bin/bash
#
g++ -c -Wall -I/$HOME/include mgmres_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ mgmres_test.o /$HOME/libcpp/mgmres.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm mgmres_test.o
#
mv a.out mgmres_test
./mgmres_test > mgmres_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm mgmres_test
#
echo "Normal end of execution."
