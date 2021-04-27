#include<stdio.h>
#include "ALGraph.h"

int main(void)
{
	ALGraph graph; //그래프의 생성
	GraphInit(&graph, 5); //정정5개

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, C, D);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, A);

	ShowGraphEdgeInfo(&graph);
	GraphDestroy(&graph);
	return 0;
}
