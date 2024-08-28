import java.io.BufferedReader
import java.io.InputStreamReader

var section = setOf<Int>()
var answer: Int = 0

fun main() {
    val bf = BufferedReader(InputStreamReader(System.`in`))
    var e = bf.readLine().toInt()
    var n = bf.readLine().trim().split(" ").map {
        it.toInt()
    }.toIntArray()
    for (i in 0 until e) {
        if (section.contains(n[i])) {
            answer += 1
        }
        else {
            section = section.plus(n[i])
        }
    }

    println(answer)
}