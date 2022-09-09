#include <Rcpp.h>

using namespace Rcpp;

//' @name rbind_Rcpp
//' @title rbind_rcpp
//' Used to bind or combine the multiple group of rows together.
//'
//' @param a,b A NumericMatrix that takes a numerical vector value as a parameter, and the elements in it are double.
//' @examples
//' set.seed(42)
//' a <- matrix(rnorm(1e7), 1e3)
//' b <- matrix(runif(1e7), 1e3)
//' identical(mmult1(a, b), mmult1(a, b))
//' @export
// [[Rcpp::export]]

NumericMatrix mmult1(NumericMatrix a, NumericMatrix b) {
  int arow = a.nrow();
  int brow = b.nrow();
  NumericMatrix out = no_init_matrix(a.ncol(), arow + brow);
  for (int j = 0; j < arow + brow; j++) {
    if (j < arow) {
      out(_, j) = a(_, j);
    } else {
      out(_, j) = b(_, j - arow);
    }
  }
  return out;
}
