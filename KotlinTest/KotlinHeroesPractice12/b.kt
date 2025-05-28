
// my template to Kotlin Contest
fun main() {
    var t = readInt()
    repeat(t) {
        val n = readInt()
        val s = readLn()
        var cnt1 = 0
        var cnt2 = 0
        for (e in s) {
            if (e == '_') cnt1 += 1
            else cnt2 += 1
        }
        var ans = 1L * (cnt2 / 2) * cnt1 * ((cnt2 + 1) / 2)
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



