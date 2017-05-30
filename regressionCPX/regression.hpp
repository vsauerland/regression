#include <ilcplex/ilocplex.h>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include "knot.hpp"

using namespace std;

/****************************** WITHOUT CPLEX ********************************/

double normaldistribution( double m, double s );

double pav( int N, int sign, double *td, double *xd, double *xr );
// regression by an isotonic function

void pavKnots( vector< Knot > &knots, int *g, int *f, int *b, double *xd, bool inform );
// regression by an isotonic series of "knots" (needed by lpav)

double lpav( int N, int sign, double L, double *td, double *xd, double *xr, bool inform );
// regression by an isotonic function with steepness bound

/******************************* WITH CPLEX **********************************/

double isoReg( int N, int sign, double *td, double *xd, double *xr );
// regression by an isotonic function

double slopeReg( int N1, int N2, double dMin, double dMax, double *td, double *xd, double *xr );
// regression by a function that has limited slope (generalization of isoReg)

double minMaxReg( int N, int kMinA, int kMinB, int kMaxA, int kMaxB, int step, double dMin, double dMax, double T, double *td, double *xd, double *xr );
// regression by a (periodic) function that has limited slope and exactly one
// local minimum and exactly one local maximum (per period)

double lpmrPartition( int N, int k, double dMin, double dMax, bool considerSteepness, double *td, double *xd, int *T );
// optimum partition for piecewise monotonic regression with (optional) steepness bounds

double lpmr( int N, int k, int mode, double dMin, double dMax, bool considerSteepness, double *td, double *xd, double *xr );
// piecewise monotonic regression with (optional) steepness bounds

double lpmrIQP( int N, int nMin, int nMax, int sign, double dMin, double dMax, double T, double *td, double *xd, double *xr );
// piecewise monotonic regression as IQP