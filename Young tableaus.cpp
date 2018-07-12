#include<iostream>
#include <sstream>
#include<fstream>
#include <string>

using namespace std;

int main(){
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");
	int table_num, method;
	string s;
	fin >> table_num;
	for (int a = 0; a < table_num; a++){
		int m = 1, n = 1, num, arr[100][100] = { 0 }, insert_num = 0, insert_data[10];
		fin >> method;
		getline(fin, s);

		if (method == 1){
			getline(fin, s);
			istringstream ins(s);
			while (ins >> num){
				insert_data[insert_num] = num;
				insert_num++;
			}
			while (true){
				getline(fin, s);
				if (s == "\0")
					break;
				istringstream iss(s);
				int p = 1;
				while (iss >> num){
					arr[n][p] = num;
					p++;
					if (p > m)
						m = p;
				}
				n++;
			}
			for (int i = 1; i < n + 1; i++){
				for (int j = 1; j < m + 1; j++){
					if (arr[i][j] == 0)
						arr[i][j] = 99999;
				}
			}
			for (int i = 0; i < n; i++){
				arr[i][0] == 0;
			}
			for (int j = 0; j < m; j++){
				arr[0][j] == 0;
			}
			for (int x = 0; x < insert_num; x++){
				int i_now = 0, j_now = 0;
				for (int i = 0; i < n; i++){
					for (int j = 0; j < m; j++){
						if (arr[i][j] == 99999){
							i_now = i;
							j_now = j;
							arr[i][j] = insert_data[x];
							goto heapify;
						}
					}
				}
			heapify:
				while (true){
					if (arr[i_now - 1][j_now] > arr[i_now][j_now] && arr[i_now - 1][j_now] > arr[i_now][j_now - 1]){
						int temp = arr[i_now][j_now];
						arr[i_now][j_now] = arr[i_now - 1][j_now];
						arr[i_now - 1][j_now] = temp;
						i_now--;
					}
					else if (arr[i_now][j_now - 1] > arr[i_now][j_now] && arr[i_now][j_now - 1] > arr[i_now - 1][j_now]){
						int temp = arr[i_now][j_now];
						arr[i_now][j_now] = arr[i_now][j_now - 1];
						arr[i_now][j_now - 1] = temp;
						j_now--;
					}
					else
						break;
				}

			}
			fout << "Insert ";
			for (int x = 0; x < insert_num; x++)
				fout << insert_data[x] << ' ';
			fout << endl;
			for (int i = 1; i < n; i++){
				for (int j = 1; j < m; j++){
					if (arr[i][j] == 99999)
						fout << 'x' << ' ';
					else
						fout << arr[i][j] << ' ';
				}
				fout << endl;
			}
			fout << endl;
		}
		else if (method == 2){
			while (true){
				getline(fin, s);
				if (s == "\0")
					break;
				istringstream iss(s);
				int p = 1;
				while (iss >> num){
					arr[n][p] = num;
					p++;
					if (p > m)
						m = p;
				}
				n++;
			}
			for (int i = 1; i < n + 1; i++){
				for (int j = 1; j < m + 1; j++){
					if (arr[i][j] == 0)
						arr[i][j] = 99999;
				}
			}
			for (int i = 0; i < n; i++){
				arr[i][0] == 0;
			}
			for (int j = 0; j < m; j++){
				arr[0][j] == 0;
			}
			fout << "Extract-min " << arr[1][1] << endl;
			arr[1][1] = 99999;
			int i = 1, j = 1;
			while (true){
				if (arr[i + 1][j] < arr[i][j] && arr[i + 1][j] < arr[i][j + 1]){
					int temp = arr[i][j];
					arr[i][j] = arr[i + 1][j];
					arr[i + 1][j] = temp;
					i++;
				}
				else if (arr[i][j + 1] < arr[i][j] && arr[i][j + 1] < arr[i + 1][j]){
					int temp = arr[i][j];
					arr[i][j] = arr[i][j + 1];
					arr[i][j + 1] = temp;
					j++;
				}
				else
					break;
			}
			for (int i = 1; i < n; i++){
				for (int j = 1; j < m; j++){
					if (arr[i][j] == 99999)
						fout << 'x' << ' ';
					else
						fout << arr[i][j] << ' ';
				}
				fout << endl;
			}
			fout << endl;
		}
	}
	fin.close();
	fout.close();
	return 0;
}