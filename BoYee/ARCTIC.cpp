// C++ program for Kruskal's algorithm to find Minimum Spanning Tree
// of a given connected, undirected and weighted graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// a structure to represent a weighted edge in graph
struct Node
{
 	   double x;
 	   double y;
};

struct Edge
{
    int src, dest;
    double weight;
};
 
// a structure to represent a connected, undirected and weighted graph
struct Graph
{

    int V, E;
	
	struct Node* node;
    struct Edge* edge;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 	
 	graph->node = (struct Node*) malloc (graph->V * sizeof ( struct Node) );
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
 
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    printf("comp a1 :%f, b1 :%f  %d \n",a1->weight,b1->weight,a1->weight > b1->weight );
    double what1 = (double)a1->weight - (double)b1->weight;
    double what2 = (double)b1->weight - (double)a1->weight;
    return (what2 > what1)-(what1 > what2);
}
 
// The main function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph)
{
    int V = graph->V;
    struct Edge result[V];  // Tnis will store the resultant MST
    int e = 0;  // An index variable, used for result[]
    int i = 0;  // An index variable, used for sorted edges
 
    // sorting
    for(i=0;i<graph->E;i++)
    {
	   printf("%x\n",&graph->edge[i]);
	}
    qsort(&(graph->edge[0]), 15, 16, myComp);
 	
 	for(i =0 ;i<(graph->E);i++)
 	{
	 	  printf("sorted %d : %d -- %d == %f\n",i,graph->edge[i].src,graph->edge[i].dest,graph->edge[i].weight);
	}
 	bool subset[graph->V];
 	memset(subset,0,sizeof(subset));
 	i = graph->E -1;
    while (1)
    {
        struct Edge next_edge = graph->edge[i--];
        subset[next_edge.src] = true;
        subset[next_edge.dest] = true;
        printf("%d : %d -- %d\n",i+1,next_edge.src,next_edge.dest);
        
		int j;
		for(j=0;j<graph->V;j++)
      		if(subset[j] == false)
      					 break;
	 
	 
	  if(j == graph->V)
	  	   break;
      					 
	    
    }
 	printf("%f\n",graph->edge[i-1].weight);
    // print the contents of result[] to display the built MST

    return;
}
 
int edgenum(int V)
{
 	int sum =0;
 	for(int i = V-1;i>0;i--)
 			sum+= i;
			
return sum;
}
// Driver program to test above functions
int main()
{

    int V = 6;  // Number of vertices in graph
    int E = edgenum(V);  // Number of edges in graph
    struct Graph* graph = createGraph(V, E);

 	for(int i=0;i<V;i++)
 	{
	 	//	scanf("%lf %lf", &(graph->node[i].x), &(graph->node[i].y) );
	}
	graph->node[0].x = 1.0;
	graph->node[0].y = 1.0;
	graph->node[1].x = 30.91;
	graph->node[1].y = 8.0;	
	graph->node[2].x = 4.0;
	graph->node[2].y = 7.64;	
	graph->node[3].x = 21.12;
	graph->node[3].y = 6.0;
	graph->node[4].x = 11.39;
	graph->node[4].y = 3.0;
	graph->node[5].x = 5.31;
	graph->node[5].y = 11.0;
 	int count =0;
 	for(int i=0;i<V;i++)
 	{
	 		for(int j=i+1;j<V; j++){
					
	 					 graph->edge[count].src = i;
						 graph->edge[count].dest = j;
						 graph->edge[count].weight = pow( pow( graph->node[i].x - graph->node[j].x, (double)2) + pow(graph->node[i].y - graph->node[j].y,(double)2),(double)1/2);
						 count++;
					//	 printf("%d %d : %f\n",i,j,graph->edge[i+j].weight);
						 }
	}
	printf("V:%d E:%d\n",graph->V,graph->E);
 	 	for(int i =0 ;i< (graph->E);i++)
 	{
	 	  printf("before sorted %d : %d -- %d == %4f\n",i,graph->edge[i].src,graph->edge[i].dest,graph->edge[i].weight);
	}

    KruskalMST(graph);
 
 	system("pause");
    return 0;
}
