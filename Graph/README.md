# Graph
- 그래프 용어 정리
  - 정점
  - 간선
  - 방향 그래프
  - 무방향 그래프
  - 완전 그래프
  - 가중치 그래프
  - 부분 그래프
  - 집합 표현
![무방향,방향 그래프](https://user-images.githubusercontent.com/79510152/116286377-215e6980-a7ca-11eb-993f-d9ca190a06c5.png)
![가중치 그래프,부분 그래프](https://user-images.githubusercontent.com/79510152/116286424-2b806800-a7ca-11eb-86ac-a7bc0cee3982.png)
![집합표현](https://user-images.githubusercontent.com/79510152/116286430-2d4a2b80-a7ca-11eb-9fb8-d0fad1ec4e66.png)

- ## 그래프의 ADT
- ### void GraphInit(UALGraph*pg, int nv);
  - 그래프의 초기화를 진행한다.
  - 두 번째 인자로 정점의 수를 전달한다.
- ### void GraphDestroy(UALGraph * pg);
  - 그래프 초기화 과정에서 할당한 리소스를 반환한다.
- ### void AddEdge(UALGraph * pg, int formV, int toV);
  - 매개변수 fromV와 toV로 전달된 정점을 연결하는 간선을 그래프에 추가한다.
- ### void ShowGraphEdgeInfo(UALGraph * pg);
  - 그래프의 간선정보를 출력한다.
