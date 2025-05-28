// my template to Kotlin Contest

fun ask(pos : Int): String {
    println("? ${pos}")
    System.out.flush()
    var x = readStrings()
    return x[0]
}


fun f(a: String, b: String): Boolean {
    var la = a.length
    var lb = b.length
    if (a == b) return true
    var p = 0
    while (p < minOf(la, lb)) {
        if (a[p] < b[p]) {
            return false
        }
        else if (a[p] > b[p]) {
            return true
        }
        p += 1
    }
    if (p == la) return false
    if (p == lb) return true
    return true
}

fun main() {
    var a = readStrings()
    var n = a[0].toInt()
    var exist = MutableList(n + 1) {"-1"}
    // verificate if upper case > lower case
    var l = ask(1)
    exist[1] = l
    var r = ask(n)
    var cnt = 0
    exist[n] = r
    cnt += 2
    if (l[0].isLowerCase() && r[0].isLowerCase()) {
        var lo = 1
        var hi = n
        while (lo < hi) {
            var mid = (lo + hi) / 2
            if (exist[mid] == "-1") {
                exist[mid] = ask(mid)
                cnt += 1
            }
            if (f(exist[mid], a[1])) hi = mid
            else lo = mid + 1
        }
        print("! ${lo}")
        System.out.flush()
    }
    else if (l[0].isUpperCase() && r[0].isUpperCase()) {
        var lo = 1
        var hi = n
        while (lo < hi) {
            var mid = (lo + hi) / 2
            if (exist[mid] == "-1") {
                exist[mid] = ask(mid)
                cnt += 1
            }
            if (f(exist[mid], a[1])) hi = mid
            else lo = mid + 1
        }
        print("! ${lo}")
        System.out.flush()
    }
    else if (l[0].isUpperCase() && r[0].isLowerCase()) {
        if (a[1][0].isLowerCase()) {
            var lo = 1
            var hi = n
            while (lo < hi) {
                var mid = (lo + hi) / 2
                if (exist[mid] == "-1") {
                    exist[mid] = ask(mid)
                    cnt += 1
                }
                if (exist[mid][0].isLowerCase()) {
                    if (f(exist[mid], a[1])) hi = mid
                    else lo = mid + 1
                }
                else lo = mid + 1
            }
            print("! ${lo}")
            System.out.flush()
        }
        else {
            var lo = 1
            var hi = n
            while (lo < hi) {
                var mid = (lo + hi) / 2
                if (exist[mid] == "-1") {
                    exist[mid] = ask(mid)
                    cnt += 1
                }
                if (exist[mid][0].isLowerCase()) hi = mid - 1
                else {
                    if (f(exist[mid], a[1])) hi = mid
                    else lo = mid + 1
                }
            }
            print("! ${lo}")
            System.out.flush()
        }
    }
    else if (l[0].isLowerCase() && r[0].isUpperCase()){
        if (a[1][0].isLowerCase()) {
            var lo = 1
            var hi = n
            while (lo < hi) {
                var mid = (lo + hi) / 2
                if (exist[mid] == "-1") {
                    exist[mid] = ask(mid)
                    cnt += 1
                }
                if (exist[mid][0].isUpperCase()) hi = mid - 1
                else {
                    if (f(exist[mid], a[1])) hi = mid
                    else lo = mid + 1
                }
            }
            print("! ${lo}")
            System.out.flush()
        }
        else {
            var lo = 1
            var hi = n
            while (lo < hi) {
                var mid = (lo + hi) / 2
                if (exist[mid] == "-1") {
                    exist[mid] = ask(mid)
                    cnt += 1
                }
                if (exist[mid][0].isLowerCase()) lo = mid + 1
                else {
                    if (f(exist[mid], a[1])) hi = mid
                    else lo = mid + 1
                }
            }
            print("! ${lo}")
            System.out.flush()
        }
    }
    assert (cnt <= 10)
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readDouble() = readLn().toDouble()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }



