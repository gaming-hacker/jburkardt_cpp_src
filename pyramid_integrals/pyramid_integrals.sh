#! /bin/bash
#
cp pyramid_integrals.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include pyramid_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pyramid_integrals.o ~/libcpp/pyramid_integrals.o
#
echo "Normal end of execution."
