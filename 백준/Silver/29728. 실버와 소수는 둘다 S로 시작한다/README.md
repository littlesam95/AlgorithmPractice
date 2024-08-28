# [Silver II] 실버와 소수는 둘다 S로 시작한다 - 29728 

[문제 링크](https://www.acmicpc.net/problem/29728) 

### 성능 요약

메모리: 26704 KB, 시간: 92 ms

### 분류

자료 구조, 덱, 구현, 수학, 정수론, 소수 판정, 에라토스테네스의 체

### 제출 일자

2024년 2월 29일 18:22:55

### 문제 설명

<p>브실이는 실버 난이도의 소수 관련 문제를 풀던 도중, "실버"와 "소수"가 동일하게 <span style="color:#e74c3c;"><code>S</code></span>로 시작한다는 것을 깨달았다.</p>

<p>물론 소수는 한글로 적었을 때의 발음만 <span style="color:#e74c3c;"><code>S</code></span>로 시작하지, 영어로는 prime이라 틀린 말이지만 브실이는 새로운 문제를 만들 생각에 들떠 세세한 것은 신경 쓰지 않기로 했다. 브실이가 구상한 문제는 다음과 같다.</p>

<p>먼저 빈 문자열 $A$를 준비한다. 그러면 브실이가 정수 $N$을 불러줄 것이다. 첫 번째 차례부터 $N$번째 차례까지 다음 작업을 진행한다.</p>

<ol>
	<li>현재 차례가 소수 번째가 아닌 경우, $A$의 끝에 알파벳 <span style="color:#e74c3c;"><code>B</code></span>를 추가한다.</li>
	<li>현재 차례가 소수 번째인 경우는 조금 특별하다. 만약 $A$의 마지막 문자가 <span style="color:#e74c3c;"><code>B</code></span>인 경우 마지막 문자를 알파벳 <span style="color:#e74c3c;"><code>S</code></span>로 교체하고, $A$의 끝에 <span style="color:#e74c3c;"><code>S</code></span>를 하나 추가한다. 아니라면 단순히 $A$의 끝에 <span style="color:#e74c3c;"><code>S</code></span>를 하나 추가한다. 이후 $A$를 뒤집는다.</li>
</ol>

<p>브실이는 이러한 문제를 구상했지만 $N$이 클수록 $A$도 엄청나게 길어질 텐데, 이러한 문자열을 일일이 채점할 자신이 없다. 따라서 $S$에 포함된 <span style="color:#e74c3c;"><code>B</code></span>와 <span style="color:#e74c3c;"><code>S</code></span>가 각각 몇 개인지를 기준으로 삼아 채점을 진행하려고 한다.</p>

<p>브실이가 채점에 참고할 수 있도록 위 문제의 답지 작성을 도와주자.</p>

<p>단, 이 문제에서 말하는 소수는 $1$과 자기 자신 이외의 약수가 존재하지 않는 $1$ 이외의 양의 정수라고 생각하자.</p>

### 입력 

 <p>첫 번째 줄에 정수 $N$이 주어진다. $(1 \le N \le 5000000)$</p>

### 출력 

 <p>문자열 $A$에 포함된 알파벳 <span style="color:#e74c3c;"><code>B</code></span>의 개수와 <span style="color:#e74c3c;"><code>S</code></span>의 개수를 공백으로 구분하여 출력한다.</p>

