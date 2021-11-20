#! /bin/bash
#
cp change_making.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include change_making.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv change_making.o ~/libcpp/change_making.o
#
echo "Normal end of execution."
