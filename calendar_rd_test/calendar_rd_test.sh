#! /bin/bash
#
$HOME/bincpp/calendar_rd < input.txt > calendar_rd_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
echo "Normal end of execution."
