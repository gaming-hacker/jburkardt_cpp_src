#! /bin/bash
#
g++ -c -Wall pyramid_exactness.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pyramid_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm pyramid_exactness.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/pyramid_exactness
#
echo "Normal end of execution."
