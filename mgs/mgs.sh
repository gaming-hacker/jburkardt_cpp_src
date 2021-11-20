#! /bin/bash
#
cp mgs.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include mgs.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv mgs.o ~/libcpp/mgs.o
#
echo "Normal end of execution."
