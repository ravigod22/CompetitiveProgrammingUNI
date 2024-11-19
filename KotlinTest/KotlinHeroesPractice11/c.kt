// my template to Kotlin Contest
fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val a = readInts()
        var i = -1
        var j = n
        var tmp = a[0]
        var tmp2 = a[n - 1]
        while (i + 1 < n && tmp == a[i + 1]) ++i
        while (j > 0 && tmp2 == a[j - 1]) j--
        if (i < j) {
            if (tmp == tmp2) println(j - i - 1)
            else { 
                val ans = minOf(j, n - i - 1)
                println(ans)
            }
        } else println(0)
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





