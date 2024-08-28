# [Bronze III] International Dates - 31655 

[문제 링크](https://www.acmicpc.net/problem/31655) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현, 파싱, 문자열

### 제출 일자

2024년 4월 1일 21:08:07

### 문제 설명

<p>You read a lot of documents that come from the United States, Europe, and other countries around the world. The issue is that their date formats aren’t consistent! The US formats their dates as MM/DD/YYYY while in Europe they format it as DD/MM/YYYY. That is, in the US the month comes before the day, while in Europe the day comes first. Given a date, can you determine if its <i>definitely</i> the US format, for sure European, or could be either? (Note that there are even more date formats, but luckily since the year is guaranteed to be last in this case, we only have to worry about these 2 formats.)</p>

### 입력 

 <p>The input consists of a single string comprised of 3 integers separated by forward slashes, as $AA/BB/CCCC$, where $1 \le AA, BB, \le 31$, and $0 \le CCCC \le 9999$. It is guaranteed that the given string will be a valid date for at least one of the formats. You can assume that all $12$ months have exactly $31$ days, so there is no need to worry about months with 30 days, or February.</p>

### 출력 

 <p>Output either <code>US</code> if the date doesn’t conform to the European format, or <code>EU</code> if the date doesn’t conform to the US format. Otherwise, output <code>either</code> if there is no way to know for sure which format the date follows.</p>

