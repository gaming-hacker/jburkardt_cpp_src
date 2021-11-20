#! /bin/bash
#
echo "Run MPI examples:"
echo "Run bones_mpi"
./bones_mpi.sh
echo "Run buffon_mpi"
./buffon_mpi.sh
echo "Run day1_mpi"
./day1_mpi.sh
echo "Run intervals_mpi"
./intervals_mpi.sh
echo "Run matvec_mpi"
./matvec_mpi.sh
echo "Run monte_carlo_mpi"
./monte_carlo_mpi.sh
echo "Run quadrature_mpi"
./quadrature_mpi.sh
echo "Run search_mpi"
./search_mpi.sh
echo "Run sum_mpi"
./sum_mpi.sh
echo "Run type_mpi"
./type_mpi.sh
#
echo "Normal end of execution."
