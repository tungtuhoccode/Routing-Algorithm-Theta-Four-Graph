## Definitions
### 1. The class of graph that this algorithm is for is a subclass of weighted geomtetric graph. Definition of weight geometric graph: 
   
    A graph $G = (P, E)$ in which: 
    - set P: set of points in the plane
    - set E: set of edges between two points (directed or undirected)
    - weight of an edge (p,q): is the Euclidean distance L2 of p and q

### 2. Definition of L2-metric: 

- Distance is the Euclidean distance between two point p and q (straight line distance)

### 3. Definition of spanning ratio of a graph G: 
- Assumming that $` L_2 (P_G (s, t)) `$ is our shortest path from s to t in the L2-metric

- Spanning ratio $c$: min value c such that $` L_2 (P_G (s, t)) \le c \cdot L_2 (s, t) `$ 

- Informal language: The shortest path between s and t is smaller at most c times the euclidean length between s and t. 

### 4. Definition of a spanner graph: 
- A graph is called c-spanner (or spanner) if spanning ratio is at most constant c. 

*** QUESTION: Are there any difference between the shortest path $` (P_G (s, t)) `$ and $` L_2 (P_G (s, t)) `$ path ? ***

### 5. Definition of routing ratio of a local online routing algorithm A: 
- It is the maximum value c' such that $` L_2 \; (P^A_G \; (s, t)) \le c' \cdot  L_2 \; (P_G \; (s, t))`$

- When c' is  constant, the algorithm A is called competitive on the class G.

### 6. Theta graphs
- Definition: $\theta_{4}$-graph is a graph that each vertex v has at most 4 outgoing edges. Each outgoing edge is chosen based on the criteria that it is the closest (when running a line that is 45 degrees to the to the dividing line (has a slope of 1 or -1))

### 7. Local routing: 

*** QUESTION: 
What does it mean by btaining competitive routing strategies on all Theta k graph? 
- Update on June 1: For theta-k graph with k >= 7, there is a competitive routing algorithm already.
- How about the theta-5 graph?

### 8. Input params for the algorithm 
The routing algorithm is denoted by Clean/Greedy/Sweep(u,t,N(u),d) 
- u: the current vertex 
- t: the target vertex 
- N(u) are the (1-hop) neighbours of u 
- d ∈ {0, 1} represents the chosen diagonal of t. 
    * d = 0 corresponds lt− 
    * d = 1 corresponds to lt+.

### 9. About the algorithm:
Algorithm 1 uses 3 helper methods to run: 

Let v ∈ N(u) be the vertex in the cone of u that faces d

1. $Clean(u,t,N(u),d)$ 
- returns True if (u, v) cross the chosen diagonal
- returns False otherwise

2. $Sweep(u,t,N(u),d)$
- Return the vertex v such that
    * 