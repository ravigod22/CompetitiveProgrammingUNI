

// my template to Kotlin Contest
fun main() {
    var t = readInt()
    repeat(t) {
        var (a, b, c) = readInts()
        var ans = ""
        for (i in 0 until a) {
            ans += ('0' + i)
        }
        for (i in 0 until b) {
            ans += ('A' + i)
        }
        for (i in 0 until c) {
            ans += ('a' + i)
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


