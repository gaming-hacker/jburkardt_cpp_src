#! /bin/bash
#
$HOME/bincpp/fem1d_sample < input.txt > fem1d_sample_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
