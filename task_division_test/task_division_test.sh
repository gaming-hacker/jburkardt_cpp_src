#! /bin/bash
#
g++ -c -Wall -I/$HOME/include task_division_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ task_division_test.o /$HOME/libcpp/task_division.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm task_division_test.o
#
mv a.out task_division_test
./task_division_test > task_division_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm task_division_test
#
echo "Normal end of execution."
