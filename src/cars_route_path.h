/**********************************************************************************
**	 Implementation of a class solving Route paths using Dijistra Algorithm 
***********************************************************************************
*	Author: 			Muhammad Nauman Nasir
*	Creation Date:      13.08.2022
*	Last Edit Date:     14.08.2022
*	Revision:			0
*	Version:			1
*	File   :            cars_route_path.h
**********************************************************************************/
/****************************************************************************
**	DESCRIPTION
*****************************************************************************
**	Problem Statement:
**  The local commuter railroad services a number of towns in Kiwiland.  Because of monetary concerns, all of the tracks are 'one-way.'  
**  That is, a route from Kaitaia to Invercargill does not imply the existence of a route from Invercargill to Kaitaia.  
**  In fact, even if both of these routes do happen to exist, they are distinct and are not necessarily the same distance!

**  The purpose of this problem is to help the railroad provide its customers with information about the routes.  
**  In particular, you will compute the distance along a certain route, the number of different routes between two towns, and the shortest route between two towns.
**
**  Input:  
**  A directed graph where a node represents a town and an edge represents a route between two towns.  
**  The weighting of the edge represents the distance between the two towns.  
**  A given route will never appear more than once, and for a given route, the starting and ending town will not be the same town.

**  Proposed Solution:
**  As its Directed Graph problem and we donot have negative values so solved it by using Dijistra Algorithm , Depth First search and combinational approach to solve the required use case. 
**
** Idea:
** - - To make Extensible class with flexibility to extend the methods based upon needs 
   - - Google coding style guide
   - - Object class concept 
   - - Singleton class at the moment has been used but as future work this problem needs to extended using other design pattern methods as we can create separate classes for different functionality
       like Route, Grpahs , Algorithm, node extension keeping in mind
   - - Tried to keep it as simple as possible
   
** Open for Modifications for future: 
   
    - - Other desin pattern apart from Singleton
	- - More generic solution 
	- - Speed should be optimized by using more smarter approach
	- - Templates needs to be used to make it more organized 
	- - Separate structure to run testcases as for production ready code testcases should be handled separately (Right now unfortunately ran testcases in main file)

****************************************************************************/

#ifndef CARS_ROUTE_PATH_H_
#define CARS_ROUTE_PATH_H_

#include <iostream>
#include <string>
#include <cmath>
#include <limits.h>
#include <cassert>
static constexpr int V = 5;

using namespace std;
/** \class RoadRoute cars_route_path.h
 *  \brief Class containing functionality of the RoadRoute
 *
 */

class RoadRouteCode
{
public:
	/**
	 * Constructor
	 */
	RoadRouteCode();
	/**
	  * Destructor
	  */
    ~RoadRouteCode();

	static int  minimumDist(int dist[], bool shortSet[]);
	static void displayRoute(int parent[], int j);
	static void printSolution(int dist[], int n, int parent[], int src);
	static void dijkstra(int graph[V][V], int src, int *outArray, int outSize);
};

#endif /* CARS_ROUTE_PATH_H_ */