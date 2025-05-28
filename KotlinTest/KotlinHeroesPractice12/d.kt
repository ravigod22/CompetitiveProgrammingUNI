
// my template to Kotlin Contest
fun main() {
    var t = readInt()
    repeat(t) {
        var (n, x, y) = readLongs()
        val a = readInts()
        val order: MutableList<Int> = mutableListOf()
        var sum: Long = 0
        for (e in a) {
            order.add(e)
            sum += 1L * e
        }
        var l = n.toInt()
        var ans: Long = 0
        order.sort()
        for (i in 0 until l - 1) {
            // sum - a[i] - y <= a[j] <= sum - a[i] - x
            var L = sum - 1L * order[i] - y
            var R = sum - 1L * order[i] - x
            var PuntL: Int = -1
            var PuntR: Int = -1
            var lo = i + 1
            var hi = l - 1
            while (lo < hi) {
                var mid = (lo + hi) / 2
                if (1L * order[mid] >= L) hi = mid
                else lo = mid + 1
            }
            if (1L * order[lo] >= L) PuntL = lo
            lo = i + 1
            hi = l - 1
            while (lo < hi) {
                var mid = (lo + hi + 1) / 2;
                if (1L * order[mid] <= R) lo = mid
                else hi = mid - 1
            }
            if (1L * order[lo] <= R) PuntR = lo
            if (PuntL == -1 || PuntR == -1) continue
            ans += 1L * maxOf(0, PuntR - PuntL + 1)
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

