#include<stdio.h>
void main(){
  int i, n;
  float un[21], 
        unpl[21], 
        u, //ディスク表面の回転速度
        rho, tau, nu, //定数
        c, //= d^2u/dy^2
        dy
        ;

  u = 700 * 0.02;
  nu = 0.00001;
  rho = 1.2;
  dy = 1 / 20 / 1000;//mm->m
  
  printf("Input c \n");
  scanf("%f",&c);
  printf("\n");
  
  un[20] = u;

  for(i = 0; i <= 19; i++){
    un[i] = 0.0;
  }

  for(n = 0; n <=20000; n++){//n = 20000*dt　まで繰り返す

    for(i = 1; i <= 19; i++){//unpl[1~19]を計算
      unpl[i] = un[i] + c * nu * (un[i+1] - 2.0*un[i] + un[i-1]);
    }

    unpl[0] = 0.0;
    unpl[20] = u;

    for(i = 0; i <= 20; i++){
      un[i] = unpl[i];
    }
    
  }

  for(i = 0; i <= 20; i++){//un[0~20]を表示
    printf("i = %d  u = %f \n", i, un[i]);
  }

  tau = rho * nu * (un[1] - un[0]) / dy;

  printf("\n");
  printf("****************\n");
  printf("tau = %f\n", tau);
  printf("****************\n");
  printf("\n");

}
