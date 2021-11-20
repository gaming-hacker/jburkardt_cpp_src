#! /bin/bash
#
g++ -c -Wall -I/$HOME/include local_min_rc_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ local_min_rc_test.o /$HOME/libcpp/local_min_rc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm local_min_rc_test.o
#
mv a.out local_min_rc_test
./local_min_rc_test > local_min_rc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm local_min_rc_test
#
echo "Normal end of execution."
