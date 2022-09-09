#include <Rcpp.h>

using namespace Rcpp;

//' @name cbind_Rcpp
//' @title cbind_rcpp
//' Take a sequence of vector, matrix or data-frame arguments and
//' combine by columns or rows, respectively.
//'
//' @param a,b A NumericMatrix that takes a numerical vector value as a parameter, and the elements in it are double.
//' @examples
//' a <- matrix(rnorm(1e7), 1e3)
//' b <- matrix(runif(1e7), 1e3)
//' identical(mmult1(a, b), mmult1(a, b))
//' @export
// [[Rcpp::export]]

NumericMatrix mmult1(NumericMatrix a, NumericMatrix b) {
  int acoln = a.ncol();
  int bcoln = b.ncol();
  NumericMatrix out = no_init_matrix(a.nrow(), acoln + bcoln);
  for (int j = 0; j < acoln + bcoln; j++) {
    if (j < acoln) {
      out(_, j) = a(_, j);
    } else {
      out(_, j) = b(_, j - acoln);
    }
  }
  return out;
}
