#! /bin/bash
#
$HOME/bincpp/hexdump text.txt > hexdump_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
