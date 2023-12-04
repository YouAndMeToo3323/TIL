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















