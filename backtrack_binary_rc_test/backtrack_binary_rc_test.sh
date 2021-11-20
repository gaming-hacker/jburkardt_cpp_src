#! /bin/bash
#
g++ -c -Wall -I/$HOME/include backtrack_binary_rc_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ backtrack_binary_rc_test.o /$HOME/libcpp/backtrack_binary_rc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm backtrack_binary_rc_test.o
#
mv a.out backtrack_binary_rc_test
./backtrack_binary_rc_test > backtrack_binary_rc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm backtrack_binary_rc_test
#
echo "Normal end of execution."
