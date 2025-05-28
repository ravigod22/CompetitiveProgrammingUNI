// my template to Kotlin Contest
fun main() {
    var s = readLn()
    var coins = mutableListOf('G', 'S', 'B')
    var q = readInt()
    var n = s.length + 1
    var prefix = List(n + 1) {IntArray(3) {0} }
    for (i in 0 until s.length) {
        for (j in 0 until 3) {
            var add = 0
            if (s[i] == coins[j]) add = 1
            prefix[i + 1][j] = prefix[i][j] + add
        }
    }
    repeat(q) {
        var (l, r) = readInts()
        var res = mutableListOf(prefix[r][0] - prefix[l - 1][0], prefix[r][1] - prefix[l - 1][1], prefix[r][2] - prefix[l - 1][2])
        res.sort()
        var ans = res[0] + res[2]
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



