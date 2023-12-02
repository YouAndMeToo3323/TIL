### 함수 포인터
* **'함수 포인터 변수'** 는 **메모리상에 바이너리 형태로 저장된 함수의 주소값을 저장하는 포인터 변수**를 말한다.
* 함수 포인터의 포인터 형은 반환형과 매개변수의 선언형태를 기준으로 구분한다.
```cpp
int SimpleFunc(int ptr1, int ptr2){}	//상수형태의 함수 포인터
//반환형 int
//매개변수 선언 int ptr1, int ptr2

int (*fptr)(int, int); //함수 포인터 변수, 변수형태의 함수 포인터
fptr = SoSimpleFunc;
fptr(3, 4);            //SoSimple(3,4)와 동일한 결과
```
* 매개변수의 선언으로 함수 포인터 변수 사용할 수 있다.
```cpp
int FuncInFunc(int ptr1, int ptr2, int (*cmp)(int n1, int n2))
{
  return cmp(ptr1, ptr2);    //첫번째, 두번째 인자를 재 전달하면서 세번째 인자로 전달된 함수를 호출
}
int SimpleFunc(int ptr1, int ptr2){}

num1 = 10;
num2 = 20;
FuncInFunc(num1, num2, SoSimple)
```
### void 포인터
* **'형(Type)'이 존재하지 않는 포인터 변수**를 가리켜 **'void형 포인터 변수'** 라고 한다.
* 어떠한 변수의 주소 값이든 담을 수 있다(함수의 주소 값도 포함).
```cpp
void SoSimpleFunc(void){}

int num = 20;
void* ptr;

ptr = &num;           //변수 num의 주소 값 저장
printf("%p \n",ptr);  //예시 : 001AF974
ptr = SoSimpleFunc;   //함수 SoSimpleFunc의 주소 값 저장
printf("%p \n",ptr);  //예시 : 00F61109
```
* void형 포인터 변수를 가지고는 아무런 포인터 연산도 하지 못한다(값의 변경이나 참조도 불가능).
```cpp
int num = 20;
void* ptr =&num;
*ptr = 20;	//컴파일 에러
ptr++;		//컴파일 에러
```
#### main함수로의 인자전달
* 프로그램 실행 시 main함수로 전달할 인자를 열거할 수 있으며(결정할 수 있으며), main함수 역시 이러한 인자를 전달받을 수 있도록 <br/>제한된 형태의 매개변수 선언이 가능하다.
* main함수의 매개변수 argv는 더블 포인터 변수이고 char형 포인터 변수로 이뤄진 1차원 배열의 이름을 전달 받을 수 있는 매개변수이다.

```cpp
int main(int argc, char* argv[])
{
  int i = 0;
  printf("전달된 문자열의 수: %d \n", argc);

  while(argv[i] != NULL)
  {
    printf("%d번째 문자열: %s \n", i + 1, argv[i]);
    i++;
  }
  return 0;
}
