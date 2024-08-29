import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextLine().toInt()
    for (i in 0 until n) {
        val m = nextLine().toInt()
        var p1 = 0
        var p2 = 0
        for (j in 0 until m) {
            val s = nextLine().split(' ')
            if (s[0] == "R") {
                when (s[1]) {
                    "S" -> {
                        p1++
                    }
                    "P" -> {
                        p2++
                    }
                }
            }
            else if (s[0] == "S") {
                when (s[1]) {
                    "R" -> {
                        p2++
                    }
                    "P" -> {
                        p1++
                    }
                }
            }
            else if (s[0] == "P") {
                when (s[1]) {
                    "R" -> {
                        p1++
                    }
                    "S" -> {
                        p2++
                    }
                }
            }
        }
        if (p1 > p2) {
            println("Player 1")
        }
        else if (p1 < p2) {
            println("Player 2")
        }
        else {
            println("TIE")
        }
    }
}