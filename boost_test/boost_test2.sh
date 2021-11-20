#! /bin/bash
#
g++ -c -Wall -I /Users/jburkardt/public_html/cpp_src/boost_1_66_0 boost_test2.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#  In order to use dynamic libraries on OSX, you need to do this:
#
export BOOST=/Users/jburkardt/public_html/cpp_src/boost_1_66_0/stage/lib
export DYLD_LIBRARY_PATH=$BOOST:$DYLD_LIBRARY_PATH
#
g++ -o boost_test2 boost_test2.o -L/Users/jburkardt/public_html/cpp_src/boost_1_66_0/stage/lib -lboost_regex
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm boost_test2.o
#
./boost_test2 < boost_test2_input.txt > boost_test2.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
rm boost_test2
#
echo "Normal end of execution."
