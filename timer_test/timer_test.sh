#! /bin/bash
#
./timer_clock.sh > timer_test.txt
./timer_clock.sh >> timer_test.txt
./timer_omp_get_wtime.sh >> timer_test.txt
./timer_time.sh >> timer_test.txt
#
echo "Normal end of execution."
