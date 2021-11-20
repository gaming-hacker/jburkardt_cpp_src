#! /bin/bash
#
cp owen.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include owen.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv owen.o ~/libcpp/owen.o
#
echo "Normal end of execution."
