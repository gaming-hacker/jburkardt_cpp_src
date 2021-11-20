#! /bin/bash
#
cp toms577.hpp /$HOME/include
#
g++ -c -I/$HOME/include toms577.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms577.o ~/libcpp/toms577.o
#
echo "Normal end of execution."
