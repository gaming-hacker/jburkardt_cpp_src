# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cstring>
# include <cmath>
# include <ctime>

using namespace std;

# include "quadrature_least_squares.hpp"
# include "qr_solve.hpp"
# include "r8lib.hpp"

//****************************************************************************80

void ncc_set ( int order, double x[], double w[] )

//****************************************************************************80
//
//  Purpose:
//
//    NCC_SET sets abscissas and weights for closed Newton-Cotes quadrature.
//
//  Discussion:
//
//    The closed Newton-Cotes rules use equally spaced abscissas, and
//    hence may be used with tabulated function data.
//
//    The rules are called "closed" because they include the endpoints.
//    As a favor, we include an order 1 rule, the midpoint rule, even 
//    though this does not satisfy the requirement that the endpoints
//    be included//
//
//    The higher order rules involve negative weights.  These can produce
//    loss of accuracy due to the subtraction of large, nearly equal quantities.
//
//    ORDER = 1 is the midpoint rule (and is not really an NCC rule//)
//    ORDER = 2 is the trapezoidal rule.
//    ORDER = 3 is Simpson's rule.
//    ORDER = 4 is Simpson's 3/8 rule.
//    ORDER = 5 is Bode's rule.
//
//    The Kopal reference for ORDER = 12 lists
//      W(6) = 15494566.0D+00 / 43545600.0D+00
//    but this results in a set of coeffients that don't add up to 2.
//    The correct value is
//      W(6) = 15493566.0D+00 / 43545600.0.
//
//    The integral:
//
//      Integral ( -1 <= X <= 1 ) F(X) dX
//
//    The quadrature rule:
//
//      Sum ( 1 <= I <= ORDER ) W(I) * F ( X(I) )
//
//    In Mathematica, the closed Newton-Cotes weights
//    can be computed by:
//
//      Needs["NumericalDifferentialEquationAnalysis`"]
//      NewtonCotesWeights [ order, -1, 1, QuadratureType -> Closed ]
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    20 April 2010
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Milton Abramowitz, Irene Stegun,
//    Handbook of Mathematical Functions,
//    National Bureau of Standards, 1964,
//    ISBN: 0-486-61272-4,
//    LC: QA47.A34.
//
//    Johnson,
//    Quarterly Journal of Mathematics,
//    Volume 46, Number 52, 1915.
//
//    Zdenek Kopal,
//    Numerical Analysis,
//    John Wiley, 1955,
//    LC: QA297.K6.
//
//    Stephen Wolfram,
//    The Mathematica Book,
//    Fourth Edition,
//    Cambridge University Press, 1999,
//    ISBN: 0-521-64314-7,
//    LC: QA76.95.W65.
//
//    Daniel Zwillinger, editor,
//    CRC Standard Mathematical Tables and Formulae,
//    30th Edition,
//    CRC Press, 1996,
//    ISBN: 0-8493-2479-3,
//    LC: QA47.M315.
//
//  Parameters:
//
//    Input, int ORDER, the order.
//    ORDER must be between 1 and 21.
//
//    Output, double X[ORDER], the abscissas.
//
//    Output, double W[ORDER], the weights.
//
{
  if ( order == 1 )
  {
//
//  2
//
    x[0] = 0.00000000000000000000;

    w[0] = 2.00000000000000000000;
  }
  else if ( order == 2 )
  {
//
//  1
//  1
//
    x[0] = -1.00000000000000000000;
    x[1] =  1.00000000000000000000;

    w[0] = 1.00000000000000000000;
    w[1] = 1.00000000000000000000;
  }
  else if ( order == 3 )
  {
//
//  1 / 3
//  4 / 3
//  1 / 3
//
    x[0] = -1.00000000000000000000;
    x[1] =  0.00000000000000000000;
    x[2] =  1.00000000000000000000;

    w[0] = 0.33333333333333333333;
    w[1] = 1.33333333333333333333;
    w[2] = 0.33333333333333333333;
  }
  else if ( order == 4 )
  {
//
//  1 / 4
//  3 / 4
//  3 / 4
//  1 / 4
//
    x[0] = -1.00000000000000000000;
    x[1] = -0.33333333333333333333;
    x[2] =  0.33333333333333333333;
    x[3] =  1.00000000000000000000;

    w[0] = 0.25000000000000000000;
    w[1] = 0.75000000000000000000;
    w[2] = 0.75000000000000000000;
    w[3] = 0.25000000000000000000;
  }
  else if ( order == 5 )
  {
//
//   7 / 45
//  32 / 45
//  12 / 45
//  32 / 45
//   7 / 45
//
    x[0] = -1.00000000000000000000;
    x[1] = -0.50000000000000000000;
    x[2] =  0.00000000000000000000;
    x[3] =  0.50000000000000000000;
    x[4] =  1.00000000000000000000;

    w[0] = 0.15555555555555555556;
    w[1] = 0.71111111111111111111;
    w[2] = 0.26666666666666666667;
    w[3] = 0.71111111111111111111;
    w[4] = 0.15555555555555555556;
  }
  else if ( order == 6 )
  {
//
//  19 / 144
//  75 / 144
//  50 / 144
//  50 / 144
//  75 / 144
//  19 / 144
//
    x[0] = -1.00000000000000000000;
    x[1] = -0.60000000000000000000;
    x[2] = -0.20000000000000000000;
    x[3] =  0.20000000000000000000;
    x[4] =  0.60000000000000000000;
    x[5] =  1.00000000000000000000;

    w[0] = 0.13194444444444444444;
    w[1] = 0.52083333333333333333;
    w[2] = 0.34722222222222222222;
    w[3] = 0.34722222222222222222;
    w[4] = 0.52083333333333333333;
    w[5] = 0.13194444444444444444;
  }
  else if ( order == 7 )
  {
//
//   41 / 420
//  216 / 420
//   27 / 420
//  272 / 420
//   27 / 420
//  216 / 420
//   41 / 420
//
    x[0] = -1.00000000000000000000;
    x[1] = -0.66666666666666666667;
    x[2] = -0.33333333333333333333;
    x[3] =  0.00000000000000000000;
    x[4] =  0.33333333333333333333;
    x[5] =  0.66666666666666666667;
    x[6] =  1.00000000000000000000;

    w[0] = 0.097619047619047619048;
    w[1] = 0.51428571428571428571;
    w[2] = 0.064285714285714285714;
    w[3] = 0.64761904761904761905;
    w[4] = 0.064285714285714285714;
    w[5] = 0.51428571428571428571;
    w[6] = 0.097619047619047619048;
  }
  else if ( order == 8 )
  {
//
//   751 / 8640
//  3577 / 8640
//  1323 / 8640
//  2989 / 8640
//  2989 / 8640
//  1323 / 8640
//  3577 / 8640
//   751 / 8640
//
    x[0] = -1.00000000000000000000;
    x[1] = -0.71428571428571428571;
    x[2] = -0.42857142857142857143;
    x[3] = -0.14285714285714285714;
    x[4] =  0.14285714285714285714;
    x[5] =  0.42857142857142857143;
    x[6] =  0.71428571428571428571;
    x[7] =  1.00000000000000000000;

    w[0] = 0.086921296296296296296;
    w[1] = 0.41400462962962962963;
    w[2] = 0.15312500000000000000;
    w[3] = 0.34594907407407407407;
    w[4] = 0.34594907407407407407;
    w[5] = 0.15312500000000000000;
    w[6] = 0.41400462962962962963;
    w[7] = 0.086921296296296296296;
  }
  else if ( order == 9 )
  {
//
//    989 / 14175
//   5888 / 14175
//   -928 / 14175
//  10496 / 14175
//  -4540 / 14175
//  10496 / 14175
//   -928 / 14175
//   5888 / 14175
//    989 / 14175
//
    x[0] = -1.00000000000000000000;
    x[1] = -0.75000000000000000000;
    x[2] = -0.50000000000000000000;
    x[3] = -0.25000000000000000000;
    x[4] =  0.00000000000000000000;
    x[5] =  0.25000000000000000000;
    x[6] =  0.50000000000000000000;
    x[7] =  0.75000000000000000000;
    x[8] =  1.00000000000000000000;

    w[0] =  0.069770723104056437390;
    w[1] =  0.41537918871252204586;
    w[2] = -0.065467372134038800705;
    w[3] =  0.74045855379188712522;
    w[4] = -0.32028218694885361552;
    w[5] =  0.74045855379188712522;
    w[6] = -0.065467372134038800705;
    w[7] =  0.41537918871252204586;
    w[8] =  0.069770723104056437390;
  }
  else if ( order == 10 )
  {
//
//   2857 / 44800
//  15741 / 44800
//   1080 / 44800
//  19344 / 44800
//   5778 / 44800
//   5778 / 44800
//  19344 / 44800
//   1080 / 44800
//  15741 / 44800
//   2857 / 44800
//
    x[0] = -1.00000000000000000000;
    x[1] = -0.77777777777777777778;
    x[2] = -0.55555555555555555556;
    x[3] = -0.33333333333333333333;
    x[4] = -0.11111111111111111111;
    x[5] =  0.11111111111111111111;
    x[6] =  0.33333333333333333333;
    x[7] =  0.55555555555555555556;
    x[8] =  0.77777777777777777778;
    x[9] =  1.00000000000000000000;

    w[0] =  0.063772321428571428571;
    w[1] =  0.35136160714285714286;
    w[2] =  0.024107142857142857143;
    w[3] =  0.43178571428571428571;
    w[4] =  0.12897321428571428571;
    w[5] =  0.12897321428571428571;
    w[6] =  0.43178571428571428571;
    w[7] =  0.024107142857142857143;
    w[8] =  0.35136160714285714286;
    w[9] =  0.063772321428571428571;
  }
  else if ( order == 11 )
  {
//
//     16067 / 299376
//    106300 / 299376
//   - 48525 / 299376
//    272400 / 299376
//  - 260550 / 299376
//    427368 / 299376
//  - 260550 / 299376
//    272400 / 299376
//   - 48525 / 299376
//    106300 / 299376
//     16067 / 299376
//
    x[0] = -1.00000000000000000000;
    x[1] = -0.80000000000000000000;
    x[2] = -0.60000000000000000000;
    x[3] = -0.40000000000000000000;
    x[4] = -0.20000000000000000000;
    x[5] =  0.00000000000000000000;
    x[6] =  0.20000000000000000000;
    x[7] =  0.40000000000000000000;
    x[8] =  0.60000000000000000000;
    x[9] =  0.80000000000000000000;
    x[10] = 1.00000000000000000000;

    w[0] =  0.053668296723852279408;
    w[1] =  0.35507188284966062744;
    w[2] = -0.16208714125380792047;
    w[3] =  0.90989257655924322591;
    w[4] = -0.87031024531024531025;
    w[5] =  1.4275292608625941959;
    w[6] = -0.87031024531024531025;
    w[7] =  0.90989257655924322591;
    w[8] = -0.16208714125380792047;
    w[9] =  0.35507188284966062744;
    w[10] = 0.053668296723852279408;
  }
  else if ( order == 12 )
  {
//
//     2171465 / 43545600
//    13486539 / 43545600
//   - 3237113 / 43545600
//    25226685 / 43545600
//   - 9595542 / 43545600
//    15493566 / 43545600
//    15493566 / 43545600
//   - 9595542 / 43545600
//    25226685 / 43545600
//   - 3237113 / 43545600
//    13486539 / 43545600
//     2171465 / 43545600
//
    x[0] = -1.00000000000000000000;
    x[1] = -0.81818181818181818182;
    x[2] = -0.63636363636363636364;
    x[3] = -0.45454545454545454545;
    x[4] = -0.27272727272727272727;
    x[5] = -0.090909090909090909091;
    x[6] =  0.090909090909090909091;
    x[7] =  0.27272727272727272727;
    x[8] =  0.45454545454545454545;
    x[9] =  0.63636363636363636364;
    x[10] = 0.81818181818181818182;
    x[11] = 1.00000000000000000000;

    w[0] =   0.049866461823927101705;
    w[1] =   0.30971071704144620811;
    w[2] =  -0.074338463587595532040;
    w[3] =   0.57931650958994708995;
    w[4] =  -0.22035617835097001764;
    w[5] =   0.35580095348324514991;
    w[6] =   0.35580095348324514991;
    w[7] =  -0.22035617835097001764;
    w[8] =   0.57931650958994708995;
    w[9] =  -0.074338463587595532040;
    w[10] =  0.30971071704144620811;
    w[11] =  0.049866461823927101705;
  }
  else if ( order == 13 )
  {
//
//      1364651 / 31531500
//      9903168 / 31531500
//    - 7587864 / 31531500
//     35725120 / 31531500
//   - 51491295 / 31531500
//     87516288 / 31531500
//   - 87797136 / 31531500
//     87516288 / 31531500
//   - 51491295 / 31531500
//     35725120 / 31531500
//    - 7587864 / 31531500
//      9903168 / 31531500
//      1364651 / 31531500
//
    x[0] = -1.00000000000000000000;
    x[1] = -0.83333333333333333333;
    x[2] = -0.66666666666666666667;
    x[3] = -0.50000000000000000000;
    x[4] = -0.33333333333333333333;
    x[5] = -0.16666666666666666667;
    x[6] =  0.00000000000000000000;
    x[7] =  0.16666666666666666667;
    x[8] =  0.33333333333333333333;
    x[9] =  0.50000000000000000000;
    x[10] = 0.66666666666666666667;
    x[11] = 0.83333333333333333333;
    x[12] = 1.00000000000000000000;

    w[0] =   0.043278974993260707546;
    w[1] =   0.31407221350078492936;
    w[2] =  -0.24064392750107035821;
    w[3] =   1.1329977958549387121;
    w[4] =  -1.6330112744398458684;
    w[5] =   2.7755193378050520908;
    w[6] =  -2.7844262404262404262;
    w[7] =   2.7755193378050520908;
    w[8] =  -1.6330112744398458684;
    w[9] =   1.1329977958549387121;
    w[10] = -0.24064392750107035821;
    w[11] =  0.31407221350078492936;
    w[12] =  0.043278974993260707546;
  }
  else if ( order == 14 )
  {
//
//      6137698213 / 150885504000
//     42194238652 / 150885504000
//   - 23361540993 / 150885504000
//    116778274403 / 150885504000
//  - 113219777650 / 150885504000
//    154424590209 / 150885504000
//   - 32067978834 / 150885504000
//   - 32067978834 / 150885504000
//    154424590209 / 150885504000
//  - 113219777650 / 150885504000
//    116778274403 / 150885504000
//   - 23361540993 / 150885504000
//     42194238652 / 150885504000
//      6137698213 / 150885504000
//
    x[0] = -1.00000000000000000000;
    x[1] = -0.84615384615384615385;
    x[2] = -0.69230769230769230769;
    x[3] = -0.53846153846153846154;
    x[4] = -0.38461538461538461538;
    x[5] = -0.23076923076923076923;
    x[6] = -0.076923076923076923077;
    x[7] =  0.076923076923076923077;
    x[8] =  0.23076923076923076923;
    x[9] =  0.38461538461538461538;
    x[10] = 0.53846153846153846154;
    x[11] = 0.69230769230769230769;
    x[12] = 0.84615384615384615385;
    x[13] = 1.00000000000000000000;

    w[0] =   0.040669438210247155353;
    w[1] =   0.27975217053157074652;
    w[2] =  -0.15542374057682837445;
    w[3] =   0.77579230848776566369;
    w[4] =  -0.75384763266423526013;
    w[5] =   1.0273523591123107492;
    w[6] =  -0.21429490310083068020;
    w[7] =  -0.21429490310083068020;
    w[8] =   1.0273523591123107492;
    w[9] =  -0.75384763266423526013;
    w[10] =  0.77579230848776566369;
    w[11] = -0.15542374057682837445;
    w[12] =  0.27975217053157074652;
    w[13] =  0.040669438210247155353;
  }
  else if ( order == 15 )
  {
//
//       90241897 / 2501928000
//      710986864 / 2501928000
//    - 770720657 / 2501928000
//     3501442784 / 2501928000
//   - 6625093363 / 2501928000
//    12630121616 / 2501928000
//  - 16802270373 / 2501928000
//    19534438464 / 2501928000
//  - 16802270373 / 2501928000
//    12630121616 / 2501928000
//   - 6625093363 / 2501928000
//     3501442784 / 2501928000
//    - 770720657 / 2501928000
//      710986864 / 2501928000
//       90241897 / 2501928000
//
    x[0] = -1.00000000000000000000;
    x[1] = -0.85714285714285714286;
    x[2] = -0.71428571428571428571;
    x[3] = -0.57142857142857142857;
    x[4] = -0.42857142857142857143;
    x[5] = -0.28571428571428571429;
    x[6] = -0.14285714285714285714;
    x[7] =  0.00000000000000000000;
    x[8] =  0.14285714285714285714;
    x[9] =  0.28571428571428571429;
    x[10] = 0.42857142857142857143;
    x[11] = 0.57142857142857142857;
    x[12] = 0.71428571428571428571;
    x[13] = 0.85714285714285714286;
    x[14] = 1.00000000000000000000;

    w[0] =   0.036068942431596752584;
    w[1] =   0.28417558938546592868;
    w[2] =  -0.30805069410470645039;
    w[3] =   1.3994978208805369299;
    w[4] =  -2.6479952112930507992;
    w[5] =   5.0481555088715582543;
    w[6] =  -6.7157289790113864188;
    w[7] =   7.8077540456799716059;
    w[8] =  -6.7157289790113864188;
    w[9] =   5.0481555088715582543;
    w[10] = -2.6479952112930507992;
    w[11] =  1.3994978208805369299;
    w[12] = -0.30805069410470645039;
    w[13] =  0.28417558938546592868;
    w[14] =  0.036068942431596752584;
  }
  else if ( order == 16 )
  {
//
//     105930069 / 3099672576
//     796661595 / 3099672576
//   - 698808195 / 3099672576
//    3143332755 / 3099672576
//  - 4688522055 / 3099672576
//    7385654007 / 3099672576
//  - 6000998415 / 3099672576
//    3056422815 / 3099672576
//    3056422815 / 3099672576
//  - 6000998415 / 3099672576
//    7385654007 / 3099672576
//  - 4688522055 / 3099672576
//    3143332755 / 3099672576
//   - 698808195 / 3099672576
//     796661595 / 3099672576
//     105930069 / 3099672576
//
    x[0] = -1.00000000000000000000;
    x[1] = -0.86666666666666666667;
    x[2] = -0.73333333333333333333;
    x[3] = -0.60000000000000000000;
    x[4] = -0.46666666666666666667;
    x[5] = -0.33333333333333333333;
    x[6] = -0.20000000000000000000;
    x[7] = -0.066666666666666666667;
    x[8] =  0.066666666666666666667;
    x[9] =  0.20000000000000000000;
    x[10] = 0.33333333333333333333;
    x[11] = 0.46666666666666666667;
    x[12] = 0.60000000000000000000;
    x[13] = 0.73333333333333333333;
    x[14] = 0.86666666666666666667;
    x[15] = 1.00000000000000000000;

    w[0] =   0.034174599543251887002;
    w[1] =   0.25701475735481036820;
    w[2] =  -0.22544581011901045383;
    w[3] =   1.0140854164204471124;
    w[4] =  -1.5125862296882804695;
    w[5] =   2.3827206990135980091;
    w[6] =  -1.9360104229924960952;
    w[7] =   0.98604699046767964179;
    w[8] =   0.98604699046767964179;
    w[9] =  -1.9360104229924960952;
    w[10] =  2.3827206990135980091;
    w[11] = -1.5125862296882804695;
    w[12] =  1.0140854164204471124;
    w[13] = -0.22544581011901045383;
    w[14] =  0.25701475735481036820;
    w[15] =  0.034174599543251887002;
  }
  else if ( order == 17 )
  {
//
//       15043611773 / 488462349375
//      127626606592 / 488462349375
//    - 179731134720 / 488462349375
//      832211855360 / 488462349375
//   - 1929498607520 / 488462349375
//     4177588893696 / 488462349375
//   - 6806534407936 / 488462349375
//     9368875018240 / 488462349375
//  - 10234238972220 / 488462349375
//     9368875018240 / 488462349375
//   - 6806534407936 / 488462349375
//     4177588893696 / 488462349375
//   - 1929498607520 / 488462349375
//      832211855360 / 488462349375
//    - 179731134720 / 488462349375
//      127626606592 / 488462349375
//       15043611773 / 488462349375
//
    x[0] = -1.00000000000000000000;
    x[1] = -0.87500000000000000000;
    x[2] = -0.75000000000000000000;
    x[3] = -0.62500000000000000000;
    x[4] = -0.50000000000000000000;
    x[5] = -0.37500000000000000000;
    x[6] = -0.25000000000000000000;
    x[7] = -0.12500000000000000000;
    x[8] =  0.00000000000000000000;
    x[9] =  0.12500000000000000000;
    x[10] = 0.25000000000000000000;
    x[11] = 0.37500000000000000000;
    x[12] = 0.50000000000000000000;
    x[13] = 0.62500000000000000000;
    x[14] = 0.75000000000000000000;
    x[15] = 0.87500000000000000000;
    x[16] = 1.00000000000000000000;

    w[0]  =   0.030797894233299012495;
    w[1]  =   0.26128238288028031086;
    w[2]  =  -0.36795289329867605622;
    w[3]  =   1.7037379778090086905;
    w[4]  =  -3.9501480717783930427;
    w[5]  =   8.5525299934402953388;
    w[6]  = -13.934614237197880038;
    w[7]  =  19.180342211078732848;
    w[8]  = -20.951950514333334128;
    w[9] =   19.180342211078732848;
    w[10] = -13.934614237197880038;
    w[11] =   8.5525299934402953388;
    w[12] =  -3.9501480717783930427;
    w[13] =   1.7037379778090086905;
    w[14] =  -0.36795289329867605622;
    w[15] =   0.26128238288028031086;
    w[16] =   0.030797894233299012495;
  }
  else if ( order == 18 )
  {
//
//       55294720874657 / 1883051089920000
//      450185515446285 / 1883051089920000
//    - 542023437008852 / 1883051089920000
//     2428636525764260 / 1883051089920000
//   - 4768916800123440 / 1883051089920000
//     8855416648684984 / 1883051089920000
//  - 10905371859796660 / 1883051089920000
//    10069615750132836 / 1883051089920000
//   - 3759785974054070 / 1883051089920000
//   - 3759785974054070 / 1883051089920000
//    10069615750132836 / 1883051089920000
//  - 10905371859796660 / 1883051089920000
//     8855416648684984 / 1883051089920000
//   - 4768916800123440 / 1883051089920000
//     2428636525764260 / 1883051089920000
//    - 542023437008852 / 1883051089920000
//      450185515446285 / 1883051089920000
//       55294720874657 / 1883051089920000
//
    x[0] = -1.00000000000000000000;
    x[1] = -0.88235294117647058824;
    x[2] = -0.76470588235294117647;
    x[3] = -0.64705882352941176471;
    x[4] = -0.52941176470588235294;
    x[5] = -0.41176470588235294118;
    x[6] = -0.29411764705882352941;
    x[7] = -0.17647058823529411765;
    x[8] = -0.058823529411764705882;
    x[9] =  0.058823529411764705882;
    x[10] = 0.17647058823529411765;
    x[11] = 0.29411764705882352941;
    x[12] = 0.41176470588235294118;
    x[13] = 0.52941176470588235294;
    x[14] = 0.64705882352941176471;
    x[15] = 0.76470588235294117647;
    x[16] = 0.88235294117647058824;
    x[17] = 1.00000000000000000000;

    w[0] =   0.029364429446790078519;
    w[1] =   0.23907238516051669677;
    w[2] =  -0.28784319231183443641;
    w[3] =   1.2897348026109258587;
    w[4] =  -2.5325477495812627261;
    w[5] =   4.7026959045817496499;
    w[6] =  -5.7913308450170443690;
    w[7] =   5.3475000248456540826;
    w[8] =  -1.9966457597354948350;
    w[9] =  -1.9966457597354948350;
    w[10] =  5.3475000248456540826;
    w[11] = -5.7913308450170443690;
    w[12] =  4.7026959045817496499;
    w[13] = -2.5325477495812627261;
    w[14] =  1.2897348026109258587;
    w[15] = -0.28784319231183443641;
    w[16] =  0.23907238516051669677;
    w[17] =  0.029364429446790078519;
  }
  else if ( order == 19 )
  {
//
//       203732352169 / 7604556960000
//      1848730221900 / 7604556960000
//    - 3212744374395 / 7604556960000
//     15529830312096 / 7604556960000
//   - 42368630685840 / 7604556960000
//    103680563465808 / 7604556960000
//  - 198648429867720 / 7604556960000
//    319035784479840 / 7604556960000
//  - 419127951114198 / 7604556960000
//    461327344340680 / 7604556960000
//  - 419127951114198 / 7604556960000
//    319035784479840 / 7604556960000
//  - 198648429867720 / 7604556960000
//    103680563465808 / 7604556960000
//   - 42368630685840 / 7604556960000
//     15529830312096 / 7604556960000
//    - 3212744374395 / 7604556960000
//      1848730221900 / 7604556960000
//       203732352169 / 7604556960000
//
    x[0] = -1.00000000000000000000;
    x[1] = -0.88888888888888888889;
    x[2] = -0.77777777777777777778;
    x[3] = -0.66666666666666666667;
    x[4] = -0.55555555555555555556;
    x[5] = -0.44444444444444444444;
    x[6] = -0.33333333333333333333;
    x[7] = -0.22222222222222222222;
    x[8] = -0.11111111111111111111;
    x[9] =  0.00000000000000000000;
    x[10] = 0.11111111111111111111;
    x[11] = 0.22222222222222222222;
    x[12] = 0.33333333333333333333;
    x[13] = 0.44444444444444444444;
    x[14] = 0.55555555555555555556;
    x[15] = 0.66666666666666666667;
    x[16] = 0.77777777777777777778;
    x[17] = 0.88888888888888888889;
    x[18] = 1.00000000000000000000;

    w[0] =    0.026790824664820447344;
    w[1] =    0.24310820888374278151;
    w[2] =   -0.42247620621346493274;
    w[3] =    2.0421742376029227612;
    w[4] =   -5.5714791681749728126;
    w[5] =   13.634004454324976218;
    w[6] =  -26.122288374274995239;
    w[7] =   41.953237533490708445;
    w[8] =  -55.115367445968607749;
    w[9] =   60.664591871329740161;
    w[10] = -55.115367445968607749;
    w[11] =  41.953237533490708445;
    w[12] = -26.122288374274995239;
    w[13] =  13.634004454324976218;
    w[14] =  -5.5714791681749728126;
    w[15] =   2.0421742376029227612;
    w[16] =  -0.42247620621346493274;
    w[17] =   0.24310820888374278151;
    w[18] =   0.026790824664820447344;
  }
  else if ( order == 20 )
  {
//
//       69028763155644023 / 2688996956405760000
//      603652082270808125 / 2688996956405760000
//    - 926840515700222955 / 2688996956405760000
//     4301581538450500095 / 2688996956405760000
//  - 10343692234243192788 / 2688996956405760000
//    22336420328479961316 / 2688996956405760000
//  - 35331888421114781580 / 2688996956405760000
//    43920768370565135580 / 2688996956405760000
//  - 37088370261379851390 / 2688996956405760000
//    15148337305921759574 / 2688996956405760000
//    15148337305921759574 / 2688996956405760000
//  - 37088370261379851390 / 2688996956405760000
//    43920768370565135580 / 2688996956405760000
//  - 35331888421114781580 / 2688996956405760000
//    22336420328479961316 / 2688996956405760000
//  - 10343692234243192788 / 2688996956405760000
//     4301581538450500095 / 2688996956405760000
//    - 926840515700222955 / 2688996956405760000
//      603652082270808125 / 2688996956405760000
//       69028763155644023 / 2688996956405760000
//
    x[0] =  -1.00000000000000000000;
    x[1] =  -0.89473684210526315789;
    x[2] =  -0.78947368421052631579;
    x[3] =  -0.68421052631578947368;
    x[4] =  -0.57894736842105263158;
    x[5] =  -0.47368421052631578947;
    x[6] =  -0.36842105263157894737;
    x[7] =  -0.26315789473684210526;
    x[8] =  -0.15789473684210526316;
    x[9] =  -0.052631578947368421053;
    x[10] =  0.052631578947368421053;
    x[11] =  0.15789473684210526316;
    x[12] =  0.26315789473684210526;
    x[13] =  0.36842105263157894737;
    x[14] =  0.47368421052631578947;
    x[15] =  0.57894736842105263158;
    x[16] =  0.68421052631578947368;
    x[17] =  0.78947368421052631579;
    x[18] =  0.89473684210526315789;
    x[19] =  1.00000000000000000000;

    w[0] =    0.025670822345560078100;
    w[1] =    0.22448968595251886556;
    w[2] =   -0.34467890099030890987;
    w[3] =    1.5996974366978074270;
    w[4] =   -3.8466730910952978835;
    w[5] =    8.3065993344729824120;
    w[6] =  -13.139430424771119113;
    w[7] =   16.333513604742678295;
    w[8] =  -13.792641220001198577;
    w[9] =    5.6334527526463774045;
    w[10] =   5.6334527526463774045;
    w[11] = -13.792641220001198577;
    w[12] =  16.333513604742678295;
    w[13] = -13.139430424771119113;
    w[14] =   8.3065993344729824120;
    w[15] =  -3.8466730910952978835;
    w[16] =   1.5996974366978074270;
    w[17] =  -0.34467890099030890987;
    w[18] =   0.22448968595251886556;
    w[19] =   0.025670822345560078100;
  }
  else if ( order == 21 )
  {
    x[0] =  -1.00000000000000000000;
    x[1] =  -0.90000000000000000000;
    x[2] =  -0.80000000000000000000;
    x[3] =  -0.70000000000000000000;
    x[4] =  -0.60000000000000000000;
    x[5] =  -0.50000000000000000000;
    x[6] =  -0.40000000000000000000;
    x[7] =  -0.30000000000000000000;
    x[8] =  -0.20000000000000000000;
    x[9] =  -0.10000000000000000000;
    x[10] =  0.00000000000000000000;
    x[11] =  0.10000000000000000000;
    x[12] =  0.20000000000000000000;
    x[13] =  0.30000000000000000000;
    x[14] =  0.40000000000000000000;
    x[15] =  0.50000000000000000000;
    x[16] =  0.60000000000000000000;
    x[17] =  0.70000000000000000000;
    x[18] =  0.80000000000000000000;
    x[19] =  0.90000000000000000000;
    x[20] =  1.00000000000000000000;

    w[0] =     0.023650546498063206389;
    w[1] =     0.22827543528921394997;
    w[2] =    -0.47295674102285392846;
    w[3] =     2.4123737869637513288;
    w[4] =    -7.5420634534306609355;
    w[5] =    20.673596439879602287;
    w[6] =   -45.417631687959024596;
    w[7] =    83.656114844387109207;
    w[8] =  -128.15055898030800930;
    w[9] =   165.59456694494570344;
    w[10] = -180.01073427048578932;
    w[11] =  165.59456694494570344;
    w[12] = -128.15055898030800930;
    w[13] =   83.656114844387109207;
    w[14] =  -45.417631687959024596;
    w[15] =   20.673596439879602287;
    w[16] =   -7.5420634534306609355;
    w[17] =    2.4123737869637513288;
    w[18] =   -0.47295674102285392846;
    w[19] =    0.22827543528921394997;
    w[20] =    0.023650546498063206389;
  }
  else
  {
    cerr << "\n";
    cerr << "NCC_SET - Fatal error!\n";
    cerr << "  Illegal value of ORDER = " << order << "\n";
    cerr << "  Legal values are 1 through 21.\n";
    exit ( 1 );
  }

  return;
}
//****************************************************************************80

