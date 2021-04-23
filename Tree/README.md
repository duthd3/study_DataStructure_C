# 트리(Tree)
- 트리는 계층적 관계를 표현하는 자료구조이다.
- 노드:트리의 구성요소.
- 간선:노드와 노드를 연결하는 연결선
- 루트노드:트리 구조에서 최상위에 존재하는 노드
- 단말노드:아래로 또 다른 노드가 연결되어 있지 않은 노드(leaf node)
## 이진트리(Binary Tree)와 서브 트리(Sub Tree)
- 큰 트리는 작은 트리로 구성이 된다. 큰 트리에 속하는 작은 트리를 가리켜 서브트리라 한다
- ### 이진트리(재귀적 이다)
  - 루트 노드를 중심으로 두 개의 서브 트리로 나뉘어진다.
  - 나뉘어진 두 서브 트리도 모두 이진 트리이어야 한다.
  - 노드가 위치할 수 있는 곳에 노드가 존재하지 않는다면, 공집합 노드가 존재하는 것으로 간주한다.(공집합 노드도 이진 트리의 판단에 있어서 노드로 인정한다.)
  - ### 포화 이진 트리, 완전 이진트리
    - 모든 레벨이 꽉 찬 이진 트리를 가리켜 포화 이진 트리라 한다.
    - 모든 레벨이 꽉 찬 상태는 아니지만 , 차곡차곡 빈 틈 없이 노드가 채워진 이진 트리를 완전 이진트리라 한다.(위에서 아래로 왼쪽에서 오른쪽순서대로 채워진다.)
  - 배열기반 이진트리, 연결 리스트 기반 이진트리
## 이진 트리 자료구조의 ADT
  - BTreeNode * MakeBTreeNode(void);
    - 이진 트리 노드를 생성하여 그 주소 값을 반환한다.
  - BTData GetData(BTreeNode * bt);
    - 노드에 저장된 데이터를 반환한다.
  - void SetData(BTreenode * bt, BTData data);
    - 노드에 데이터를 저장한다. data로 전달된 값을 저장한다.
  - BTreeNode * GetLeftSubTree(BTreeNode * bt);
    - 왼쪽 서브 트리의 주소 값을 반환한다.
  - BTreeNode * GetRightSubTree(BTreeNode * bt);
    - 오른쪽 서브 트리의 주소값을 반환한다.
  - void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
    - main의 왼쪽 서브 트리를 연결한다.
  - void MakeRightSubTree(BTreeNode * main ,BTreeNode * sub);
    - main의 오른쪽 서브 트리를 연결한다.

## 이진 트리의 순회(Traversal)
- 순회의 세 가지 방법
  - 전위순회(Preorder Traversal) 루트노드를 먼저
  - 중위순회(Inorder Traversal) 루트노드를 중간에
  - 후위순회(Postorder Traversal) 루트노드를 마지막에
