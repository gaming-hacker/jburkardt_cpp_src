#! /bin/bash
#
g++ -c -Wall test02.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ test02.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
mv a.out test02
echo "Executable created as test02"
#
#  Run program
#
./test02 > test02.txt
echo "Executable output stored as test02.txt"
#
#  Rerun program with valgrind
#
valgrind --dsymutil=yes ./test02 &> test02_valgrind.txt
echo "Valgrind output stored as test02_valgrind.txt"
#
#  Don't delete object until later.
#
rm test02.o
#
echo "Normal end of execution."
