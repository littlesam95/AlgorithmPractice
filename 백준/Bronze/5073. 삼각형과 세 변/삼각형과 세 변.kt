import java.util.*

fun main() = with(Scanner(System.`in`)) {
    while (true) {
        val n = nextLine()
        if (n == "0 0 0") {
            break
        }
        val s = n.split(' ')
        val arr = arrayOf<Int>(s[0].toInt(), s[1].toInt(), s[2].toInt())
        val a = arr[0]
        val b = arr[1]
        val c = arr[2]
        if (a + b <= c) {
            println("Invalid")
        }
        else if ((a == b) && (b == c)) {
            println("Equilateral")
        }
        else if ((a == b) || (b == c) || (a == c)) {
            println("Isosceles")
        }
        else {
            println("Scalene")
        }
    }
}