#! /bin/bash
#
g++ -c -Wall metis_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ metis_test.o -L /usr/local/lib -lmetis
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm metis_test.o
#
mv a.out metis_test
./metis_test > metis_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm metis_test
#
echo "Normal end of execution."
