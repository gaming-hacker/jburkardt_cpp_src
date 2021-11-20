#! /bin/bash
#
cp ppmb_io.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include ppmb_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ppmb_io.o ~/libcpp/ppmb_io.o
#
echo "Normal end of execution."
