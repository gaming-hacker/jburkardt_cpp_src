#! /bin/bash
#
cp fn.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include fn.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv fn.o ~/libcpp/fn.o
#
echo "Normal end of execution."
