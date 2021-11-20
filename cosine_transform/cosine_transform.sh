#! /bin/bash
#
cp cosine_transform.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include cosine_transform.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cosine_transform.o ~/libcpp/cosine_transform.o
#
echo "Normal end of execution."
