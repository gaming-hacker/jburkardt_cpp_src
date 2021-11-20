#! /bin/bash
#
cp image_components.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include image_components.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv image_components.o ~/libcpp/image_components.o
#
echo "Normal end of execution."
