/*
 * In this file, you'll implement Dijkstra's algorithm to find the least
 * expensive paths in the graph defined in `airports.dat`.  Don't forget to
 * include your name and @oregonstate.edu email address below.
 *
 * Name: Luiz Medina
 * Email: medinalu@oregonstate.edu
 */

#include <stdio.h>
#include <stdlib.h>
#include "pq.h"

#define DATA_FILE "airports.dat"

int main(int argc, char const *argv[]) {
	/*
	 * Open file and read the first two int: num of nodes, num of edges
	 */
	int n_nodes, n_edges;
	int node, direction, weight;
	FILE* file = fopen(DATA_FILE, "r");
	fscanf(file, " %d %d ", &n_nodes, &n_edges);
	struct pq* priority_queue = pq_create();
	for (int i = 0; i < n_nodes; i++){
			fscanf(file, "%d %d %d", &node, &direction, &weight);
			pq_insert(priority_queue, );
	}
	/*
	 * Write your code here to find the
	 * least-cost paths from the start node to all other nodes in the graph.  Make sure
	 * to print out the least-cost paths you find at the end.
	 *
	 * FIXME: 
 	 */
	

	fclose(file);

	 
  return 0;
}

