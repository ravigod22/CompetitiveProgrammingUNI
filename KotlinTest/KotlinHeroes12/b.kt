// my template to Kotlin Contest
fun main() {
    var t = readInt()
    repeat (t) {
        val n = readInt()
        val a = readInts()
        val b = mutableListOf<Int>()
        for(e in a) {
            b.add(e)
        }
        b.sort()
        var p = 1
        var ans: Boolean = true
        while (p + 1 < 2 * n) {
            val L = b[p] - b[p - 1]
            val R = b[p + 1] - b[p]
            if (p % 2 == 0) {
                if (R > L) ans = false
            }
            else {
                if (L > R) ans = false
            }
            p += 1
        }
        if (ans) println("YES")
        else println("No")
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


