#! /bin/bash
#
g++ -c -Wall -I/$HOME/include qr_solve_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ qr_solve_test.o /$HOME/libcpp/qr_solve.o /$HOME/libcpp/test_lls.o /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm qr_solve_test.o
#
mv a.out qr_solve_test
./qr_solve_test > qr_solve_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm qr_solve_test
#
echo "Normal end of execution."
