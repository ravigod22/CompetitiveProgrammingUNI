
fun main() {
    val a = intArrayOf(3, 1, 5, 7, 8, 9)
    // One way to get prefix sums 
    val prefixSums = a.scan(0, Int::plus)
    //val prefixSums = a.scan(0, {x, y -> x + y})
    println(prefixSums)

    // Anothe way to get prefix sums instead use method from source code
    val prefixSums2 = mutableListOf<Int>(0)
    val n = a.size
    for (i in 0 until n) {
        prefixSums2.add(prefixSums2.last() + a[i])
    }
    println(prefixSums2)
}
