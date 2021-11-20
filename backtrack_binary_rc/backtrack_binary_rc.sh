#! /bin/bash
#
cp backtrack_binary_rc.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include backtrack_binary_rc.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv backtrack_binary_rc.o ~/libcpp/backtrack_binary_rc.o
#
echo "Normal end of execution."
