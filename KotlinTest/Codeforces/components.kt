import java.util.Queue
import java.util.LinkedList

private const val maxn = (1e5 + 5).toInt()
private val G = Array(maxn) {mutableListOf<Int>()}
private val vis = BooleanArray(maxn) {false}
private val ans = Array(maxn) {mutableListOf<Int>()}
// my template to Kotlin Contest

fun DFS(u : Int, component : MutableList<Int>) {
    vis[u] = true
    component.add(u + 1)
    for (v in G[u]) {
        if (vis[v]) continue
        DFS(v, component)
    }
}

fun main() {
    val (n, m) = readInts()
    for (i in 0 until m) {
        var (u, v) = readInts()
        u-- ; v--
        G[u].add(v)
        G[v].add(u)
    }
    var cnt = 0
    for (i in 0 until n) {
        if (vis[i]) continue
        val path = mutableListOf<Int>()
        DFS(i, path)
        path.sort()
        ans[cnt] = path
        cnt++
    }
    println(cnt)
    for (i in 0 until cnt) {
        val l = ans[i].size
        print(l)
        for (e in ans[i]) print(" $e")
        println()
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



