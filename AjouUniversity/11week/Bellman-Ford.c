#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define INF (100000009)

// 주어진 그래프
int map[6][6] = {
	{INF, 10, INF, 20, INF, INF},
	{INF,INF,60,INF,INF,INF},
	{INF,INF,INF,INF,-30,20},
	{INF,20,INF,INF,30,INF},
	{INF,INF,INF,INF,INF,10},
	{INF,INF,INF,INF,INF,INF}
};



int bellman(int destination) {
	// 시
	int start = 0;// 시작 정잠
	int distance[6]; // 시작정점에서 다른 정점까지의 거리

	for (int i = 0; i < 6; i++) {
		distance[i] = INF;
	}
	distance[start] = 0;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] != INF) {
				// 출발 정점에서 weight를 더했을때 기존 j 정점까지 최소비용보다 작다면
				// 갱신
				if (distance[i] + map[i][j] < distance[j]) {
					distance[j] = distance[i] + map[i][j];
				}
			}
		}
	}
	return distance[destination];
}


int main() {
	printf("도착 vertex를 입력하세요: ");
	int destination;
	scanf("%d", &destination);
	printf("Vertex 0번에서 Vertex %d번까지 shortest path의 길이는 %d 입니다", destination, bellman(destination));
}
