#! /bin/bash
#
cp cube_integrals.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include cube_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cube_integrals.o ~/libcpp/cube_integrals.o
#
echo "Normal end of execution."
