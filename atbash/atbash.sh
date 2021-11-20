#! /bin/bash
#
cp atbash.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include -Wall atbash.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv atbash.o ~/libcpp/atbash.o
#
echo "Normal end of execution."
