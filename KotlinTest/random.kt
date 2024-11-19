import kotlin.random.Random

val n = 5

fun main() {
    for (i in 1 .. n) {
        for (j in 1 .. n) {
            var num = Random.nextInt(1, 11)
            print("$num${if (j == n) "\n" else " "}")
        }        
    }
}
