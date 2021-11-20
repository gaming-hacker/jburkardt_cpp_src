#! /bin/bash
#
cp ball_integrals.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include ball_integrals.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ball_integrals.o ~/libcpp/ball_integrals.o
#
echo "Normal end of execution."
