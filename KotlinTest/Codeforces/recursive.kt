
fun fibo(n : Int): Int {
    if (n < 2) return 1
    return fibo(n - 1) + fibo(n - 2)
}
// my template to Kotlin Contest
fun main() {
    println("the 10-th fibonacci number is: ${fibo(10)}")
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readDouble() = readLn().toDouble()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }


