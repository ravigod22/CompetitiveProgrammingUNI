import java.util.*
import kotlin.math.*

private fun readLn() = readLine()!!
private 
val maxn = 100 + 10
fun main() {
    var tt = readLine()!!.toInt()
    repeat (tt) {
        val n = readLine()!!.toInt()
        val a = readLine()!!.split(" ").map { it.toInt() }
        val cnt = IntArray(maxn)
        var pos = IntArray(n)
        for (i in 0 .. n - 1) {
            var x = a[i]
            pos[i] = x
            cnt[x]++
        }
        var unique: Int = 0
        for (i in 1 .. maxn) {
            if (cnt[i] != 0 && cnt[i] == 1) {
                unique = i
                break
            }
        }
        var ans: Int = 0
        for (i in 0 .. n - 1) {
            if (pos[i] == unique) {
                ans = i + 1
                break
            }
        }
        println(ans)
    }
}
