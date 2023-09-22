#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// input data
int n_of_bins, n_of_days;
vector<int> bins_capacities; // n_of_bins

vector<int> bins_indexes, n_of_bags;


int main()
{
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

	cin >> n_of_bins >> n_of_days;
	bins_capacities.resize(n_of_bins);
	for (int i=0; i<n_of_bins; i++)
		cin >> bins_capacities[i];

	bins_indexes.resize(n_of_days);
	n_of_bags.resize(n_of_days);
	for (int i=0; i<n_of_days; i++)
	{
		cin >> bins_indexes[i] >> n_of_bags[i];
	}

	vector<int> sums(n_of_bins, 0);
	for (int day=0; day<n_of_days; day++)
	{
		sums[bins_indexes[day]] += n_of_bags[day];
		
		
		if (sums[bins_indexes[day]] > bins_capacities[bins_indexes[day]])
		{
			// qui solo se la somma supera il massimo
			sums[bins_indexes[day]] -= n_of_bags[day];



		}
	}



	// insert your code here

	cout << 42 << endl; // print the result
	return 0;
}
