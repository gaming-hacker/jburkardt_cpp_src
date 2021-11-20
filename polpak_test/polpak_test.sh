#! /bin/bash
#
g++ -c -Wall -I/$HOME/include polpak_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ polpak_test.o /$HOME/libcpp/polpak.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm polpak_test.o
#
mv a.out polpak_test
./polpak_test > polpak_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm polpak_test
#
echo "Normal end of execution."
