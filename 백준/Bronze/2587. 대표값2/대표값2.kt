import java.io.BufferedReader
import java.io.InputStreamReader

var arr = arrayOf<Int>()
var answer: Int = 0

fun main() {
    val bf = BufferedReader(InputStreamReader(System.`in`))
    for (i in 0 until 5) {
        var n = bf.readLine().toInt()
        arr = arr.plus(n)
        answer += n
    }
    arr.sort()

    println(answer / 5)
    println(arr[2])
}