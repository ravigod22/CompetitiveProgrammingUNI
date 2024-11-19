// my template to Kotlin Contest


fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val a = readInts()
        val aux = mutableMapOf<Int, Int>()
        for (i in 0 until n) {
            if (aux.containsKey(a[i])) {
                aux[a[i]] = aux[a[i]]!! + 1
            }
            else aux[a[i]] = 1
        }
        val cnt = aux.toSortedMap()
        var sum : Long = 0
        var tmp = 0
        for (e in cnt.values) {
            sum += 1L * e * (e - 1) * tmp / 2
            sum += 1L * e * (e - 1) * (e - 2) / 6
            tmp += e
        }
        println(sum)
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
