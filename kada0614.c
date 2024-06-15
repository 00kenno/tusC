#include<stdio.c>
void main(void){
  int i, n;
  float tn[21], tnpl[21], c;

  printf("Input c \n");
  scanf("%f",&c);
  tn[20] = 2000.0;

  for(i = 0; i <= 19; i++){
    tn[i] = 300.0;
  }
  
  for(n = 0; n <=2000; n++){
    
    for(i = 1; i <= 19; i++){
      tnpl[i] = tn[i] + c * (tn[i+1] - 2.0*tn[i] + tn[i-1]);
    }
    
    tnpl[0] = 300.0;
    tnpl[20] = 2000.0;
    
    for(i = 0; i <= 20; i++){
      tn[i] = tnpl[i];
    }
    
  }

  for(i = 0; i <= 20; i++){
    printf("i = %d  T = %f \n", i, tn[i]);
  }
  
}
