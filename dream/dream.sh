#! /bin/bash
#
cp dream.hpp /$HOME/include
cp dream_user.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include dream.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv dream.o ~/libcpp/dream.o
#
echo "Normal end of execution."
