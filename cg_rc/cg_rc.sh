#! /bin/bash
#
cp cg_rc.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include cg_rc.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cg_rc.o ~/libcpp/cg_rc.o
#
echo "Normal end of execution."
