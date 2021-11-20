#! /bin/bash
#
g++ -c -Wall -I/$HOME/include r8st_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ r8st_test.o /$HOME/libcpp/r8st.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm r8st_test.o
#
mv a.out r8st_test
./r8st_test > r8st_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm r8st_test
#
echo "Normal end of execution."
