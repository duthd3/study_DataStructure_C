# 스택
- 스택은 먼저 들어간 것이 나중에 나오는 자료구조 이다.
- LIFO(Last-in, First-out)구조의 자료구조이다.
- 배열 기반 스택, 연결리스트 기반 스택.


## 스택ADT의 정의
### void StackInit(Stack * pstack);
  - 스택의 초기화를 진행한다.
  - 스택 생성 후 제일 먼저 호출되어야 하는 함수이다.
### int SIsEmpty(Stack * pstack);
  - 스택이 빈 경우 TRUE(1)을 ,그렇지 않은 경우FALSE(0)을 반환한다.
### void SPush(Stack * pstack, Data data);
  - 스택에 데이터를 저장한다. 매개변수 data로 전달된 값을 저장한다.
### Data SPop(Stack * pstack);
  - 마지막에 저장된 요소를 삭제한다.
  - 삭제된 데이터는 반환이 된다.
  - 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다. //SIsEmpty()가 선행되어야한다.
### Data SPeek(Stack * pstack);
  - 마지막에 저장된 요소를 반환하되 삭제하지 않는다.
  - 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.
