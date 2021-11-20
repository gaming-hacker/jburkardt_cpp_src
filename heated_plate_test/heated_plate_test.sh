#! /bin/bash
#
$HOME/bincpp/heated_plate 0.1 sol_500x500.txt > heated_plate_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
