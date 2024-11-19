fun main() {
    val t = readInt()
    repeat(t) {
        var (n, k) = readInts()
        val S = readLn()
        var cntLower = IntArray(27)
        var cntUpper = IntArray(27)
        for (i in 0 until n) {
            if (S[i] >= 'a' && S[i] <= 'z') {
                cntLower[S[i] - 'a']++
            } 
            else {
                cntUpper[S[i] - 'A']++
            }
        }
        var ans = 0
        var steps = 0
        for (i in 0 until 27) {
            if (cntLower[i] == 0 && cntUpper[i] == 0) continue
            var tmp : Int = (cntLower[i] + cntUpper[i]) / 2
            var min_e = minOf(cntLower[i], cntUpper[i])
            ans += min_e 
            steps += tmp - min_e
        }
        var maximun = ans + minOf(steps, k)
        println(maximun)
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
