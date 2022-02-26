#![allow(dead_code, unused_macros, unused_imports)]
import java.io.BufferedReader
import kotlin.math.*


fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    var t = 1
//    t = br.readInt()
    repeat(t) {
        var n = br.readInt()
        var a = IntArray(n) { br.readInt() }
        var ans = 0
        // shuffle and sort array
        a.shuffle()
        a.sort()
        var prev = 0
        for (i in 0 until n) {
            // check the
            // decremented value
            if (prev < a[i] - 1) {
                ans++
                prev = a[i] - 1
            } else if (prev < a[i]) {
                ans++
                prev = a[i]
            } else if (prev < a[i] + 1) {
                ans++
                prev = a[i] + 1
            }
        }
        sb.appendLine(ans)
    }
    println(sb)
}

private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()

private fun BufferedReader.readInt(): Int {
    var ret: Int = read()
    while (ret <= SPACE_INT) ret = read()
    val neg = ret == '-'.toInt()
    if (neg) ret = read()
    ret -= ZERO_INT
    var read = read()
    while (read >= ZERO_INT) {
        ret *= 10
        ret += read - ZERO_INT
        read = read()
    }
    while (read <= SPACE_INT && read != -1 && read != NL_INT) {
        mark(1)
        read = read()
    }
    if (read > SPACE_INT) reset()
    return if (neg) -ret else ret
}

