#! /bin/bash
#
cp high_card_simulation.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include high_card_simulation.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv high_card_simulation.o ~/libcpp/high_card_simulation.o
#
echo "Normal end of execution."
