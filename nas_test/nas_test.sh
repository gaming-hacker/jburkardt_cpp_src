#! /bin/bash
#
$HOME/bincpp/nas > nas_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
