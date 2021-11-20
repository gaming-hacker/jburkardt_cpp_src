#! /bin/bash
#
$HOME/bincpp/svd_basis < input.txt > svd_basis_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
