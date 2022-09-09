#include <Rcpp.h>

using namespace Rcpp;

//' @name wich_max_rcpp
//' @title wich_max_rcpp
//' Find the maximum values of a data frame or array.
//'
//' @param A NumericMatrix that takes a numerical vector value as a parameter, and the elements in it are double.
//' @examples
//' set.seed(42)
//' a <- matrix(rnorm(1e7), 1e3)
//' b <- matrix(runif(1e7), 1e3)
//'
//' @export
// [[Rcpp::export]]

DataFrame Wichmax_rcpp(NumericMatrix A){
  int arow  = A.nrow();
  int acol  = A.ncol();
  int index = 0;
  double max = A(0,0);

  NumericVector indMaxarows;
  NumericVector indMaxacols;

  for(int i=0; i < arow; i++){
    for(int j=0; j < acol; j++){
      if(A(i,j) > max){
        max = matrix(i,j);
      }
    }
  }
  for(int i=0; i < arow; i++){
    for(int i=0; i < acol; i++){
      if(A(i,j) >= max){
        indMaxarows.push_back(i+1);
        indMaxacols.push_back(i+1);
      }
    }
  }
  DataFrame MaxV = DataFrame::create(Named("Row")=na_omit(indMaxarows),Named("Cols")=na_omit(indMaxacols));

  return MaxV
}

