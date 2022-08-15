/*
***********************************************************************************
*	Author: 			Muhammad Nauman Nasir
*	Creation Date:      13.08.2022
*	Last Edit Date:     14.08.2022
*	Revision:			0
*	Version:			1
*	File   :            cars_route_path_main.cpp
**********************************************************************************/
#include<iostream>

#include "cars_route_path.h"
#include <array>


using namespace std;

int main()
{    
     RoadRouteCode Rotl;
	// Let us create our graph provided.
	int graph[V][V] = { 
	         {0, 5, 0, 5, 7},      // A     
             {0, 0, 4, 0, 0},      // B
             {0, 0, 0, 8, 2},      // C
             {0, 0, 8, 0, 6},      // D
             {0, 3, 0, 0, 0}       // E   
	};
	
    // Shortest path array for everynode.
    int shortArray[V] = {0};
    
	int shortPathArray[V][V] = {{0}};
	
	// Call dikstra algorithm.
	// Run the loop to get the shortest path for every node.
	for(int i = 0; i < V; i++)
	{
	    Rotl.dijkstra(graph, i, shortArray, V);
	    cout << "\n\n";
	    
	    // Store the values of the array into a shortest path array.
	    for(int j = 0; j < V; j++)
	        shortPathArray[i][j] = shortArray[j];
	}
	
	// Test case 1 : Short Path Route from A-B-C.
	assert(9 == findShortPathABC(shortPathArray, 5));
	cout << "\nTest Case 1  is Passed\n";
	
		
	// Test case 2 : Short Path Route from A-D.
	assert(5 == findShortPathAD(shortPathArray, 5));
	cout << "\nTest Case 2  is Passed\n";
	
	// Test case 3 : Short Path Route from A-D.
	assert(13 == findShortPathADC(shortPathArray, 5));
	cout << "\nTest Case 3  is Passed\n";
	
	// Test case 4 : Short Path Route from A-D.
	assert(22 == findShortPathAEBCD(shortPathArray, 5));
	cout << "\nTest Case 4  is Passed\n";
	
	// Test case 5 : Short Path Route from A-E-D.
	assert(true == findShortPathAED(shortPathArray, 5));
	cout << "\nNO SUCH ROUTE\n";
	
	// Test case 8 : Short Path Route from A-C.
	assert(9 == findShortPathAC(shortPathArray, 5));
	cout << "\nTest Case 8  is Passed\n";
	
	// Test case 9 : Short Path Route from B-B.
	assert(9 == findShortPathBB(shortPathArray, 5));
	cout << "\nTest Case 9  is Passed\n";

 return 0;
}