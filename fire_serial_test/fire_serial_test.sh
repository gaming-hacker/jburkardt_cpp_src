#! /bin/bash
#
$HOME/bincpp/fire_serial > fire_serial_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
