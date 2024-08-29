import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextLine().toInt()
    for (i in 0 until n) {
        val a = nextLine().split(' ')
        val b = nextLine().split(' ')
        val scoreA = a[0].toInt() + (a[1].toInt() * 2) + (a[2].toInt() * 3) + (a[3].toInt() * 3) + (a[4].toInt() * 4) + (a[5].toInt() * 10)
        val scoreB = b[0].toInt() + (b[1].toInt() * 2) + (b[2].toInt() * 2) + (b[3].toInt() * 2) + (b[4].toInt() * 3) + (b[5].toInt() * 5) + (b[6].toInt() * 10)
        if (scoreA > scoreB) {
            println("Battle ${i + 1}: Good triumphs over Evil")
        }
        else if (scoreA < scoreB) {
            println("Battle ${i + 1}: Evil eradicates all trace of Good")
        }
        else {
            println("Battle ${i + 1}: No victor on this battle field")
        }
    }
}