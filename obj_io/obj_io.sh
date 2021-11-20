#! /bin/bash
#
cp obj_io.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include obj_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv obj_io.o ~/libcpp/obj_io.o
#
echo "Normal end of execution."
