#! /bin/bash
#
cp st_to_ccs.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include st_to_ccs.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv st_to_ccs.o ~/libcpp/st_to_ccs.o
#
echo "Normal end of execution."
