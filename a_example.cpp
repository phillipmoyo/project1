#include<iostream>
#include<vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	vector<int> slices;
	vector<int> indices;

	int max_slices = 0;
	int pizza_count = 0;
	int pizza_used = 0;
	int sum = 0;
	int input;
	string line;

	ifstream myfile ("a_example.in");

	if (myfile.is_open())
	{
		getline (myfile,line); 
		stringstream s(line);
		s >> max_slices;
		s >> pizza_count;	

		getline (myfile,line); 
		stringstream ss(line);
		while (ss >> input)
		{
			slices.push_back(input);
		}

		myfile.close();

		for (int i = slices.size() - 1; i >= 0; i--)
		{
			if (max_slices - slices[i] >= 0)
			{
				sum += slices[i];
				indices.push_back(i);
				pizza_used++;
				max_slices -= slices[i];	
			}
		}

		cout << pizza_used << endl;

		for (int i = indices.size() - 1; i >= 0; i--)
			cout << indices[i] << " ";
		cout << endl;
	}
	else
	{
		cout << "Unable to open file" << endl;
	}



	return (0);
}
