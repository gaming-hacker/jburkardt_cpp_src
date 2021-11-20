#! /bin/bash
#
cp filon.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include filon.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv filon.o ~/libcpp/filon.o
#
echo "Normal end of execution."
