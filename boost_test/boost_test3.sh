#! /bin/bash
#
g++ -c -Wall -I /Users/jburkardt/public_html/cpp_src/boost_1_66_0 boost_test3.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o boost_test3 boost_test3.o -L/Users/jburkardt/public_html/cpp_src/boost_1_66_0/stage/lib
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm boost_test3.o
#
./boost_test3 > boost_test3.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
rm boost_test3
#
echo "Normal end of execution."
