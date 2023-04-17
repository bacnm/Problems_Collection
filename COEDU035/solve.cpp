#include<iostream>

using namespace std;


enum covid_status{
	NONE,
	F0,
	F1,
	F2
};

int main(){
	freopen("input.txt", "r", stdin);


	int matrix[100][100] = {NONE};
	
	int res[100] = {NONE};

	int T, tc = 1, N, M, f0_indx, f1, f2;


	cin >> T;

	while ( tc <= T)
	{

		cin >> N >> M;


		f1 = 0, f2 = 0;
		for (int i = 0; i < 100; i++)
		{
			res[i] = NONE;
			for (int j = 0; j < 100; j++)
			{
				matrix[i][j] = NONE;
			}
			
		}
		
		for( int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				cin >> matrix[i][j];
			}

		for (int i = 0; i < M; i++)
		{
			cin>>f0_indx;
			res[f0_indx-1] = F0;
		}
		

		for( int i = 0; i < N; i++)
		{
			if(res[i] == F0)
			{
				for (int j = 0; j < N; j++)
				{
					if( ( matrix[i][j] == 1 ) && ( res[j] != F0 ) ) res[j] = F1; // có thể bỏ qua đk i != j bởi đk res[j] != F0 đã thỏa mãn
				}
				
			}
		}

		for (int i = 0; i < N; i++)
		{
			if( res[i] == F1 )
			{
				for (int  j = 0; j < N; j++)
				{
					if ( matrix[i][j] == 1 && res[j] == NONE ) // có thể bỏ qua đk i != j bởi đk res[j] == F1 đã thỏa mãn
					{
						res[j] = F2;
						//break;
					}
				}
				
				
			}
		}
		

		for (int i = 0; i < N; i++)
		{
			switch (res[i])
			{
			case F1:
				f1++;
				break;
			case F2:
				f2++;
				break;
			}
		}

		cout<<'#'<<tc<<' '<<f1<<' '<<f2<<endl;
		tc++;

		
	}

	return 0;
}
