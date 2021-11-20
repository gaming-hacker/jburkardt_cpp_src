#! /bin/bash
#
g++ -c -Wall -I$HOME/include svd_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ svd_test.o $HOME/libcpp/linpack_d.o $HOME/libcpp/blas1_d.o /$HOME/libcpp/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm svd_test.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/svd_test
#
echo "Normal end of execution."
