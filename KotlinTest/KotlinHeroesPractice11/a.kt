
// my template to Kotlin Contest
fun main() {
    val t = readInt()
    repeat(t) {
        val (x, y) = readInts()
        val mine = minOf(x, y)
        val maxe = maxOf(x, y)
        println("$mine $maxe")
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



