#! /bin/bash
#
cp wavelet.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include wavelet.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv wavelet.o ~/libcpp/wavelet.o
#
echo "Normal end of execution."
