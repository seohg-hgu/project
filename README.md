# 과제 제출 관리 프로그램
학생들의 기본 정보와  과제 제출 여부와 과제 점수를 저장하고 관리하는 프로그램이다. 학생들의 과제 제출 여부를 쉽게 파악하고 과제 점수의 평균을 계산할 수 있다. 

## 기능 목록
1. 학생 정보 추가
2. 학생 정보 출력
3. 과제 제출 학생 출력
4. 제출 정보 변경
5. 학생 정보 삭제 (이름)
6. 모든 학생 정보 리스트 출력
7. 학번으로 검색
8. 학생 이름으로 정렬
9. 파일 새로 읽기
10. 파일 저장
11. 레코드 최적화
12. 과제 제출 통계 출력
13. 보고서 파일 저장

### 학생 정보 추가

- 추가할 수 있는 공간이 있는지 확인한다.
	- 공간이 있을경우
	  - 학생의 이름, 학번, 과제 제출여부, 과제점수를 입력하여 추가한다.
  
  - 공간이 없을 경우
    - 저장하지 못하도록 한다.

### 학생 정보 출력

- 출력할 학생의 이름을 입력받는다.
  - 입력받은 학생 정보가 있을 경우 
    - 그 학생의 이름, 학번, 과제 제출 여부, 과제 점수를 출력한다.
  - 입력받은 학생 정보가 없을 경우
    - 해당 멤버가 없다고 출력한다.

### 과제 제출 학생 출력

- 과제를 제출한 학생(과제 제출 여부가 Y)의 리스트를 출력한다. 

### 제출 정보 변경

- 정보를 변경할 학생의 이름을 입력받는다.
  - 입력받은 학생 정보가 있을 경우
    - 학번, 과제 제출 여부, 과제 점수를 추가로 입력받은 후 저장한다.
  - 일치하는 학생이 없을 경우 
    - 해당 멤버가 없다고 출력한다.
    
### 학생 정보 삭제 (이름)

- 이름을 입력받는다.
  - 입력받은 학생 정보가 있을 경우
    - 해당 학생 기록을 삭제한다.
  - 일치하는 학생이 없을 경우 
    - 해당 멤버가 없다고 출력한다.

### 모든 학생 정보 리스트 출력

- 모든 학생 정보를 출력한다.
    
### 학번으로 검색

- 학번 앞자리부터 3자리를 입력받고 일치하는 모든 학생 정보를 출력한다.

### 학생 이름으로 정렬

- 학생의 이름을 사전 순으로 정렬한 후 결과를 출력한다.

### 파일 새로 읽기

- 기존에 저장되어 있던 레코드를 삭제한다.
- data file을 읽어들여 레코드를 추가한다.
   - 동일한 학생 정보가 있으면 건너뛴다.

### 파일 저장

- 학생 정보 레코드를 문자열 형태로 가져와 파일로 저장한다.

### 레코드 최적화

- 레코드 중 빈 공간을 끝으로 몰아준다.

### 과제 제출 통계 출력

- 과제를 제출한 학생의 수, 과제 점수 평균, grade 별 학생 수를 출력한다.

### 보고서 파일 저장

- 제출통계를 보고서 파일로 저장한다.
