#include<bits/stdc++.h>
using namespace std;

class regression {
    double tx,ty,tx2,txy;
    vector<double> x,y;
public:
    regression(){}
    void cal_sum(int ln=0){
        tx=ty=tx2=txy=0;
        for(long long i=0;i<min(x.size(),y.size());i++){
            if(ln){
                x[i]=log(x[i]);
                y[i]=log(y[i]);
            }
            tx+=x[i];
            ty+=y[i];
            tx2+=x[i]*x[i];
            txy+=x[i]*y[i];
        }
    }
    double linear_regress(double x_target,int ln=0) {
        cal_sum();
        long long n = min(x.size(),y.size());
        if((n*tx2 - (tx)*(tx))<1e-9){
            cout<<"Division by zero in linear regression"<<endl;
            return -1;
        }
        double b = (n*txy - tx*ty)/(n*tx2 - (tx)*(tx));
        double a = (ty-b*tx)/n;
        if(ln) ((log(a)+b*log(x_target)));
        return ((a+b*x_target));
    }

    double transcen_regress_power(double x_target){

    }
};