#! /bin/bash
#
g++ -c -Wall -I/$HOME/include cnf_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ cnf_io_test.o /$HOME/libcpp/cnf_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cnf_io_test.o
#
mv a.out cnf_io_test
./cnf_io_test > cnf_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cnf_io_test
#
echo "Normal end of execution."
