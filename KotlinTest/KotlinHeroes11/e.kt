
// my template to Kotlin Contest
fun main() {
    val t = readInt()
    repeat (t) {
        var s = readLn()
        var ans = 0
        if (s[0] == 'S') {
            s = "R" + s
        }
        else if (s[0] == 'P') {
            s = "RS" + s
        }
        val n = s.length
        var plays = mutableListOf<Char>()
        for (i in 1 until n) {
            if (s[i] == 'S') {
                plays.add('P')
            }
            else if (s[i] == 'R') {
                plays.add('S')
            }
            else {
                plays.add('R')
            }
        }
        if (s[n - 1] == 'S') plays.add('R')
        else if (s[n - 1] == 'R') plays.add('P')
        else plays.add('S')
        for (i in 0 until n) {
            if (s[i] == 'S') {
                if (plays[i] == 'P') ans--
                else if (plays[i] == 'R') ans++
            }
            else if (s[i] == 'P') {
                if (plays[i] == 'S') ans++
                else if (plays[i] == 'R') ans--
            }
            else {
                if (plays[i] == 'S') ans--
                else if (plays[i] == 'P') ans++
            }
        }
        if (ans > 0) println(s.length)
        else {
            val result = n - ans
            println(result)
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


