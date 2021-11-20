#! /bin/bash
#
g++ -c -Wall curve_plot_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -c -Wall curve_plot.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o curve_plot_test curve_plot_test.o curve_plot.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
./curve_plot_test > curve_plot_test.txt
gnuplot < curve_plot_commands.txt
#
echo "Normal end of execution."
