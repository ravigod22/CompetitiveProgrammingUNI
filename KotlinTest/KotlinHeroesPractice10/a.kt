

fun main() {
    val t = readInt()
    repeat (t) {
        val n = readInt()
        val a = readInts()
        var cnt = IntArray(101)
        for (i in 0 until n) {
            cnt[a[i]]++
        }
        var tmp = -1
        for (i in 1 until 101) {
            if (cnt[i] == 1) {
                tmp = i
                break
            }
        }
        var ans = -1
        for (i in 0 until n) {
            if (a[i] == tmp) {
                ans = i + 1
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
