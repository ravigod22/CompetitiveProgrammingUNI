
// my template to Kotlin Contest

fun ask(l: Int, r: Int): Int{
    println("? ${l} ${r}")
    System.out.flush()
    var x = readInt()
    return x
}

fun main() {
    var t = readInt()
    for (x in 0 until t) {
        val n = readInt()
        var cnt = MutableList(n) {0}
        for (i in 1 until n) {
            var res = ask(1, i + 1)
            cnt[i] = res
        }
        if (cnt[n - 1] == 0) {
            println("! IMPOSSIBLE")
            System.out.flush()
            continue
        }
        var ind = 1
        while (ind < n && cnt[ind] == 0) {
            ind += 1
        }
        var s: String = ""
        for (i in 0 until (ind - cnt[ind])) s += "1"
        for (i in (ind - cnt[ind]) until ind) s += "0"
        for (i in ind until n) {
            if (cnt[i - 1] == cnt[i]) s += "0"
            else s += "1"
        }
        println("! ${s}")
        System.out.flush()
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



