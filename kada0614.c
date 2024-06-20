#include<stdio.h>
void main(){
  int i, n;
  float un[21], 
        unp1[21], 
        u, //ディスク表面の回転速度
        rho, tau, nu, //定数
        dt, 
        dy
        ;

  u = 700 * 0.02;
  nu = 0.00001;
  rho = 1.2;
  dy = 0.001 / 20;//mm->m

  printf("u=%f\nnu=%f\nrho=%f\ndy=%f\n",u,nu,rho,dy);
  
  printf("Input dt \n");
  scanf("%f",&dt);
  printf("\n");
  
  un[20] = u;

  for(i = 0; i <= 19; i++){
    un[i] = 0.0;
  }

  for(n = 0; n <=20000; n++){//n = 20000*dt　まで繰り返す

    for(i = 1; i <= 19; i++){//unpl[1~19]を計算
      unp1[i] = un[i] + nu * dt * (un[i+1] - 2.0*un[i] + un[i-1]) / dy / dy;
    }

    unp1[0] = 0.0;
    unp1[20] = u;

    for(i = 0; i <= 20; i++){
      un[i] = unp1[i];
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
