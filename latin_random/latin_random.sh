#! /bin/bash
#
cp latin_random.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include latin_random.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv latin_random.o ~/libcpp/latin_random.o
#
echo "Normal end of execution."
