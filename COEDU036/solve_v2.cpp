#include<iostream>

using namespace std;

int dx[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dy[8] = {-1, 1, 2,  2, 1, -1, -2, -2};


int main(){
	freopen("input.txt", "r", stdin);
	int a[8][8];
	int b[8][8];
	int c[8][8];
	int d[2][64];

	int T;
	cin >> T;
	for(int t= 1; t <= T; t++){
		int n;
		cin >> n;

		int x, y;
		cin >> x>> y;
		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++){
				a[i][j] = 0;
				b[i][j] = 0;
				c[i][j] = 0;
			}
		}


		a[x-1][y-1] = 2;

		for (int i = 0; i < n; i++){
			for (int j = 0; j < 2; j++){
				cin >> d[j][i];
			}
		}

		for(int i= 0 ; i < n; i++){
			b[d[0][i]-1][d[1][i]-1] = 1;
		}

		int tong = 0;

		for(int j = 0; j < 8; j++){
			int x0, y0;
			x0 = (x-1) + dx[j];
			y0 = (y-1) + dy[j];

			int dem;

			if ( x0 >= 0 && x0 < 8 && y0 >= 0 && y0 < 8){
				int x1 ;
				int y1 ;
				dem = 0;
				for(int k=0; k < 8; k++){

					x1 = x0 + dx[k];
					y1 = y0 + dy[k];
					if ( x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8){
						if(b[x1][y1] == 1){
							dem ++;
						}
					}

				}
				if(dem >= 2){
					tong += 1;
				}



			}
		}

		for(int j = 0; j < 8; j++){
			int x0, y0;
			x0 = x-1 + dx[j];
			y0 = y-1 + dy[j];

			if ( x0 >= 0 && x0 < 8 && y0 >= 0 && y0 < 8){
				int x1 ;
				int y1 ;
				for(int k=0; k < 8; k++){
					x1 = x0 + dx[k];
					y1 = y0 + dy[k];
					if ( x1 >= 0 && x1 < 8 && y1 >= 0 && y1 < 8){
						int ans =0;
						int x2, y2;
						for(int z=0; z < 8; z++){
							x2 = x1 + dx[z];
							y2 = y1 + dy[z];
							if ( x2 >= 0 && x2 < 8 && y2 >= 0 && y2 < 8){
								if(b[x2][y2] == 1){
									ans ++;
								}
							}

						}
						
						if(ans >= 2 && c[x1][y1] != 3){
							c[x1][y1] = 3;
							tong += 1;
						}
					}

				}
			}
		}
		///////

		cout << "#"<< t << " "<< tong << endl; 
	}

	return 0;
}
