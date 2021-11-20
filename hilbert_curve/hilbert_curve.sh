#! /bin/bash
#
cp hilbert_curve.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include hilbert_curve.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hilbert_curve.o ~/libcpp/hilbert_curve.o
#
echo "Normal end of execution."
