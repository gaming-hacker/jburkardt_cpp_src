#! /bin/bash
#
cp image_denoise.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include image_denoise.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv image_denoise.o ~/libcpp/image_denoise.o
#
echo "Normal end of execution."
