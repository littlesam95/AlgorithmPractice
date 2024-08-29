import kotlin.math.*
import java.util.*

fun main() = with(Scanner(System.`in`)) {
    var answer: Int = 0
    var arr: Array<Array<Int>> = arrayOf(arrayOf(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), arrayOf(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0))
    val n: Int = nextLine().toInt()
    for (i in 1 .. n) {
        answer = 0
        arr = arrayOf(arrayOf(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0), arrayOf(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0))
        val a = nextLine()
        for (j in a) {
            arr[0][j - 'a'] += 1
        }
        val b = nextLine()
        for (j in b) {
            arr[1][j - 'a'] += 1
        }
        for (j in 0 .. 25) {
            answer += abs(arr[0][j] - arr[1][j])
        }

        println("Case #${i}: $answer")
    }
}