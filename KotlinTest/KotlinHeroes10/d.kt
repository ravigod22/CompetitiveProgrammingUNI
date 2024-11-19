fun main() {
    val t = readInt()
    repeat (t) {
        val n = readInt()
        val a = readInts()
        var i = 0
        var ans: Long = 0
        while (i < n) {
            if (a[i] == 0) {
                ++i
                continue
            }
            var sum: Long = 0
            var pos_odd: Boolean = true
            var max_odd: Long = 0
            var cnt = 0
            while ((i < n) && (a[i] != 0)) {
                sum = sum +  (1L * 2 * a[i])
                if (pos_odd) {
                    max_odd = maxOf(max_odd, a[i].toLong())
                    pos_odd = false
                }
                else pos_odd = true
                i++
                cnt++
            }
            if (cnt % 2 == 0) {
                max_odd = 0
            }
            ans += sum - max_odd
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


