import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val f = nextLine().split(' ')
    val a = f[0].toInt()
    val b = a + f[1].toInt()
    val c = f[2].toInt()
    val d = c + f[3].toInt()
    val s = nextLine().split(' ')
    val p = s[0].toInt()
    val m = s[1].toInt()
    val n = s[2].toInt()
    var answerP = 0
    var answerM = 0
    var answerN = 0

    val pb = (p % b)
    val pd = (p % d)
    if ((pb > 0) && (pb <= a)) {
        answerP++
    }
    if ((pd > 0) && (pd <= c)) {
        answerP++
    }

    val mb = (m % b)
    val md = (m % d)
    if ((mb > 0) && (mb <= a)) {
        answerM++
    }
    if ((md > 0) && (md <= c)) {
        answerM++
    }

    val nb = (n % b)
    val nd = (n % d)
    if ((nb > 0) && (nb <= a)) {
        answerN++
    }
    if ((nd > 0) && (nd <= c)) {
        answerN++
    }

    println("$answerP\n$answerM\n$answerN")
}