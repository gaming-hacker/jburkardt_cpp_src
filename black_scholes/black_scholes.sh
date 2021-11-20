#! /bin/bash
#
cp black_scholes.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include black_scholes.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv black_scholes.o ~/libcpp/black_scholes.o
#
echo "Normal end of execution."
