#! /bin/bash
#
cp toms112.hpp /$HOME/include
#
gcc -c -Wall toms112.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms112.o ~/libcpp/toms112.o
#
echo "Normal end of execution."
