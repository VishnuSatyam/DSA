//A graph is a data structure used to represent relationships between objects.
/*A ---- B
|      |
|      |
C ---- D*/

/*Here:

A, B, C, D → vertices/nodes
The lines → edges

So this graph has:

Vertices = 4
Edges = 4*/

/*Two major types of graphs

Undirected Graph

The connection works both ways.

A ---- B*/

/*Directed Graph

The connection has a direction.

A ----> B*/


/*Unweighted
A ---- B

We only care that A and B are connected.

Weighted
A --10-- B

The edge has a value/weight.*/




/*Degree

In an undirected graph, degree means:

Number of edges connected to a node.

Example:

    1
    |
2---0---3

Node 0 has:

degree = 3

because three edges touch it.*/




/*Indegree and Outdegree

These are mainly used for directed graphs.

A ---> B ---> C

For B:

indegree  = 1
outdegree = 1

Because:

One edge comes into B
One edge goes out of B*/



// total degree of a graph is 2 Edges.