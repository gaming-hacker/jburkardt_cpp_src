#! /bin/bash
#
$HOME/bincpp/triangle_histogram g10000.txt 4 > triangle_histogram_test.txt
$HOME/bincpp/triangle_histogram b10000.txt 4 >> triangle_histogram_test.txt
#
echo "Normal end of execution."
