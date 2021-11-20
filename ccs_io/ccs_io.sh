#! /bin/bash
#
cp ccs_io.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include ccs_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ccs_io.o ~/libcpp/ccs_io.o
#
echo "Normal end of execution."
