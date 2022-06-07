/*
Class: CIS-7 Discrete Structures
Authors: Ivan Sebastian Perez, Eric Coria, Marlon Jimenez
Program Desrciption: This program will show the user the variations of trips to the noted cities
that must be taken to market their products. The program will determine and display possible routes,
the cheapest route, alternate roads, and a general map of the routes between the cities.
Date: June 5, 2022
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//struct
struct adjacent
{
    int city, adj1, adj2, adj3;
};

// classes
class cityMap
{
private:
    adjacent cityMap[4];

public:
    void createMap();
    void printMap();

};

// Data structure to store Adjacency list nodes
struct Node {
    int val, cost;
    Node* next;
};
// Data structure to store graph edges
struct Edge {
    int src, dest, weight;
};
class Graph
{
    // Function to allocate new node of Adjacency List
    Node* getAdjListNode(int value, int weight, Node* head)
    {
        Node* newNode = new Node;
        newNode->val = value;
        newNode->cost = weight;
        // point new node to current head
        newNode->next = head;
        return newNode;
    }
    int N;  // number of nodes in the graph
public:
    // An array of pointers to Node to represent
    // adjacency list
     Node **head;
    // Constructor
    Graph(Edge edges[], int n, int N)
    {
        // allocate memory
        head = new Node*[N]();
        this->N = N;
        // initialize head pointer for all vertices
        for (int i = 0; i < N; ++i)
            head[i] = nullptr;
        // add edges to the directed graph
        for (unsigned i = 0; i < n; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;
            // insert in the beginning
            Node* newNode = getAdjListNode(dest, weight, head[src]);
            // point head pointer to new node
            head[src] = newNode;
            // Uncomment below lines for undirected graph
            newNode = getAdjListNode(src, weight, head[dest]);
            // change head pointer to point to the new node
            head[dest] = newNode;
            
        }
    }
    // Destructor
    ~Graph() {
        for (int i = 0; i < N; i++)
            delete[] head[i];
        delete[] head;
    }
};

// used in printing out route variations
void printList(Node* ptr)
{
    while (ptr != nullptr)
    {
        cout << " -> " << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// print all neighboring vertices of given vertex
void printList(Node* ptr, int i)
{
    while (ptr != nullptr)
    {
        cout << "(" << i << ", " << ptr->val
            << ", " << ptr->cost << " Miles) ";
        ptr = ptr->next;
    }
    cout << endl;
}

// functions 
void cityMap :: createMap()
{

    for (int i = 0; i < 5; i++)
    {

        cityMap[i].city = i + 1;
        if ((i + 1) == 1)
        {
            cityMap[i].adj1 = 2;
            cityMap[i].adj2 = 3;
            cityMap[i].adj3 = 4;
        }
        else if ((i + 1) == 2)
        {
            cityMap[i].adj1 = 1;
            cityMap[i].adj2 = 3;
            cityMap[i].adj3 = 4;
        }
        else if ((i + 1) == 3)
        {
            cityMap[i].adj1 = 1;
            cityMap[i].adj2 = 2;
            cityMap[i].adj3 = 4;
        }
        else if ((i + 1) == 4)
        {
            cityMap[i].adj1 = 1;
            cityMap[i].adj2 = 2;
            cityMap[i].adj3 = 3;
        }
    }
}
void cityMap :: printMap()
{
    cout << " LEGEND: \n 1. Riverside \n 2. Perris \n 3. Moreno Valley \n 4. Hemet\n";
    for (int i = 0; i < 4; i++)
    {
        cout << "\n City: " << cityMap[i].city << " \nis adjacent to cities -> " <<
            cityMap[i].adj1 << ", " << cityMap[i].adj2 << ", " << cityMap[i].adj3 << endl;
    }
}

//Choice 2: Most cost effective route
void cheapestRoute()
{
    //The cheapest route is determined by finding the shortest path
    //This is done by choosing the path with the lowest graph line weight overall
    cout << "The most cost effective route is: " << endl;
    cout << " 1 -> 2 -> 4 -> 3 " << endl << endl;
}

void printLegend()
{
    //Genral Legend to improve output readability for user
  cout << " LEGEND: \n 1. Riverside \n 2. Perris \n 3. Moreno Valley \n 4. Hemet\n";
}

 int main()
 {
     int choice = 0;

     cout << "Welcome to CAR's routing program, please choose from one of the following options: " << endl;
     cout << "1. Trip Planning (Route Variations)" << endl;
     cout << "2. Shortest Path (Lowest Cost Trips)" << endl;
     cout << "3. Roads (Adjecencies)" << endl;
     cout << "4. Map (Matrix)" << endl;
     cout << "5. Exit Program" << endl;

     do
     {
         cout << "Enter your choice: ";
         cin >> choice;
         cout << endl;

         if (choice < 1 || choice > 5)
         {
             cout << "Invalid choice, please enter a valid choice." << endl << endl;
         }

         else
             switch (choice)
             {
             case 1:
             {
                 cout << "You picked choice: 1." << endl << endl;
               printLegend();
               
               cout << "These are the possible routes: " << endl;
               // setting relationships
               Edge edges[] = { {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4} };

               int N = 5;
               int n = sizeof(edges) / sizeof(edges[0]);
               Graph graph(edges, n, N);
               for (int i = 1; i < N; i++)
               {
                   cout << i;
                   printList(graph.head[i]);
               }
                 break;
             }

             case 2:
             {
                 cout << "You picked choice: 2." << endl << endl;
                  printLegend();
                  //Choice 2
         
                      cheapestRoute();
    
                 break;
             }

             case 3:
             {
                 cout << "You picked choice: 3.\nYou would like to view the       adjacent cities!\n" << endl << endl;
                 cityMap cityMap1;
                 cityMap1.createMap();
                 cityMap1.printMap();
                 break;
             }

             case 4:
             {
                 cout << "You picked choice: 4." << endl << endl;
                 printLegend();
               // lab 10 example 3
               // array of graph edges as per above diagram.
                  Edge edges[] =
                  {
                      // (x, y, w) -> edge from x to y having weight w
                      { 1, 2, 24 }, { 1, 3, 16 }, { 1, 4, 33 }, { 2, 3, 18 },
                      { 3, 4, 26 }, { 4, 2, 30 }
                  };
                  // Number of vertices in the graph
                  int N = 5;
                  // calculate number of edges
                  int n = sizeof(edges)/sizeof(edges[0]);
                  // construct graph
                  Graph graph(edges, n, N);
                  // print adjacency list representation of graph
                  for (int i = 0; i < N; i++)
                  {
                      // print all neighboring vertices of vertex i
                      printList(graph.head[i], i);
                  }
                               break;
                           }
             }

     } while (choice != 5);

     cout << "Thanks for playing.";
     return 0;
 }