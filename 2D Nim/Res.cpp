#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int width = 0;
int height = 0;
int pieces = 0;

void mostrarMatriz(vector< vector< pair<int,int> > >& matriz);
int DFS(vector< vector< pair<int,int> > >& grid, int i, int j);
void vectoresIguales(vector<int>& v1, vector<int>& v2);
void mostrarVector(vector<int>& v);

int main(){
	int cases;
	cin >> cases;
	
	int i = 0;
	while(i < cases){
		cin >> width;
		cin >> height;
		cin >> pieces;

		vector< vector< pair<int,int> > > grid1(width, vector< pair<int,int> >(height,pair<int,int>(0,0)));
		for(int j = 0; j < pieces; j++){
			int x = 0;
			int y = 0;
			cin >> x >> y;
			grid1[x][y].first = 1;
		}

		//mostrarMatriz(grid1);
		vector< vector< pair<int,int> > > grid2 (width, vector< pair<int,int> >(height,pair<int,int>(0,0)));
		for(int j = 0; j < pieces; j++){
			int x = 0;
			int y = 0;
			cin >> x >> y;
			grid2[x][y].first = 1;
		}
		//mostrarMatriz(grid2);
		vector<int> clusters1;
		for(int x = 0; x < width; x++){
			for(int y = 0; y < height; y++){
				if(grid1[x][y].first == 1 && grid1[x][y].second == 0){
					grid1[x][y].second == 1;
					int res = DFS(grid1, x, y)+1;
					clusters1.push_back(res);
				}
			}
		}
		
		vector<int> clusters2;
		for(int x = 0; x < width; x++){
			for(int y = 0; y < height; y++){
				if(grid2[x][y].first == 1 && grid2[x][y].second == 0){
					grid2[x][y].second == 1;
					int res = DFS(grid2, x, y)+1;
					clusters2.push_back(res);
				}
			}
		}
		
		vectoresIguales(clusters1, clusters2);
		i++;
		if(i < cases){
			cout << endl;
		}
	}

	return 0;
}

int DFS(vector< vector< pair<int,int> > >& grid, int i, int j){
	if(i == height && j == width){
		return 0;
	}

	int left = 0;
	int right = 0;
	int up = 0;
	int down = 0;
	
	if(i < width-1 && grid[i+1][j].first == 1 && grid[i+1][j].second == 0){
		grid[i+1][j].second = 1;
		down = DFS(grid, i+1, j)+1;
	}
	
	if(j < height-1 && grid[i][j+1].first == 1 && grid[i][j+1].second == 0 ){
		grid[i][j+1].second = 1;
		right = DFS(grid, i, j+1)+1;
	}
	
	if(j > 0 && grid[i][j-1].first == 1 && grid[i][j-1].second == 0){
		grid[i][j-1].second = 1;
		left = DFS(grid, i, j-1)+1;
	}
	
	if(i > 0 && grid[i-1][j].first == 1 && grid[i-1][j].second == 0){
		grid[i-1][j].second = 1;
		up = DFS(grid, i-1, j)+1;
	}

	return (left+right+up+down);		
}

void vectoresIguales(vector<int>& v1, vector<int>& v2){
	for(int i = 0; i < v1.size(); i++){
		int elementoABuscar = v1[i];
		int j = 0;
		bool flag = true;

		while(j < v2.size()){
			if(v2[j] == elementoABuscar){
				v2.erase(v2.begin()+j);
				flag = false;
				break;
			}
			j++;
		}
		
		if(flag){
			cout << "NO";
			return;
		}

	}
	cout << "YES";
}

void mostrarMatriz(vector< vector< pair<int,int> > >& matriz){

	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			cout << "("<< matriz[i][j].first << ", " << matriz[i][j].second << ") ";
		}
		cout << endl;
	}
	cout << endl << endl;
}

void mostrarVector(vector<int>& v){
	for(int i = 0; i < v.size(); i++){
		cout << v[i];
	}
	cout << endl;
}