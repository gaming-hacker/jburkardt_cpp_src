#! /bin/bash
#
$HOME/bincpp/discrete_pdf_sample_2d > discrete_pdf_sample_2d_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
