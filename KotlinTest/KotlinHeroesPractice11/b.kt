
// my template to Kotlin Contest
fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val s = readLn()
        val cnt = s.count { it == '1'}
        if (cnt % 4 == 0 && n == (cnt / 4 + 1) * (cnt / 4 + 1)) {
            println("Yes")
        } else println("No")
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




