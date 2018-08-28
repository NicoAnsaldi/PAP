#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

void mostrarVector(vector<int>&);
void PD(int, vector<int>&, vector<int>&);
int kp(int, int, vector<int>&, vector<int>&, vector< vector<int> >&);
int sumaLosQueQuedan(vector<int>, vector<int>&, int);

int main(){
	int cantCases = 0;
	int ferryLarge = 0;
	cin >> cantCases;
	
	while(cantCases > 0){
		cin >> ferryLarge;
		ferryLarge = ferryLarge * 100;
		vector<int> cars;
		vector<int> res;
		int aux = 1;
		cin >> aux;
		
		while(aux > 0){
			cars.push_back(aux);
			cin >> aux;
		}

		PD(ferryLarge, cars, res);

		cout << cars.size() << endl;
		int i = 0;
		while(i < cars.size()){
			if(i == res[0]){
				cout << "port" << endl;
				res.erase(res.begin());
			}else{
				cout << "starboard" << endl;
			}
			i++;
		}

		cout << endl;
		cantCases --;
	}

	return 0;
}



void PD(int ferry, vector<int>& cars, vector<int>& res){
	vector<int> loadCars;	
	while(cars.size() > 0){
		vector< vector<int> > matriz (cars.size(),vector<int>(ferry,-1));
		kp(cars.size()-1, ferry, cars, loadCars, matriz);
		if(sumaLosQueQuedan(loadCars, cars, ferry) <= ferry){
			break;
		}else{
			loadCars.clear();
			cars.pop_back();
		}
	}

	int i = 0;
	while(i < loadCars.size()){
		res.push_back(loadCars[i]);
		i++;
	}
}


int kp(int i, int ferryL, vector<int>& cars, vector<int>& loadCars, vector< vector<int> >& matriz){

	if(i <= 0){
		return 0;
	}
	
	if(cars[i] > ferryL){
		kp(i-1, ferryL, cars, loadCars, matriz);
	}else{
		int a = kp(i-1, ferryL, cars, loadCars, matriz);
		int b = kp(i-1, (ferryL-cars[i]), cars, loadCars, matriz)+1;
		if(b>=a){
			loadCars.push_back(i);
		}
		return max(a,b);
	}

	return -1;
}

void mostrarVector(vector<int>& x){
	int i = 0;
	while(i < x.size()){
		cout << x[i];
		i++;
	}
}

int sumaLosQueQuedan(vector<int> loadCars, vector<int>& cars, int ferry){
	int i = 0;
	int suma=0;

	while(i < cars.size()){
		if(i == loadCars[0]){
			loadCars.erase(loadCars.begin());
		}else{
			suma = suma + cars[i];
		}
		i++;
	}
	return suma;
}

