import java.util.*

fun main() = with(Scanner(System.`in`)) {
    while (true) {
        val s = nextLine()
        if (s == "***") {
            break
        }
        println(s.reversed())
    }
}