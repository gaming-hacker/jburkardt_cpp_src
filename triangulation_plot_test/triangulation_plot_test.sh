#! /bin/bash
#
$HOME/bincpp/triangulation_plot elbow3 1 2 > triangulation_plot_test.txt
$HOME/bincpp/triangulation_plot ell3 2 1 >> triangulation_plot_test.txt
$HOME/bincpp/triangulation_plot ell6 2 2 >> triangulation_plot_test.txt
$HOME/bincpp/triangulation_plot hex_holes3 1 1 >> triangulation_plot_test.txt
$HOME/bincpp/triangulation_plot lake3 1 1 >> triangulation_plot_test.txt
#
echo "Normal end of execution."
