#! /bin/bash
#
$HOME/bincpp/quad2d_serial > quad2d_serial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
