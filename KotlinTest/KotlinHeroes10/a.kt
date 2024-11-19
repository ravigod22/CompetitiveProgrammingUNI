fun main() {
    val t = readInt()
    repeat (t) {
        val n = readInt()
        var ans = 100
        for (i in 0 until 101) {
            for (j in 0 until 34) {
                for (k in 0 until 21) {
                    if ((i + 3 * j + 5 * k) == n) {
                        ans = minOf(ans, i)
                    }
                }
            }
        }
        println(ans)
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
