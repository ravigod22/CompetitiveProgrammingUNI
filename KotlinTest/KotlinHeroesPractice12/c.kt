
// my template to Kotlin Contest
fun main() {
    var t = readInt()
    for (x in 0 until t) {
        val (n, m) = readInts()
        val a = MutableList(n) {MutableList(m) {0}}
        for (i in 0 until n) {
            val aux = readInts()
            val tmp = MutableList(m) {0}
            assert(aux.size == m)
            for (j in 0 until m) {
                tmp[j] = aux[j]
            }
            tmp.sort()
            a[i] = tmp
        }
        var ans: Int = 1
        val realturn: MutableList<Int> = mutableListOf()
        for (i in 0 until m) {
            val turn: MutableList<Pair<Int, Int>> = mutableListOf()
            for (j in 0 until n) {
                turn.add(a[j][i] to j)
            }
            turn.sortBy { it.first}
            var cnt = 0
            for (j in 0 until n) {
                if (turn[j].first == cnt) cnt += 1
                else {
                    ans = 0
                    break
                }
            }
            for (j in 0 until n) {
                realturn.add(turn[j].second)
            }
            break
        }
        if (ans == 0) {
            println(-1)
            continue
        }
        var cntreal = 0
        for (i in 0 until m) {
            for (j in 0 until n) {
                if (a[realturn[j]][i] == cntreal) cntreal += 1
                else {
                    ans = 0
                    break;
                } 
            }
        }
        if (ans == 0) {
            println(-1)
        }
        else {
            for (i in 0 until n) {
                print("${realturn[i] + 1} ")
            }
            println()
        }
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




