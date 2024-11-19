fun main() {
    val t = readInt()
    repeat (t) {
        val (k, m) = readLongs()
        var mod = 3 * k
        var times = m / mod
        var com = 2 * k
        var ans = maxOf((times * mod + com) - m, 0)
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

