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
            }else if(ln==2){
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
       
        if(ln==1){
             a = exp(a);
             return a*exp(b*x_target);
        }else if(ln==2){
             a = exp(a);
             return a*pow(x_target,b);
        }
        return ((a+b*x_target));
    }

    double transcen_regress_power(double x_target){
        cal_sum(1);
        return linear_regress(x_target,1);
    }

    double transcen_regress_exp(double x_target){
        cal_sum(2);
        return linear_regress(x_target,2);
    } 
};