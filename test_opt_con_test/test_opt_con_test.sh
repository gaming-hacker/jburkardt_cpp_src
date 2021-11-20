#! /bin/bash
#
g++ -c -Wall -I/$HOME/include test_opt_con_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ test_opt_con_test.o /$HOME/libcpp/test_opt_con.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_opt_con_test.o
#
mv a.out test_opt_con_test
./test_opt_con_test > test_opt_con_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_opt_con_test
#
echo "Normal end of execution."
