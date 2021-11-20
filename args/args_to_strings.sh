#! /bin/bash
#
g++ -c -Wall args_to_strings.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o args_to_strings args_to_strings.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
chmod ugo+x args_to_strings
mv args_to_strings ~/bincpp/args_to_strings
#
echo "Normal end of execution."
