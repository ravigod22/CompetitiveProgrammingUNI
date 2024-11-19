

fun main() {
    var arr1 = arrayOf(1, 2, 3)
    var arr2 = arrayOf(4, 5, 6)

    arr1 = arr2.also {arr2 = arr1}
    for (e in arr2) println(e)
}

