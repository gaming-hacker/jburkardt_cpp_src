#! /bin/bash
#
$HOME/bincpp/rot13 gettysburg.txt > rot13_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
