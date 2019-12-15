#include <stdio.h>


int fact_calc(int n);
int fib_calc(int n);

int main(void){

  int n = 10;
  printf("%d\n", fact_calc(n));
  printf("%d\n", fib_calc(n));
;

  return 0;
}


int fact_calc(int n){
  //printf("%d\n", n);
  if(n == 0){
    return 1;
  }else{
    return n * fact_calc(n-1);
  }
}

int fib_calc(int n){
  //printf("%d\n", n);
  if( n <= 0){
    return 0;
  }else if(n== 1){
    return 1;
  }else{
    return fib_calc(n-1) + fib_calc(n-2);
  }
}
