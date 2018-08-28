#include <iostream>
#include <vector>

using namespace std;

void mostrarVector(vector<int>&);
vector<int> PD(int, int, vector<int>&, vector<int>&, int);

int main(){
	int cantCases = 0;
	int ferryLarge = 0;
	cin >> cantCases;
	
	while(cantCases > 0){
		cin >> ferryLarge;
		vector<int> cars;
		vector<int> res;
		int aux = 1;
		cin >> aux;
		
		while(aux > 0){
			cars.push_back(aux);
			cin >> aux;
		}

		res = PD(ferryLarge, ferryLarge, cars, res, 0);
		cout << endl;
		cantCases --;
	}





	return 0;
}



vector<int> PD(int ferryD, int ferryI, vector<int>& cars, vector<int>& res, int i){
	if(cars[i] > ferryD && cars[i] > ferryI){
		return res;
	}

	


	return res;
}



void mostrarVector(vector<int>& x){
	int i = 0;
	while(i < x.size()){
		cout << x[i];
		i++;
	}
}