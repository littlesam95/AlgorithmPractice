import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextLine().toInt()
    for (i in 0 until n) {
        val s = nextLine().split(' ')
        val x = s[0].toInt()
        val y = s[1].toInt()
        if (x < y) {
            println("NO BRAINS")
        }
        else {
            println("MMM BRAINS")
        }
    }
}