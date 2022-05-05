//============================================================================
// Name        : Djikstra_Algorithm.cpp
// Author      : AYUB SHAIKH V.
// Version     : V1
// Copyright   : IIT Madras @2022 copyright notice
// Description : Dijkstra’s shortest path Algorithm
//  Roll NUmber: CS21M515
//        Date : 4th- MAY-2022
//============================================================================

#include <iostream>
using namespace std;

/*int main() {
	cout << "Djikstra Algorithm" << endl; // prints Djikstra Algorithm
	return 0;
}*/

#include <limits.h>

#define size 5
#define INFINITY 9999
void dijkstraPath(int Graphs[size][size],int n,int startnode);


void printVertexDistanceFromSource(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstraPath(int Graphs[size][size],int n,int startnode)
{
   int cost[size][size],distance[size],pred[size];
   int visited[size],count,mindistance,nextnode,i,j;
   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
   if(Graphs[i][j]==0)
      cost[i][j]=INFINITY;
   else
      cost[i][j]=Graphs[i][j];
   for(i=0;i<n;i++) {
      distance[i]=cost[startnode][i];
      pred[i]=startnode;
      visited[i]=0;
   }
}

int DjikstraMINPathFind(int costOfVertex[], bool shortestPathArray[], int V)
{


	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (shortestPathArray[v] == false && costOfVertex[v] <= min)
			min = costOfVertex[v], min_index = v;

	return min_index;
}

// Structure heap node
struct MinHeapNode
{
    int  vertex;
    int dist;
};



void minimumHeapify(struct MinHeap* minHeap,
                                  int idx1)
{
    int smallest, left, right;
    smallest = idx1;
    left = 2 * idx1 + 1;
    right = 2 * idx1 + 2;
}

int main()
{


    int vertexVector = 0;

    cout << "-----------------------------------------------------------------" << endl;
   	 cout << "--------LAB Programming Assignment-4 *************************" << endl;
   	 cout << "******* Dijkstra’s shortest path Algorithm. in C++----------\n" << endl;

   	 cout << "Submitted By: Name- AYUB SHAIKH VAHIDODDIN" << endl;

   	 cout << "by Roll number: CS21M515" << endl;
   	 cout << "Email Id :- Ayub.Shaikh.Vahid@gmail.com" << endl;
   	 cout << "-----------------------------------------------------------------" << endl;



    cout << "Enter the Number of NOdes or Vertices : "<<endl;
    cin  >> vertexVector;
	int graphForDijkstras[vertexVector][vertexVector] = { };


   for (int index = 0; index < vertexVector; index++)
    {
        for (int j_index = 0; j_index < vertexVector; j_index++)
        	graphForDijkstras[index][j_index] = 0;
    }

    for (int index = 0; index < vertexVector; index++)
    {
        cout<<"Please Enter values for row : "<<(index)<<endl;
        for (int j = index; j < vertexVector; j++)
        {
        	int valuesForRowEnteredByUser;

            cout<<"("<<index << " " << j<<") : ";
            cin>> valuesForRowEnteredByUser;
            // Set zero for No Edges

            graphForDijkstras[index][j] = valuesForRowEnteredByUser;

            graphForDijkstras[j][index] = valuesForRowEnteredByUser;

            graphForDijkstras[j][index] = graphForDijkstras[index][j];

        }
    }


    cout<<"\n\Storing edegs by weight : \n"<<endl;


    cout<<" Desti | \t";
    for (int i = 0; i < vertexVector; i++)
        cout<< i << "\t   ";
    cout<<endl;

    for (int i = 0; i < vertexVector*10; i++)
        cout<< "-";
    cout<<endl;


    // Display Table
   for (int i = 0; i < vertexVector; i++)
    {cout<<"Source Node" << i << " |\t";
        for (int j = 0; j < vertexVector; j++)
        {
            cout<<graphForDijkstras[i][j] << "\t";
        }
        cout<<endl;
    }

   cout<<"\n\The Input Graph is as below : \n"<<endl;
   for (int i = 0; i < vertexVector; i++)
      {cout<<"" << " \t";
          for (int j = 0; j < vertexVector; j++)
          {
              cout<<graphForDijkstras[i][j] << "\t";
          }
          cout<<endl;
      }

    int source = 0;
    cout << "Please Enter the source Node : ";
    cin>> source;
	int cost[vertexVector];

	bool shortestPathArray[vertexVector];

	for (int i = 0; i < vertexVector; i++)
		cost[i] = INT_MAX, shortestPathArray[i] = false;

	cost[source] = 0;


	for (int index = 0; index < vertexVector - 1; index++)
	{

		int u = DjikstraMINPathFind(cost, shortestPathArray, vertexVector);

		shortestPathArray[u] = true;

		for (int v = 0; v < vertexVector; v++)
			if (!shortestPathArray[v] && graphForDijkstras[u][v] && cost[u] != INT_MAX && cost[u] + graphForDijkstras[u][v] < cost[v])
				cost[v] = cost[u] + graphForDijkstras[u][v];
	}

	/*for (int v = 0; v < vertexVector; v++)
				if (!shortestPathArray[v] && graphForDijkstras[u][v] && cost[u] != INT_MAX && cost[u] + graphForDijkstras[u][v] < cost[v])
					cost[v] = cost[u] + graphForDijkstras[u][v];
		}*/

	cout <<"Vertex \t Distance from Source:=> " << source <<endl;
	for (int i = 0; i < vertexVector; i++)
		cout << i << " \t\t"<<cost[i]<< endl;



	cout << " \n ----------------------END Thank You!-------------------" << endl;
	cout << " \n---------------------------------------------------------" << endl;

    int exit;
	cout << "press any number to exit: ";

	cin >> exit;

      if(exit > 0)
      {
           return 0;
       }
}
