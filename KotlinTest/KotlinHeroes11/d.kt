
// my template to Kotlin Contest
fun main() {
    val t = readInt()
    repeat (t) {
        val (n, h, b) = readInts()
        val s = Array(2) {""}
        for (i in 0 until 2) {
            s[i] = readLn()
        }
        val dx = intArrayOf(0, 0, -1, 1)
        val dy = intArrayOf(1, -1, 0, 0)
        var x = -1
        var y = -1
        for (i in 0 until 2) {
            for (j in 0 until n) {
                if (s[i][j] == 'S') {
                    x = i
                    y = j
                    break
                }
            }
            if (x != -1) break
        }
        var pos = 0
        for (i in 0 until 4) {
            val ii = dx[i] + x
            val jj = dy[i] + y
            if (ii < 0 || ii >= 2 || jj < 0 || jj >= n) continue
            pos++
        }
        var ans: Long
        var cntleft = 0
        var cntright = 0
        for (i in 0 until 2) {
            for (j in 0 until n) {
                if (s[i][j] == 'W') {
                    if (j <= y) cntleft++
                    else cntright++
                }
            }
        }
        if (cntleft != 0 && cntright == 0) {
            ans = minOf(1L * b * 2, 1L * cntleft * h)
        }
        else if (cntleft == 0 && cntright != 0) {
            ans = minOf(1L * b * 2, 1L * cntright * h)
        }
        else if (cntleft != 0 && cntright != 0){
            ans = 1L * b * 2 + minOf(1L * cntright * h, 1L * cntleft * h)
            ans = minOf(ans, 1L * b * 3)
            ans = minOf(ans, 1L * (cntright + cntleft) * h)
        }
        else ans = 0
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


