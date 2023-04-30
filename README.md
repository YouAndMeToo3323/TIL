Git을 공부한 책과 사이트를 적었습니다.

참고 도서

[지옥에서 온 문서 관리자 깃&깃허브 입문](https://www.google.co.kr/books/edition/Do_it_%EC%A7%80%EC%98%A5%EC%97%90%EC%84%9C_%EC%98%A8_%EB%AC%B8%EC%84%9C_%EA%B4%80%EB%A6%AC%EC%9E%90/W6HFDwAAQBAJ?hl=ko&gbpv=0)

참고사이트

[velog](https://velog.io/@ejayjeon/Github-Repository%EB%93%A4-%EA%B9%94%EB%81%94%ED%95%98%EA%B2%8C-%ED%95%98%EB%82%98%EB%A1%9C-%ED%95%A9%EC%B9%98%EA%B8%B0, "Repository 합치기"), 
[yeonLog](https://yeonyeon.tistory.com/169, "Repository 합치기")

---

## 기존 Repository들을 새로운 Repository에 병합

1. 새로운 Repository 생성
- 자신의 프로필에서 Repositories 선택
-  기존 Repository들을 합칠 새로운 Repository(New)로 생성.

2. 새로운 Repository를 로컬 저장소로 clone
- 생성한 Repository의 주소를 복사하고 로컬 저장소로 clone.

` git clone 복사한Repository주소 `

3. clone한 Repository에 기록 남기기
- 새로 생성한 Repository는 기록이 없다면 기존 Repository들을 합칠 수 없으므로, 터미널을 이용하여 commit과 GitHub에 push를 실행.

`git add 파일명`

`git commit -m '기록할 메시지'`

`git push -u origin master`

4. 기존 Repository들을 새로 생성한 Repository로 합치기
- 
- 기존 Repository의 주소를 복사
- Subtree에 기존 Repository명과 기존메인 브랜치명, 주소를 입력하여 차례대로 병합.


` git remote add origin <원격 저장소 주소> ` //수정이 필요함.

` git subtree add prefix=기존Repository명 기존Repository주소 기존메인브랜치명`

5. 하나로 합친 Repository 원격저장소로 push
- 합쳐진 Repository를 원격저장소(GitHub)로 push


