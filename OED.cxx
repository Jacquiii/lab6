#include <iostream>

using namespace std;

  void EulerFrank(double* y, const int N, const double dt, const double lambda);
  void EulerBecky(double* y, const int N, const double dt, const double lambda);
  void EulerMegatron(double* y, const int N, const double dt, const double lambda);
 
int main(){
  
  const int N=5000;
  const double dt=1.0/1000;
  const double lambda=-0.5;
  double y[N];
  y[0]=1;
  
  //EulerFrank(y, N, dt, lambda);
  //EulerBecky(y,N,dt,lambda);
  EulerMegatron(y,N,dt,lambda);
  
  for(int i=0; i<N; i++){
  cout<< i*dt << '\t' << y[i] <<endl;
  }
}
  
  void EulerFrank(double* y, const int N, const double dt, const double lambda){
       for(int i=1; i<N; i++){ 
	 y[i]=y[i-1] + y[i-1]*lambda*dt;
	 //cout << i << endl;	 
      }
  }
  
  void EulerBecky(double* y, const int N, const double dt, const double lambda){
       for(int i=1; i<N; i++){ 
	 y[i]=y[i-1]/(1-lambda*dt);
	 //cout << i << endl;	 
      }
  }
  
    void EulerMegatron(double* y, const int N, const double dt, const double lambda){
       for(int i=1; i<N; i++){ 
	 y[i]=(y[i-1]/(1-lambda*dt)+y[i-1] + y[i-1]*lambda*dt)/2;
	 //cout << i << endl;	 
      }
  }