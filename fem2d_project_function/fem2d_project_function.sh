#! /bin/bash
#
g++ -c -Wall fem2d_project_function.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fem2d_project_function.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem2d_project_function.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/fem2d_project_function
#
echo "Normal end of execution."
