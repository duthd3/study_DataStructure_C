#include <stdio.h>
#include "ALGraphDFS.h"

int main(void)
{
	ALGraph graph;
	GraphInit(&graph, 7);      // A, B, C, D, E, F, G의 정점 생성

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, C);
	AddEdge(&graph, B, D);
	AddEdge(&graph, B, E);
	AddEdge(&graph, C, E);
	AddEdge(&graph, D, G);
	AddEdge(&graph, E, G); 
	AddEdge(&graph, G, F);

	ShowGraphEdgeInfo(&graph);

	DFShowGraphVertex(&graph, A); printf("\n");
	DFShowGraphVertex(&graph, C); printf("\n");
	DFShowGraphVertex(&graph, E); printf("\n");
	DFShowGraphVertex(&graph, G); printf("\n");

	GraphDestroy(&graph);
	return 0;
}
