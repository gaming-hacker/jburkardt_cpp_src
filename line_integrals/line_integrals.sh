#! /bin/bash
#
cp line_integrals.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include line_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv line_integrals.o ~/libcpp/line_integrals.o
#
echo "Normal end of execution."
