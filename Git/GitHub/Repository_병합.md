기존 Repository들을 새로운 Repository에 병합
===
#### 1. 새로운 Repository 생성
자신의 프로필에서 Repositories 선택합니다.

기존 Repository들을 합칠 새로운 Repository(New)로 생성합니다.

#### 2. 새로운 Repository를 로컬 저장소로 clone
생성한 Repository의 주소를 복사하고 로컬 저장소로 clone.

```bash
$ git clone 복사한Repository주소 
```

#### 3. clone한 Repository에 기록 남기기
새로 생성한 Repository는 기록이 없다면 기존 Repository들을 합칠 수 없으므로, 터미널을 이용하여 commit과 GitHub에 push를 실행합니다.

```bash
$ git add 파일명
$ git commit -m '기록할 메시지'
$ git push -u origin master
```

#### 4. 기존 Repository들을 새로 생성한 로컬 저장소로 합치기
기존 Repository의 주소를 복사합니다.
Subtree에 기존 Repository명과 기존메인 브랜치명, 주소를 입력하여 차례대로 병합합니다.

```bash
$ git subtree add --prefix=기존Repository명 기존Repository주소 기존메인브랜치명
```

#### 5. 하나로 합친 Repository 원격저장소로 push
합쳐진 Repository를 로컬 저장소에서 원격저장소(GitHub)로 push 

```bash
$ git push origin HEAD:main --force 
```

--force 명령어는 사용자의 로컬 변경사항들이 원격 변경사항들과 호환되지 않는 경우, 사용자의 변경사항을 push 하는 유일한 방법이 **force push**를 이용하는 것입니다.
