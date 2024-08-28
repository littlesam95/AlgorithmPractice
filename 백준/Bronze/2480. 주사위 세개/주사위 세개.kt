import java.io.*
import java.util.*

fun main(args: Array<String>) {
    val BR = BufferedReader(InputStreamReader(System.`in`))
    val Token = StringTokenizer(BR.readLine())
    var A : Int = Integer.parseInt(Token.nextToken())
    var B : Int = Integer.parseInt(Token.nextToken())
    var C : Int = Integer.parseInt(Token.nextToken())
    if ((A == B) && (B == C) && (A == C)) { // 1. 같은 눈이 3개가 나오면 10,000원+(같은 눈)×1,000원의 상금을 받게 된다.
        var answer : Int = (A * 1000) + 10000
        println(answer)
    }
    else if (A == B) { // 2. 같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)×100원의 상금을 받게 된다.
        var answer : Int = (A * 100) + 1000
        println(answer)
    }
    else if (B == C) {
        var answer : Int = (B * 100) + 1000
        println(answer)
    }
    else if (A == C) {
        var answer : Int = (C * 100) + 1000
        println(answer)
    }
    else { // 3. 모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)×100원의 상금을 받게 된다.
        var arr : Array<Int> = arrayOf(A, B, C)
        var answer = arr[0]
        for (i in 0 until arr.size) {
            if (answer < arr[i]) {
                answer = arr[i]
            }
        }
        answer = answer * 100
        println(answer)
    }
    BR.close()
}