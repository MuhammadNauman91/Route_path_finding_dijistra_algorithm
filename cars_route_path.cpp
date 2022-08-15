/*
***********************************************************************************
*	Author: 			Muhammad Nauman Nasir
*	Creation Date:      13.08.2022
*	Last Edit Date:     14.08.2022
*	Revision:			0
*	Version:			1
*	File   :            cars_route_path.cpp
**********************************************************************************/

#include<iostream>
#include "cars_route_path.h"
#include <array>

using namespace std;

/**
 * Constructor
 */
RoadRouteCode::RoadRouteCode(){
}
/**
  * Destructor
  */
RoadRouteCode::~RoadRouteCode(){}
/*!
    * This function is used to find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree
    * @param dist[]      [in]  Distance array 
    * @param shortSet[]  [in]  Bool type shortest path tree set 
    * @return min_index  [out] 

*/
int RoadRouteCode::minimumDist(int dist[], bool shortSet[])
{
	// Initialize min value
	int min = INT_MAX;
	int min_index = 0;
	
	for (int i = 0; i < V; i++)
	{
		if (shortSet[i] == false && dist[i] <= min)
		{
			min = dist[i];
			min_index = i;
		}
	}
	return min_index;
}
/*!
    * Function to print shortest path from  some specific source using parent array
    * @param dist[]      [in]  Distance array 
    * @param shortSet[]  [in]  Bool type shortest path tree set 
*/
void RoadRouteCode::displayRoute(int parent[], int j)
{
    char node = 'A';
	// First Case : If j is source
	if (parent[j] == -1)
		return;
	displayRoute(parent, parent[j]);
   (j == 0) ? (node = 'A') : (j == 1) ? (node = 'B') : (j == 2) ? (node = 'C') : (j == 3) ? (node = 'D') : (node = 'E');
	printf(" %c", node);
}
/*!
    * A utility function to print the constructed distance array
	* @param dist[]      [in]  Distance array 
    * @param parent[]    [in]  Parent array to store shortest path tree
	* @param src         [in]  Source node 
*/
void RoadRouteCode::printSolution(int dist[], int n, int parent[], int src)
{
	cout << "Vertex\t Distance\t \tPath";
	for (int i = 0; i < V; i++) 
	{
	        char node = 'A';
	        (src == 0) ? (node = 'A') : (src == 1) ? (node = 'B') : (src == 2) ? (node = 'C') : (src == 3) ? (node = 'D') : (node = 'E');
	        printf("\n%d -> %d \t\t %d\t \t %c", src, i, dist[i], node);
	        displayRoute(parent, i);
	}
}
/*!
	* Function that implements Dijkstra's single source shortest path algorithm for a graph represented using adjacency matrix representation
	* @param graph[V][V]      [in]  2D array containing all weights and combinations of vertices and edges 
    * @param outArray         [in]  Ouput array to store shortest paths
	* @param src              [in]  Source node 
*/
void RoadRouteCode::dijkstra(int graph[V][V], int src, int *outArray, int outSize)
{// The output array. dist[i] will hold the shortest
	// distance from src to i
	int dist[V];

	// shortSet[i] will true if vertex i is included / in
	// shortest path tree or shortest distance from src to i
	// is finalized
	bool shortSet[V] = { false };

	// Parent array to store shortest path tree
	int parent[V] = { -1 };

	// Initialize all distances as INFINITE
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) 
	{
		// Pick the minimum distance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in first iteration.
		int u = minimumDist(dist, shortSet);
		// Mark the picked vertex as processed.
		shortSet[u] = true;
		// Update dist value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)
			// Update dist[v] only if it is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (! shortSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) 
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}
	
	for(int index = 0; index < outSize; index++)
	{
	    outArray[index] = dist[index];
	}
	
    // print the constructed distance array
	printSolution(dist, V, parent, src);
	//printSpecificSolution(dist, V,  parent, src,p);
}

// Test Case 1:
int findShortPathABC(int shortPathArray[][5], int size)
{
    // The  path for A-B-C is
    int shortPathValue = shortPathArray[0][1] + shortPathArray[1][2];
    
    return shortPathValue;
}
// Test Case 2:
int findShortPathAD(int shortPathArray[][5], int size)
{
    // The  path for A-D is
    int shortPathValue = shortPathArray[0][3];
    
    return shortPathValue;
}

/*
	Functionality Handling Testcases 
*/
// Test Case 3:
int findShortPathADC(int shortPathArray[][5], int size)
{
    // The  path for A-D-C is
    int shortPathValue = shortPathArray[0][3]+ shortPathArray[3][2];
    
    return shortPathValue;
}
// Test Case 4:
int findShortPathAEBCD(int shortPathArray[][5], int size)
{
    // The  path for A-E-B-C-D is
    int shortPathValue = shortPathArray[0][4]+ shortPathArray[4][1]+ shortPathArray[1][2]+shortPathArray[2][3];
    
    return shortPathValue;
}
// Test Case 5:
bool findShortPathAED(int shortPathArray[][5], int size)
{
    // The  path for A-E-D is
    bool shortPathValue = shortPathArray[0][4]+ shortPathArray[4][3];
    
    return shortPathValue;
}

// Test Case 8:
int findShortPathAC(int shortPathArray[][5], int size)
{
    // The  path for A-C is
    int shortPathValue = shortPathArray[0][1]+ shortPathArray[1][2];
    
    return shortPathValue;
}

// Test Case 9:
int findShortPathBB(int shortPathArray[][5], int size)
{
    // The  path for B-B is
    int shortPathValue = shortPathArray[1][2]+ shortPathArray[2][4]+ shortPathArray[4][1] ;
    
    return shortPathValue;
}
