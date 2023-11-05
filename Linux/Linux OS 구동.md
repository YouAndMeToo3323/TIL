Linux OS 구동
===
**가상화**는 서버, 스토리지, 네트워크 및 기타 물리적 시스템에 대한 가상 표현을 생성하는데 사용할 수 있는 기술입니다. 가상 소프트웨어는 물리적 하드웨어 기능을 모방하여 하나의 물리적 머신에서 여러 가상 시스템을 동시에 실행합니다. 즉, **여러 운영체제 운용할 수 있습니다.**

저는 Linux의 OS(운영체제)를 구동하기 위해 가상화 머신 **Hyper-V**를 사용합니다.

### Hyper-V 요구 사항
* Windows 10 Enterprise, Pro 또는 Education
* 두 번째 수준 주소 변환(SLAT)을 사용하는 64비트 프로세서.
* VM 모니터 모드 확장(Intel CPU의 VT-c)에 대한 CPU 지원.
* 최소 4GB의 메모리.

Hyper-V 역할은 Windows 10 Home에는 **설치할 수 없습니다.**

**설정>업데이트 및 보안>정품 인증**을 열어 Windows 10 Home 버전을 Windows 10 Pro로 업그레이드하세요.

### 1. PowerShell을 사용하여 Hyper-V를 사용하도록 설정
1. 관리자 권한으로 PowerShell 콘솔을 실행.
2. 다음 명령 실행.

```powershell
Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Hyper-V -All
```

3. 설치가 완료되면 컴퓨터를 다시 부팅합니다.

### 2. CMD와 DISM을 사용하여 Hyper-V를 사용하도록 설정
1. 관리자 권한으로 PowerShell 또는 CMD 세션을 실행.
2. 다음 명령을 입력.

```powershell
DISM /Online /Enable-Feature /All /FeatureName:Microsoft-Hyper-V
```

### 3. 설정을 통해 Hyper-V 역할 활성화
1. Windows 단추를 마우스 오른쪽 단추로 클릭하고 '앱 및 기능'을 선택.
2. 오른쪽의 관련 설정에서 **프로그램 및 기능**를 선택.
3. **Windows 기능 사용/사용 안 함**을 선택.
4. **Hyper-V**를 선택하고 **확인**을 클릭.

![Window기능옵션](https://github.com/YouAndMeToo3323/TIL/assets/126636390/2d5968a6-d229-4254-9f60-6bfdaa69b593)

5. 설치가 완료되면 컴퓨터를 다시 시작하라는 메시지가 표시.

***

## 가상화 활성화
Windows 기능 켜기/끄기 화면에서 **'Hyper-V'** 선택 항목만 선택한 뒤 설치를 진행하는 경우가 많은데, 메인보드에서 가상화 옵션이 비활성화된 상태라면, 하위 항목인 **'Hyper-V 관리도구'** 는 정상적으로 설치되었지만, **'Hyper-V 플랫폼'** 은 설치되지 않은 경우가 대부분입니다.

CPU 가상화 미지원 또는 옵션 비활성화된 상태에서 Hyper-V 플랫폼 설치를 시도하면 **"Hyper-V를 설치할 수 없습니다. 펌웨어에서 가상화 지원을 사용할 수 없습니다."** 풍선말과 함께 항목을 선택할 수 없습니다.

### 1. Hyper-V 요구 사항 확인
1. **명령 프로프트** 실행.
2. **"systeminfo"** 명령어 입력.

Hyper-V 요구 사항에서 **"펌웨어 가상화 사용"** 항목이 **"아니오"** 인 경우 메인보드에서  해당 옵션을 활성화 해야 합니다.

### 2. SVM Mode 활성화
1. 시스템 재부팅 후 **UEFI BIOS** 진입.
2. **SVM Mode** 또는 **Intel Virtualization Technology**  활성화하고 시작.
3. **명령 프로프트** 재실행.
4. **"systeminfo"** 명령어 입력.
5. **"하이퍼바이저가 검색되었습니다. Hyper-V에 필요한 기능이 표시되지 않습니다"** 확인.

만약 **UEFI BIOS**에서 가상화 옵션이 없을 경우 가까운 서비스 센터에 방문하여 가상화를 활성화 하시면 됩니다.

### 참고사이트
[리눅스OS 구동](https://lunacellstone.tistory.com/88),
[Hyper-v 사용 및 설정](https://learn.microsoft.com/ko-kr/virtualization/hyper-v-on-windows/quick-start/enable-hyper-v),
[가상화 활성화](https://forbes.tistory.com/995)
