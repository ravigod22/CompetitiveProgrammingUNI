
// my template to Kotlin Contest
fun main() {
    var t = 1
    repeat(t) {
        val n = readInt()
        val s = readLn()
        var cnt =  MutableList (26) {0}
        for (i in 0 until n) {
            cnt[s[i] - 'a'] += 1
        }
        var can: Boolean = false
        for (e in cnt) {
            if (e > 1) can = true
        }
        if (can || n == 1)  println("Yes")
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


