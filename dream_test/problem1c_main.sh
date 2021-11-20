#! /bin/bash
#
g++ -c -Wall -I/$HOME/include problem1c_main.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -c -I/$HOME/include problem1c.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -c -I/$HOME/include problem1c_covariance.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ problem1c_main.o \
    problem1c.o \
    problem1c_covariance.o \
  /$HOME/libcpp/pdflib.o \
  /$HOME/libcpp/rnglib.o \
  -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm problem1c_main.o
rm problem1c.o
rm problem1c_covariance.o
#
mv a.out problem1c_main
./problem1c_main > problem1c_main_output.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm problem1c_main
#
echo "Normal end of execution."
