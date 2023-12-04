### scanf와 같은 함수 사용 시 C4996 오류가 발생하는 원인
* 최신 Visual Studio에서 C4996 오류가 발생하는 이유는 scanf, strcpy, fopen 과 같은 함수들을 사용했기 때문인데,<br/>
이 함수들은 **버퍼 오퍼플로우(BOF) 등의 보안 취약점을 가지고 있으므로 사용을 자제하라는 의미**이다.
* 이러한 위험성을 가진 함수들은 C++14 이상에서는 deprecated 되어 있다.

```cpp
#include <stdio.h>

int main()
{
...

error C4996 : 'scanf' : This function or variable may be unsafe.Consider using scanf_s instead.To disable deprecation,
use _CRT_SECURE_NO_WARNINGS.See online help for details.//scanf함수 사용시 오류 발생
scanf(...);

...
}
```
### 해결 방법
#### 1. 특정 코드 줄에 대한 경고 끄기
* 특정 코드 줄에 대한 경고를 끄려면 pragma를 warning 사용합니다.
```cpp
#pragma warning(suppress : 4996)
scanf(...);
```
#### 2. 파일 내에서 경고 끄기
* 다음의 모든 항목에 대해 파일 내에서 경고를 해제하려면 경고 pragma를 사용한다.
```cpp
#pragma warning(disable : 4996)
```

#### 3. 안전한 함수로 대체 하기 scanf_s, strcpy_s, fopen_s
* 가장 권장되는 방법은 보안 취약점이 해결되는 안전한 함수로 대체하여 사용하는 것이다.
* scanf_s, strcpy_s, fopen_s 등의 secure 함수로 대체하여 사용하면 오류가 해결되며, 동시에 취약점도 해결할 수 있다.
```cpp
scanf_s("%d", &n);
```
#### 4. 매크로 추가 #define _CRT_SECURE_NO_WARNINGS
* scanf_s, strcpy_s 등의 함수는 안전하지만 그만큼 쓰기가 번거로운 경우가 있다.
* 취약점에 민감할 필요가 없는 코드를 작성하는 경우 코드 최상단에 **_CRT_SECURE_NO_WARNINGS** 를 정의해주면<br/>
해당 소스 파일(c, cpp)에서 이전과 같이 **안전하지 않은(unsafe) scanf, strcpy, fopen 등의 함수를 사용**할 수 있다.
```cpp
//'#define _CRT_SECURE_NO_WARNINGS'는 반드시 최상단('#include <studio.h>' 보다 위)에 정의해야 한다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
...

scanf(...);

...
}
```
#### 5. 프로젝트 속성에서 SDL 검사 옵션 해제하기
* SDL(Security Development Lifecycle) 옵션을 해제해주면 모든 소스 파일에서 안전하지 않은 함수를 사용할 수 있다.
* 실행 방법
1) [솔루션 탐색기] -> [프로젝트 우클릭] -> [속성(R)]
2) [프로젝트 속성] -> [C/C++] -> [SDL 검사]: 아니요(/sdl-) 선택
<img src = "https://github.com/YouAndMeToo3323/TIL/assets/126636390/7bc2554e-1b50-40d1-90f4-fa4c8421fc77" width = "80%" height = "60%" title = "프로젝트 속성"></img>

---
#### 참고자료
[헤이즐넛s_오류C4996 해결 방법](https://itisguide.tistory.com/8)<br/>
[Microsoft Build_C4996](https://learn.microsoft.com/ko-kr/cpp/error-messages/compiler-warnings/compiler-warning-level-3-c4996?view=msvc-170)
