#include <stdio.h>
#include <math.h>

void(){
double distance(double x1[4], double x2[4]){
  int c = 0;
  double d = 0;
  for(; c < 4; c++) d += (x1[c]-x2[c]) * (x1[c]-x2[c]);
  return sqrt(d);
}

}
int main(){
    int i, j, k, ntrain, ntest, y[ntrain], I[ntrain];
    double xtrain[ntrain][4], dp[4], media[4], s, var, normtrain[ntrain][4], xtest[ntest][4], normtest[ntest][4], w[ntrain];
    scanf("%d %d %d", &k, &ntrain, &ntest);

    for(i = 0; i < ntrain; i++){
        for(j = 0; j < 4; j++){
            scanf("%d", xtrain[i][j]);
        }
    }

    for(j = 0; j < 4; j++){
        s = 0;
        var = 0;
        for(i = 0; i < ntrain; i++){
            s += xtrain[i][j];
            media[j] = s/ntrain;
            var += pow((media - xtrain[i][j]), 2);
            dp[j] = sqrt(var/ntrain);
        }
    }

    for(i = 0; i < ntrain; i++){
        for(j = 0; j < 4; j++){
            normtrain[i][j] = (xtrain[i][j] - media[j])/dp[j]
        }
    }

    for(i = 0; i < ntrain; i++){
        scanf("%d", &y[i]);
    }

    for(i = 0; i < ntest; i++){
        for(j = 0; j < 4; j++){
            scanf("%d", xtest[i][j]);
            normtest[i][j] = (xtest[i][j] - media[j]/dp[j]);
        }
    }

    for(i = 0; i < ntrain; i++){
        I[i] = i; 
    }

    for(i = 0; i < ntrain; i++){



    }



    return 0;
}
