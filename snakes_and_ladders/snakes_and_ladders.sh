#! /bin/bash
#
cp snakes_and_ladders.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include snakes_and_ladders.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv snakes_and_ladders.o ~/libcpp/snakes_and_ladders.o
#
echo "Normal end of execution."