double *weights_ls ( int d, double a, double b, int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    WEIGHTS_LS computes weights for a least squares quadrature rule.
//
//  Discussion:
//
//    We suppose that we wish to estimate integrals of functions f(x)
//    over the interval [a,b], given values of the function at N points X,
//    and that we wish to do this in such a way that our estimate is
//    based on the least squares polynomial approximant p(x) of degree D.
//
//    The resulting quadrature rule will only be exact if N = D + 1
//    and f(x) is a polynomial of degree D or less.
//
//    This function is based in part on ideas of Mac Hyman, of Tulane
//    University.
//
//  Method:
//
//    The approximant p(x) to f(x) has coefficients C(1:D+1).
//    The values of p(x) at the abscissas are found by V * C = P.
//    The values of f(x) at the abscissas are in the vector F.
//    We want to minimize ||P-F|| = ||V * C - F||.
//    We set up the D+1 x D+1 system V' * V * C = V' * F.
//
//    Now, for quadrature, we have Q * C = W * F,
//    so formally Q * inv ( V' * V ) * V' = W.
//
//    Hence, to solve for the weights W, we solve two Vandermonde systems:
//
//    1) Solve   Q' = V' * S  for S, an N vector.
//    2) Solve   S  = V  * R  for R, a D+1 vector.
//    3) Compute W  = R' * V' for W, an N vector.
//
//    so that, by construction (and writing inv() for matrices which
//    actually don't have inverses):
//
//      W  = R' * V'
//      W' = V  * R
//      W' = V  * inv ( V )      * S
//      W' = V  * inv ( V )      * inv ( V' ) * Q'
//      W  = Q  * inv ( V )      * inv ( V' ) * V'
//      W  = Q  * inv ( V' * V )              * V'
//
//    Thus, knowing the values Q and the abscissas X, we can construct
//    V and solve for W, and the value of W depends (as it should) only
//    on N and X, but not on f(x).
//
//    Having W, we can estimate the integral of any f(x)
//    if we have its values F(1:n) at the points X(1:n), by the formula:
//
//      I(f) \approx Q(f) = sum ( 1 <= i <= n ) W(i) * F(i)
//
//    A simple test is to use N points associated with a known quadrature
//    rule, and specify D = N-1.  Assuming the rule is exact for polynomials
//    of degree D, this procedure should determine the same weights as 
//    those used for the given quadrature rule.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 April 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int D, the desired degree of the polynomial 
//    approximant.  0 <= D.
//
//    Input, double A, B, the left and right endpoints of 
//    the interval.
//
//    Input, int N, the number of data points or abscissas.
//
//    Input, double X[N], the data points.
//
//    Output, double WEIGHTS_LS[N], the quadrature weights.
//
{
  double ai;
  double bi;
  int i;
  int j;
  double *q;
  double *r;
  double *s;
  double *v;
  double *vt;
  double *w;
//
//  Integrate the basis functions x^0, x^1, ..., x^d over [a,b].
//
  q = new double[d+1];

  bi = b;
  ai = a;
  for ( i = 0; i < d + 1; i++ )
  {
    q[i] = ( bi - ai ) / ( double ) ( i + 1 );
    ai = ai * a;
    bi = bi * b;
  }
//
//  Form the N by D+1 Vandermonde matrix V.
//
  v = new double[n*(d+1)];
  for ( i = 0; i < n; i++ )
  {
    v[i+0*n] = 1.0;
    for ( j = 1; j < d + 1; j++ )
    {
      v[i+j*n] = v[i+(j-1)*n] * x[i];
    }
  }
//
//  Solve the D+1 by N system V' * S = Q for vector S of length N.
//
  vt = r8mat_transpose_new ( n, d + 1, v );
  s = qr_solve ( d + 1, n, vt, q );
//
//  Solve the N by D+1 system V * R = S for vector R, of length D+1.
//
  r = qr_solve ( n, d + 1, v, s );
//
//  Compute W = R' * V';
//
  w = r8mat_mv_new ( n, d + 1, v, r );
//
//  Free memory.
//
  delete [] q;
  delete [] r;
  delete [] s;
  delete [] v;
  delete [] vt;

  return w;
}
