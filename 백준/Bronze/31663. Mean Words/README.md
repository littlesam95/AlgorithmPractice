# [Bronze III] Mean Words - 31663 

[문제 링크](https://www.acmicpc.net/problem/31663) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

사칙연산, 구현, 수학, 문자열

### 제출 일자

2024년 4월 6일 22:27:23

### 문제 설명

<p>Little Timmy got caught by his teacher using some mean words. After getting sent to the principal, little Timmy learned his lesson - he should do his best to not get caught next time!</p>

<p>What Timmy decided to do is to take all the mean words that he wants to say, and combine them all together into a single "mean" word by getting the average of all the characters in the same position across all the words that have a character in that position, and then rounding this average down to get the character in that position.</p>

<p>Note: The value of a character is its ASCII value, so the value of <code>a</code> is $97$, the value of <code>b</code> is $98$ and so on up to <code>z</code>, which has value $122$. So when we average characters, we are averaging their ASCII values, rounding this down to the nearest integer, and then using the corresponding character as the result of this averaging.</p>

<p>Help Timmy create his mean mean words!</p>

### 입력 

 <p>The first line contains a single integer $N$ ($2 \leq N \leq 1\, 000$), which represents the number of words that follow. The next $N$ lines contain a single word between $1$ and $45$ lowercase English characters each.</p>

### 출력 

 <p>Output the mean word obtained by following Timmy’s procedure.</p>

