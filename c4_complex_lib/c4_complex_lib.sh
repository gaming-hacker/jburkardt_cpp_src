#! /bin/bash
#
cp c4_complex_lib.hpp /$HOME/include
#
g++ -c -Wall c4_complex_lib.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv c4_complex_lib.o ~/libcpp/c4_complex_lib.o
#
echo "Normal end of execution."
