# Table&Hash

## 테이블 자료구조의 이해
- 데이터가 key와 value로 한 쌍을 이루며, key가 데이터의 저장 및 탐색의 도구가 된다.
- 키가 존재하지 않는 값 은 저장할 수 없다. 그리고 모든 키는 중복되지 않는다.

## 테이블에 의미를 부여하는 해쉬 함수와 충돌문제
- 해쉬함수는 넓은 범위의 키를 좁은 범위의 키로 변경하는 역할을 한다.
- 서로다른 두개의 키가 해쉬함수를 통과하고 그결과가 서로같은 충돌 문제가 발생할 수도 있다.