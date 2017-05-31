#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <map>
#include <math.h>
#include "knot.hpp"
#include <assert.h>

using namespace std;


double pav( int N, int sign, double *td, double *xd, double *xr );
// regression by an isotonic function

void pavKnots( vector< Knot > &knots, int *g, int *f, int *b, double *xd, bool inform );
// regression by an isotonic series of "knots" (needed by lpav)

double lpav( int N, int sign, double L, double *td, double *xd, double *xr, bool inform );
// regression by an isotonic function with steepness bound

double lpmrPartition( int N, int k, double dMin, double dMax, bool considerSteepness, double *td, double *xd, int *T );
// optimum partition for piecewise monotonic regression with (optional) steepness bounds

double lpmr( int N, int k, int mode, double dMin, double dMax, bool considerSteepness, double *td, double *xd, double *xr );
// piecewise monotonic regression with (optional) steepness bounds