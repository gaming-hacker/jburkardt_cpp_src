#! /bin/bash
#
$HOME/bincpp/simple_ga > simple_ga_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
