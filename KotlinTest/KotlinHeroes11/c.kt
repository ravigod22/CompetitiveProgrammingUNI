
// my template to Kotlin Contest
fun main() {
    val t = readInt()
    repeat (t) {
        val s = readLn().split("+")
        val n = s.size
        var ans: Long = 0
        ans += s[0].toLong()
        ans += s[n - 1].toLong()
        for (i in 1 until n - 1) {
            val k = s[i].length
            var aux: Long = 0
            for (j in 1 until k) {
                var tmp = s[i].substring(0, j)
                var tmp2 = s[i].substring(j)
                var sum = tmp.toLong() + tmp2.toLong()
                aux = maxOf(aux, sum)
            }
            ans += aux
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


