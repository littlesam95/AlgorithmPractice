import java.io.BufferedReader
import java.io.InputStreamReader

var days = arrayOf<Int>(0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31)
var days2 = mapOf<Int, String>(0 to "Wednesday", 1 to "Thursday", 2 to "Friday", 3 to "Saturday", 4 to "Sunday", 5 to "Monday", 6 to "Tuesday")

fun main() {
    val bf = BufferedReader(InputStreamReader(System.`in`))
    var n = bf.readLine().trim().split(" ").map() {
        it.toInt()
    }.toTypedArray()
    var d = n[0]
    var m = n[1]
    for (i in 0 until m) {
        d += days[i]
    }
    d %= 7
    println(days2[d])
}