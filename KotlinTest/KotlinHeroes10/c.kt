fun main() {
    val t = readInt()
    repeat (t) {
        val (n, k) = readLongs()
        var ans = n
        for (i in 0 until 61) {
            var bit: Long = (1L shl i)
            if (k and bit > 0) {
                ans = ans - i
                break
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

