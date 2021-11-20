#! /bin/bash
#
$HOME/bincpp/i2_binary_to_ascii > i2_binary_to_ascii_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
