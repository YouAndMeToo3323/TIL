Git을 공부한 자료를 모았습니다.

---

## 기존 Repository들을 새로운 Repository에 병합

1. 새로운 Repository 생성
자신의 프로필에서 Repositories 선택하고 기존 Repository들을 합칠 새로운 Repository(New)로 생성.

2. 새로운 Repository를 로컬 저장소로 clone
생성한 Repository의 주소를 복사하고 로컬 저장소로 clone.

` git clone 복사한Repository주소 `

3. clone한 Repository에 기록 남기기
새로 생성한 Repository는 기록이 없다면 기존 Repository들을 합칠 수 없으므로, 터미널을 이용하여 commit과 GitHub에 push를 실행.

`git add 파일명`
`git commit -m '기록할 메시지'`
`git push -u origin master`

4. 기존 Repository들을 새로 생성한 Repository로 합치기


5. 하나로 합친 Repository 원격저장소로 push
