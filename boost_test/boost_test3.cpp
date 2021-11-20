# include <algorithm>
# include <iomanip>
# include <iostream>
# include <vector>

# include <boost/accumulators/accumulators.hpp>
# include <boost/accumulators/statistics/density.hpp>
# include <boost/accumulators/statistics/stats.hpp>
 
using namespace boost;
using namespace boost::accumulators;
 
typedef accumulator_set<double, features<tag::density> > acc;
typedef iterator_range<std::vector<std::pair<double, double> >::iterator > histogram_type; 
 
template <typename T>
class data_filler 
{  
public:
  data_filler(){}
  T operator()() { return rand()/(T)RAND_MAX; }
};

//****************************************************************************80

int main ( int argc, char** argv )

//****************************************************************************80
{
  std::cout << "\n";
  std::cout << "BOOST_TEST3:\n";
  std::cout << "  Demonstrate the Boost accumulator function\n";
  std::cout << "  by computing a histogram of 100 random values.\n";
//
//  Create some random data.
//
  std::vector<double> data(100);

  std::generate ( data.begin(), data.end(), data_filler<double>() );
//
//  Cache size for histogram.
//
  int c = data.size();
//
//  Create an accumulator with 20 bins.
//
  acc myAccumulator ( tag::density::num_bins = 20, tag::density::cache_size = 10 );
//
//  Fill the accumulator with the data.
//
  for ( int j = 0; j < c; ++j )
  {
    myAccumulator ( data[j] );
  }
//
//  Label the bins by their "density".
//
  histogram_type hist = density ( myAccumulator );
 
  std::cout << "\n";
  std::cout << "  Lower Bound    Density\n";
  std::cout << "\n";

  double total = 0.0;
 
  for( unsigned int i = 0; i < hist.size(); i++ ) 
  {
    std::cout << "   " << std::setw(10) << hist[i].first 
              << "      " << std::setw(5)  << hist[i].second << std::endl; 

    total += hist[i].second;
  }

  std::cout << "\n"; 
  std::cout << "Total: (should be 1): " << total << std::endl;
//
//  Terminate.
//
  std::cout << "\n";
  std::cout << "BOOST_TEST3:\n";
  std::cout << "  Normal end of execution.\n";
 
  return 0;
}
