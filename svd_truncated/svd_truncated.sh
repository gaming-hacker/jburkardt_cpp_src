#! /bin/bash
#
g++ -c -Wall -I$HOME/include svd_truncated.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ svd_truncated.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm svd_truncated.o
#
chmod ugo+x a.out
mv a.out $HOME/bincpp/svd_truncated
#
echo "Normal end of execution."
