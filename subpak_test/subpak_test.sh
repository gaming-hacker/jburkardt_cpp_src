#! /bin/bash
#
g++ -c -Wall -I/$HOME/include subpak_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ subpak_test.o /$HOME/libcpp/subpak.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm subpak_test.o
#
mv a.out subpak_test
./subpak_test > subpak_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm subpak_test
#
echo "Normal end of execution."
