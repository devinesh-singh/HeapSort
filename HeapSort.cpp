#include <iostream>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

#include "json.hpp"
#include "PriorityQueue.h"

using namespace std;
using json = nlohmann::json;

int main(int argc, char** argv)
{
	if (argc != 2) {
		printf("Usage: %s numSamples arraySize\n", argv[0]);
		return EXIT_FAILURE;
	}

	ifstream file;
	ofstream ofile("output.json");

	file.open(argv[1]);
	json jsonObject, jsonOutput;

	// Store the contents filename into jsonObject
	if (file.is_open()) {
		file >> jsonObject;
	}
	else
		return EXIT_FAILURE;

	int *arr = NULL;

	for (int i = 1; i <= jsonObject["metadata"]["numSamples"]; i++)
	{
		string s = "Sample";
		std::stringstream numFormat;
		numFormat << std::setw(2) << std::setfill('0') << i;
		s.append(numFormat.str());
		int size = jsonObject["metadata"]["arraySize"];
		arr = new int[size];
		int j;
		for (j = 0; j < size; j++)
			arr[j] = jsonObject[s].at(j);		PriorityQueue *pq = new PriorityQueue(size);
		json tempJson;
		for (j = 0; j < size; j++)
			pq->insert(arr[j]);
		for (j = size - 1; j >= 0; j--) 
			arr[j] = pq->removeMax();		for(j = 0; j < size;j++)			tempJson.push_back(arr[j]);		jsonOutput[s] = tempJson;	}
	jsonOutput["metadata"]["arraySize"] = jsonObject["metadata"]["arraySize"];
	jsonOutput["metadata"]["numSamples"] = jsonObject["metadata"]["numSamples"];
	ofile << jsonOutput;
}
