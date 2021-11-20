#! /bin/bash
#
cp cnf_io.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include cnf_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cnf_io.o ~/libcpp/cnf_io.o
#
echo "Normal end of execution."
