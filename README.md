# Route_path_finding_dijistra_algorithm

**********************************************************************************/
/****************************************************************************
**	Trains
*****************************************************************************
A generic tackle at the trains problem in C++. You can find a detailed description below.

Problem:
The local commuter railroad services a number of towns in Kiwiland. Because of monetary concerns, all of the tracks are 'one-way.' That is, a route from Kaitaia to Invercargill does not imply the existence of a route from Invercargill to Kaitaia. In fact, even if both of these routes do happen to exist, they are distinct and are not necessarily the same distance!

The purpose of this problem is to help the railroad provide its customers with information about the routes. In particular, you will compute the distance along a certain route, the number of different routes between two towns, and the shortest route between two towns.

Input:
A directed graph where a node represents a town and an edge represents a route between two towns. The weighting of the edge represents the distance between the two towns. A given route will never appear more than once, and for a given route, the starting and ending town will not be the same town.

Output:
For test input 1 through 5, if no such route exists, output 'NO SUCH ROUTE'. Otherwise, follow the route as given; do not make any extra stops! For example, the first problem means to start at city A, then travel directly to city B (a distance of 5), then directly to city C (a distance of 4).

The distance of the route A-B-C.
The distance of the route A-D.
The distance of the route A-D-C.
The distance of the route A-E-B-C-D.
The distance of the route A-E-D.
The number of trips starting at C and ending at C with a maximum of 3 stops. In the sample data below, there are two such trips: C-D-C (2 stops). and C-E-B-C (3 stops).
The number of trips starting at A and ending at C with exactly 4 stops. In the sample data below, there are three such trips: A to C (via B,C,D); A to C (via D,C,D); and A to C (via D,E,B).
The length of the shortest route (in terms of distance to travel) from A to C.
The length of the shortest route (in terms of distance to travel) from B to B.
The number of different routes from C to C with a distance of less than 30. In the sample data, the trips are: CDC, CEBC, CEBCDC, CDCEBC, CDEBC, CEBCEBC, CEBCEBCEBC.
Test Input:
For the test input, the towns are named using the first few letters of the alphabet from A to E. A route between two towns (A to B) with a distance of 5 is represented as AB5.

Graph: AB5, BC4, CD8, DC8, DE6, AD5, CE2, EB3, AE7
Expected Output:
Output #1: 9 Output #2: 5 Output #3: 13 Output #4: 22 Output #5: NO SUCH ROUTE Output #6: 2 Output #7: 3 Output #8: 9 Output #9: 9 Output #10: 7


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

   
** Diagram
![image](https://user-images.githubusercontent.com/43953818/184623353-26478b61-19cb-4384-b1b7-43ff0fdd6c27.png)

 
** Algorithm

Upon analysis of the problem description and a visualisation of the map, it is clear to see that this requires an implementation of Dijkstra’s Shortest Path Algorithm . 


** Unit Testing

Right now all Unit Test cases has been included in -main file and .cpp file but to be honest its not good approach so normally all unit tests should be handled separately 
in separate folder and separate files.

Like (For future )

Tests
- cars_route_path_test.h
- cars_route_path_test.cpp
- main_test.cpp

** Operating Instructions

You may wish to either compile the code into an executable, or run it in Visual Studio.

It can be run easily in Visual studio code by running main.cpp function. 
Can also run this in open source compiler like C++ shell or GDB compiler by copy pasting stuffs directly

** Future Work

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
	- - Investigate some other algorithms for path finding to handle this problem more smartly. 
	

