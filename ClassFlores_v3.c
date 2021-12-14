#include <stdio.h>
#include <math.h>

double distance(double x1[COLS], double x2[COLS]){
  int c=0;
  double d=0;
  for(; c < COLS; c++) d += (x1[c]-x2[c]) * (x1[c]-x2[c]);
  return sqrt(d);
}

int main(){
    int i, j, k, ntrain, ntest, l;
    scanf("%d %d %d", &k, &ntrain, &ntest);
    int y[ntrain], I[ntrain], contador[3];
    double xtrain[ntrain][4], dp[4], media[4], s, var, normtrain[ntrain][4], xtest[ntest][4], normtest[ntest][4], w[ntrain];
}