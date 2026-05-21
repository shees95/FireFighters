# FireFighters

# git 컨벤션
✨ feat	     해당 파일에 새로운 기능이 생김  
🎉 add	     없던 파일을 생성함, 초기 세팅  
🐛 fix	     버그 수정  
♻️ refactor	 코드 리팩토링  
⚡️ improve	 개선  

# git 명령어
레포지토리 다운 : git clone https://github.com/shees95/FireFighters.git

브랜치 목록 확인 : git branch  
브랜치 선택 : git switch branch-name  
브랜치 추가 : git switch -c convention/branch-name  
브랜치 삭제 : git branch -d branch-name      << 웬만하면 쓰지 마세요  
  
현재 디렉토리 내 변경된 파일 전체 추가 : git add .  
파일 개별 추가 : git add dnf/Monster/Monster.cpp  
디렉토리 추가 : git add dnf/Monster/*  
  
커밋 : git commit -m "convention : 커밋 내용"  
커밋 리셋 : git reset  
  
푸쉬 (최초 1회) : git push --set-upstream origin dev  
푸쉬  : git push  
  
풀 : git pull  
  
새로고침 : git fetch (pull 이전, push 이후 항상 사용)  

# git 전략
1. 개발 시작 전, dev 브랜치에서 pull
2. dev 브랜치에서 내가 개발할 기능 이름을 딴 브랜치 생성
3. 개발 완료 후 commit, push

# ※※※ 다른 팀원이 개발중인 부분은 건들지 말것 ※※※
같은 파일을 건드는 순간부터 git 충돌이 나기 시작함
추가적인 개발이 필요한 부분이 있다면 팀원과 상의 후 추가 개발을 요청해야함
ex) GameLog 개발자 : Character의 스탯 Getter좀 만들어주세요. 제가 만들면 git 충돌 나니까요.


# dev 클래스

- GameManager : 전용준

- Character : 최석훈
- Inventory : 최석훈

- Monster : 최호용

- Battle : 신희성

- RewardSystem : 신희성

- GameLog : 장희동

- Item : 임찬우
- ItemType : 임찬우

