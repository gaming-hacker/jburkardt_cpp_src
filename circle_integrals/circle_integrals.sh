#! /bin/bash
#
cp circle_integrals.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include circle_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv circle_integrals.o ~/libcpp/circle_integrals.o
#
echo "Normal end of execution."
