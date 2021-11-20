#! /bin/bash
#
g++ -c -Wall -I/$HOME/include freefem++_msh_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ -o freefem++_msh_io_test freefem++_msh_io_test.o /$HOME/libcpp/freefem++_msh_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm freefem++_msh_io_test.o
#
./freefem++_msh_io_test > freefem++_msh_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm freefem++_msh_io_test
#
echo "Normal end of execution."
