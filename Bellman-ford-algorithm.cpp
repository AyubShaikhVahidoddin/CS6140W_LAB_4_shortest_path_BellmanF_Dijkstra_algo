//============================================================================
// Name        : Bellman-ford-algorithm.cpp
// Author      : Ayub SHaikh
// Version     :
// Copyright   : IIT Madars @2022 copyright notice
// Description :  Bellman Ford SHortest Path Algorithm
// Date        :  4th-MAY_2022
//============================================================================

#include <iostream>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

#define inf INT_MAX
struct EdgeBellmanFord
{
    int NodeSrc;
    int Nodedest;
    int EdgeWeight;
};

struct GraphBellmanFord
{
    int numVertices = -1;
    std::vector<EdgeBellmanFord> edgeVector = {};
};

int main()
{
	GraphBellmanFord graphBellmanF;

	cout << "-----------------------------------------------------------------" << endl;
		 cout << "**** LAB Programming Assignment-4 *************************" << endl;
		 cout << "**** Implement Bellman-Ford and Dijkstra's algorithm for shortest path finding algorithm ***\n" << endl;

		 cout << "Submitted By: Name- AYUB SHAIKH VAHIDODDIN" << endl;

		 cout << "by Roll number: CS21M515" << endl;
		 cout << "Email Id :- Ayub.Shaikh.Vahid@gmail.com" << endl;
		 cout << "-----------------------------------------------------------------" << endl;


    //No of vertex, edge
    int numEdge;
    printf("\n Please Enter the number of vertex=>\n");
    scanf("%d", &graphBellmanF.numVertices);
    printf("\n Please Enter the number of edge=>\n");
    scanf("%d", &numEdge);

    printf("\n Please Enter Node --> Edge and weight by space in between them. \n"
    		"For exampl if you want to enter for 2 -> 3 with weight 10, then input should be 2 3 10 \n");
    for (int i = 0; i < numEdge; i++)
    {
        int edge, node_vertices, wight;
        scanf("%d %d %d", &edge, &node_vertices, &wight);
        graphBellmanF.edgeVector.push_back({edge, node_vertices, wight});
    }

    int sourceNode = 0;
   // start

            cout << "Enter the source node : ";
            cin>> sourceNode;

    int distance[graphBellmanF.numVertices];

        //Set distance to infinity -
    //  and then set visited as false
        for (int i = 0; i < graphBellmanF.numVertices; i++)
        {
            distance[i] = inf;
        }


        distance[sourceNode] = 0;

        for (int i = 0; i < graphBellmanF.numVertices - 1; i++)
        {
            for(auto e: graphBellmanF.edgeVector)
            {

                if (distance[e.NodeSrc] != inf)
                {
                    //Update the distance list if the weight of the edge is lesser than the distance list
                    if(e.EdgeWeight + distance[e.NodeSrc] < distance[e.Nodedest])
                    {
                        distance[e.Nodedest] = e.EdgeWeight + distance[e.NodeSrc];
                    }
                }
            }
        }

        // Print the shortest path
        printf("\n\nShortest Path using BellmenFord's Algo");
        for (int i = 0; i < graphBellmanF.numVertices; i++)
        {
            printf("\n\t%d --> %d = %d",sourceNode, i, distance[i]);
        }

        for (int i = 0; i < graphBellmanF.numVertices; i++)
        {
                 cout<<"\n\n\t From "<<sourceNode <<" to "<<i<< " distance is "<<distance[i]<<endl;
         }
    // END

        cout << " \n ----------------------END Thank You!-----------------------" << endl;
        cout << "-----------------------------------------------------------" << endl;

        int exit;
        cout << "press any number to exit: ";
        cin >> exit;

        if(exit > 0)
        {
              return 0;
         }
}
