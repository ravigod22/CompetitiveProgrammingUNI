fun main() {
    val t = readInt()
    repeat(t) {
        val tshirt = readStrings()
        var s1 = tshirt[0]
        var s2 = tshirt[1]
        var leng1 = s1.length
        var leng2 = s2.length
        // XXXX...XS < XXXX...S < S < M < XXXMMM
        if (s1[leng1 - 1] == s2[leng2 - 1]) {
            if (s1[leng1 - 1] == 'S') {
                if (leng1 > leng2) {
                    println("<")
                }
                else if (leng1 == leng2) {
                    println("=")
                }
                else {
                    println(">")
                } 
            }
            else if (s1[leng1 - 1] == 'M') {
                println("=")
            }
            else if (s1[leng1 - 1] == 'L') {
                if (leng1 < leng2) {
                    println("<")
                }
                else if (leng1 == leng2) {
                    println("=")
                }
                else {
                    println(">")
                }
            }

        }
        else {
            if (s1[leng1 - 1] == 'M' && s2[leng2 - 1] == 'S') {
                println(">")
            }
            else if (s1[leng1 - 1] == 'M' && s2[leng2 - 1] == 'L') {
                println("<")
            }
            else if (s1[leng1 - 1] == 'S' && s2[leng2 - 1] == 'L') {
                println("<")
            }
            else if (s1[leng1 - 1] == 'S' && s2[leng2 - 1] == 'M') {
                println("<")
            }
            else if (s1[leng1 - 1] == 'L' && s2[leng2 - 1] == 'S') {
                println(">")
            }
            else if (s1[leng1 - 1] == 'L' && s2[leng2 - 1] == 'M') {
                println(">")
            }
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
