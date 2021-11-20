#! /bin/bash
#
g++ -c -Wall -I$HOME/include mgs_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ mgs_test.o $HOME/libcpp/mgs.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm mgs_test.o
#
mv a.out mgs_test
./mgs_test > mgs_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm mgs_test
#
echo "Normal end of execution."
