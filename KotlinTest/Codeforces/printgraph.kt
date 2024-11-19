
private val maxn = (1e5 + 10).toInt()
private val G = Array(maxn) {mutableListOf<Int>()}

fun main() {
    G[1].add(2)
    G[2].add(1)
    G[3].add(2)
    G[2].add(3)
    for (i in 0 until 4) {
        /* the first way to print the adjacency list
        print("node $i -> [")
        for (j in G[i]) {
            print("$j ")
        }
        println("]")
        */
        /* the short way to print the adjacency list
        println("node $i -> ${G[i]}")
        */
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


