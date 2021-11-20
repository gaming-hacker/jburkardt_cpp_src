#! /bin/bash
#
cp compass_search.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include compass_search.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv compass_search.o ~/libcpp/compass_search.o
#
echo "Normal end of execution."
