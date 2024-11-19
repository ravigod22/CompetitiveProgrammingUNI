fun main() {
    val t = readInt()
    repeat (t) {
        val (n, k) = readInts()
        var max_k = 1
        var cnt = 0
        while (max_k * 2 <= n) {
            max_k *= 2
            cnt++
        }
        cnt++
        //println(cnt)
        if (k > cnt) {
            println(-1)
            return@repeat
        }
        var perm = Array<Int>(n) {0}
        var times = k
        var ini = 2
        var p = 1
        for (i in 0 until n) {
            if (perm[i] != 0) continue
            var tmp = i
            if (times > 1) {
                while (tmp < n) {
                    perm[tmp] = p
                    p++
                    tmp += ini
                }
                ini *= 2
                times--
            }
            else {
                for (j in 0 until n) {
                    if (perm[j] != 0) continue
                    perm[j] = p
                    p++
                }
            }
        }
        println(perm.joinToString(" "))
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
