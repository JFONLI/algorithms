# HW4 The Map Maker
[Problem](Problem.md)
## Maps of Los Santos

Since there are no negative edges in this map.
We can use Dijkstra’s Algorithm to solve the problem.
1. Let every vertex to be source one time.
2. Use Dijkstra’s Algorithm to find the minimum path from source to all vertex
(implemented by priority queue and Adjacent List)
3. Store the path to V0 in a vector answer
4. Print out the elements in answer

### Time complexity : O(V*ElogV + V^2)

<br>

## Maps of Portal Chambers
Since there are some negative edges but no negative cycles in this map.
The proper algorithm is Floyd-Warshall Algorithm.
1. Create an Adjacent Matrix
2. Let every vertex to be intermediate vertex once and run through all distance(V^3)
3. Print out the elements distance[i][i] (since it asks the path from any chamber back to it)

### Time complexity : O(V^3)

<br>

## Maps of Skyrim
We are asked to find whether there are a positive cycle in the graph.
We can complete it by Bellman-Ford Algorithm with a little change.
1. Create an Adjacent List to read input, however multiply (-1) to every edge
2. Use Bellman-Ford Algorithm to find whether there is a negative cycle
Since we multiply (-1) to every edge, if there contains a negative cycle in the new graph, it
indicates a positive cycle in the original one.

### Time complexity : O(V^4)

<br>

## Maps of Blight Town
Using DFS to find path from V0 to V[v-1].
Then check every path whether the warrior will be poisoned.
1. Using DFS to find every paths from V0 to V[v-1]
2. Using a variable total to calculate first n routes.
3. Check if it is bigger than m, if yes, break, if no, discard the first route and add the next route
and continue to check if it is bigger then m.
4. If the path won’t poison the warrior, change the variable healthy to true
5. Print out the answer based on healthy<br>


### Time complexity : O(V+E)