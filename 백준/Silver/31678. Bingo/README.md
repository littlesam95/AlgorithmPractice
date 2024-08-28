# [Silver V] Bingo - 31678 

[문제 링크](https://www.acmicpc.net/problem/31678) 

### 성능 요약

메모리: 2168 KB, 시간: 0 ms

### 분류

브루트포스 알고리즘, 구현

### 제출 일자

2024년 4월 8일 21:31:39

### 문제 설명

<p>It’s time to play Bingo!</p>

<p>To play Bingo, you need a game master and a drum with $90$ balls, each containing a number from $1$ to $90$, sucha that every number appears on exactly one ball.</p>

<p>Before the game starts, the game master gives each of the $n$ players a board of size $5 \times 5$. Each field of the board contains an integer between $1$ and $90$, where all the integers on the board are distinct. Each player gets a unique board.</p>

<p>After the players receive their boards, the game can begin.</p>

<p>The game master starts drawing balls from the drum. After drawing a ball with the number $x_i$, he announces that number and puts the ball aside. The players then check their boards and, if they have the drawn number, they mark it.</p>

<p>When a player marks all the $5$ numbers in a row, column, main diagonal or antidiagonal, he has a <em>Bingo!</em> and shouts it out. The game ends and that player wins.</p>

<p>To make the game more interesting, the game master has decided to introduce an additional rule. Namely, the game master will draw $m$ balls from the drum before anyone is allowed to shout <em>Bingo!</em> (even if he has already marked all the numbers in a row, column, or diagonal).</p>

<p>But, as soon as the game master drew $m$ balls, there was a commotion: all the players shouted <em>Bingo!</em> at the same time.</p>

<p>The game master is confused and doesn’t know who to trust. To resolve this situation, he asked you for help. Determine which players had a <em>Bingo!</em> after drawing $m$ balls, i.e. which players had all the numbers marked in at least one row, column, or diagonal.</p>

### 입력 

 <p>The first line contains the integer $n$ ($1 ≤ n ≤ 50$), the number of players.</p>

<p>Then, $n$ times six lines follows:</p>

<ul>
	<li>The first of these lines contains a string of at most $20$ lowercase English letters, the name of the player. No two players have the same name.</li>
	<li>Then five lines follow with five integers between $1$ and $90$, which describe the player’s board. All the integers on the board are distinct.</li>
</ul>

<p>The next line contains the integer $m$ ($1 ≤ m ≤ 90$), the number of balls the game master drew before the players shouted <em>Bingo!</em>.</p>

<p>The next line contains a sequence of $m$ integers between $1$ and $90$, the numbers the game master drew from the drum. Each number is drawn at most once.</p>

### 출력 

 <p>In the first line, output $k$, the number of players that had a <em>Bingo!</em> after drawing $m$ balls.</p>

<p>In the next $k$ lines, output the names of the players that had a <em>Bingo!</em> after drawing $m$ balls. The names should be output in the same order as they appear in the input.</p>

