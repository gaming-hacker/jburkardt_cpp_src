#! /bin/bash
#
$HOME/bincpp/string_simulation > string_simulation_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
