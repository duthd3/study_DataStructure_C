# 큐(Queue)
- 큐는 먼저 들어간 것이 먼저 나오는 자료구조이다.
- FIFO(First-in, First-out)
- 배열 기반 큐, 연결리스트 기반 스택.
- 큐를 구성하는 배열을 효율적으로 사용하기 위해 원형큐 도입.

## 큐ADT의 정의

### void QueueInit(Queue * pq);
  - 큐의 초기화를 진행한다.(head,tail)
  - 큐 생성 후 제일 먼저 호출되어야 하는 함수이다.
   
### int QIsEmpty(Queue * pq);
  - 큐가 빈 경우 TRUE(1), 그렇지 않은 경우 FALSE(0)을 반환한다.

### void Enqueue(Queue * pq, Data data);
  - 큐에 데이터를 저장한다. 매개변수 data로 전달된 값을 저장한다.
  
### Data Dequeue(Queue * pq);
  - 저장순서가 가장 앞선 데이터를 삭제한다.
  - 삭제된 데이터는 반환된다.
  - 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.

### Data QPeek(Queue * pq)
  - 저장순서가 가장 앞선 데이터를 반환하되 삭제하지 않는다.
  - 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.
