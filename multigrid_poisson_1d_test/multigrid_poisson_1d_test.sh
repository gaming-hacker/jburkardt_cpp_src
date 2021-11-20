#! /bin/bash
#
g++ -c -Wall -I$HOME/include multigrid_poisson_1d_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ multigrid_poisson_1d_test.o /$HOME/libcpp/multigrid_poisson_1d.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm multigrid_poisson_1d_test.o
#
mv a.out multigrid_poisson_1d_test
./multigrid_poisson_1d_test > multigrid_poisson_1d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm multigrid_poisson_1d_test
#
echo "Normal end of execution."
