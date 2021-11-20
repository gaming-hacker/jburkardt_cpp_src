#! /bin/bash
#
g++ -c -Wall -I/$HOME/include filon_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ filon_test.o /$HOME/libcpp/filon.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm filon_test.o
#
mv a.out filon_test
./filon_test > filon_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm filon_test
#
echo "Normal end of execution."
