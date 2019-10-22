#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;
 
// float dec_3(double n){
//     int t = (n*1000);
//     float r = (t/1000.0);
//     return r;
// }
 
double distance(int x1, int y1, int x2, int y2);
 
 
int main(){
	
	int t;
	cin>>t;
	while(t--){
	    vector<int> a[200];
		int size, n;
		double dis=0, t_dis=0, min_dis=INT_MAX;
		int x1,x2,y1,y2;
		cin>>size;
		for(int i=0; i<size; i++){
			cin>>n;
			a[i].push_back(n);
			cin>>n;
			a[i].push_back(n);
			
		}
 
		for(int i=0; i<size; i++){
			
			for(int j=i+1; j<size; j++){
				t_dis=distance(a[i][0], a[i][1], a[j][0], a[j][1]);
			//	cout<<"test-> ("<<a[i][0]<<","<<a[i][1]<<") ("<<a[j][0]<<","<<a[j][1]<<") "<<t_dis<<endl;
				if(t_dis<min_dis){
					x1=a[i][0];
					y1=a[i][1];
					x2=a[j][0];
					y2=a[j][1];
					min_dis=t_dis;
				}
			}
 
		}
 
        if(x1>x2)
            cout<<"("<<x2<<","<<y2<<") ("<<x1<<","<<y1<<") ";
        else
		cout<<"("<<x1<<","<<y1<<") ("<<x2<<","<<y2<<") ";//<<(float)dec_3(min_dis)<<endl;
		cout.precision(3);
        	cout << fixed <<min_dis<< endl;
	}
 
	return 0;
}
 
 
double distance(int x1, int y1, int x2, int y2){
    return sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) );
}
