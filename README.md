This repos is still under construction
======================================

The package `regression` provides C++ implementations of non-parameteric
univariate regression methods by [BBBB72], [DP91], and [YW09]. These methods
are considered in [SLL+17] to assess biogeochemical ocean models.


Contents
--------

* `Makefile`:
  On a LINUX platform with GNU g++ compiler, you can generate the executable
  `isoReg` by typing `make`.

* `isoReg.cpp`:
  The test program reads observational data (uni-variate time series) from
  a provided file and applies some regression method implemented in
  `regression.cpp` and writes the obtained regression time series to output
  file `regression_2columns.dat`.
  The provided input file must be a text-file. Each line must consist of two
  real numbers (2 columns): a time value and an associated measurement value.
  The first column (the time values) must be given in increasing order.
  The output file has the same format as the input file.

* `regression.cpp/hpp`:
  Implements QP free regression methods that are considered by [SLL+17]
  for the assessment of biogeochemical ocean models

* `knot.cpp/hpp`:
  An auxiliary structure introduced in [YW09] and used to calculate
  "isotonic regression under Lipschitz constraint"

* `sineLikeNoise_0.2_200.txt`:
  Data file with 200 samples of the function sin(t)+0.3*sin(t)+Normal(0,0.2),
  serving as test observational data


Usage
-----

After having generated the executable `isoReg` (by typing `make`) you can type,
e.g., `./isoReg fakeSine.dat` to calculate some non-parametric regression
time-series.
To select a non-parametric method, simply comment in/out the corresponding line
in `isoReg.cpp` (and type `make`, again).


Notes
-----

The `regression` package requires no further software to be installed.

Implementations of additional non-parametric regression algorithms considered
by [SLL+17] and some parametric example regression methods are provided with
the package `regressionCPX`. We provide the sub-package `regression` since
the additonal non-parametric regression algorithms are based on problem
formulations in terms of quadratic programs (QPs) and require the CPLEX solver
to be installed on your system. The parametric example regression methods
further require the EIGEN linear algebra package to be copied to your system.


References
----------

[BBBB72] Barlow, R. E., Bartholomew, D. J., Bremmer, J. M., Brunk, H. D.
         *Statistical Inference under order restrictions: The theory and
         applications of isotonic regression.* John Wiley & Sons, 1972

[DP91]   I. C. Demetriou. M. J. D. Powell.
         *Least Squares Smoothing of Univariate Data to achieve Piecewise
         Monotonicity.*
         IMA Journal of Numerical Analysis 11:411-432 (1991)
         doi: 10.1093/imanum/11.3.411

[YW09]   Yeganova, L., Wilbur, W. J.
         *Isotonic Regression under Lipschitz Constraint.*
         J. Optim. Theory Allp. 141:429-443 (2009)
         doi: 10.1007/s10957-008-9477-0

[SLL+17] Sauerland, V., Loeptien, U., Leonhard, C., Oschlies, A., Srivastav, A.
         *Error assessment of biogeochemical models by lower bound methods.*
         Geoscientific Model Development Discussions (2017)
