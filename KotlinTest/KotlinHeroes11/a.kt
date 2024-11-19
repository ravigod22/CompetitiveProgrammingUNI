
// my template to Kotlin Contest
fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val a = readInts()
        var maxe = 0
        for (i in 0 until n - 1) {
            maxe = maxOf(maxe, a[i])
        }
        if (maxe + 1 == a[n - 1]) {
            println(maxe)
        }
        else println("Ambiguous")
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readDouble() = readLn().toDouble()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }


