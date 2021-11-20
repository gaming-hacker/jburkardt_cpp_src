#! /bin/bash
#
$HOME/bincpp/poisson_serial > poisson_serial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
