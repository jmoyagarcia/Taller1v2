#include <Rcpp.h>

using namespace Rcpp;

//' @name mmatrix_rcpp
//' @title mmatrix_rcpp
//' Multiplies two matrices, if they are conformable
//'
//' @param m1,m2 A NumericMatrix that takes a numerical vector value as a parameter, and the elements in it are double.
//' @examples
//' set.seed(42)
//' A <- matrix(c(1:6),ncol=2)
//' B <- matrix(c(0:7),nrow=2)
//' mmult(A,B)
//' @export
// [[Rcpp::export]]

NumericMatrix mmult(const NumericMatrix& m1, const NumericMatrix& m2){
  if (m1.ncol() != m2.nrow()) stop ("Dimiensiones incompatibles de las matrices");
  NumericMatrix out(m1.nrow(),m2.ncol());
  NumericVector rm1, cm2;
  for (size_t i = 0; i < m1.nrow(); ++i) {
    rm1 = m1(i,_);
    for (size_t j = 0; j < m2.ncol(); ++j) {
      cm2 = m2(_,j);
      out(i,j) = std::inner_product(rm1.begin(), rm1.end(), cm2.begin(), 0.);
    }
  }
  return out;
}
