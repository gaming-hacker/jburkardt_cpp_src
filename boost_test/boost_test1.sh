#! /bin/bash
#
g++ -c -Wall -I /Users/jburkardt/public_html/cpp_src/boost_1_66_0 boost_test1.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o boost_test1 boost_test1.o -L/Users/jburkardt/public_html/cpp_src/boost_1_66_0/stage/lib -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm boost_test1.o
#
./boost_test1 < boost_test1_input.txt > boost_test1.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
rm boost_test1
#
echo "Normal end of execution."
