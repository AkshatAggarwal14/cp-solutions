#![allow(dead_code, unused_macros, unused_imports)]
import java.io.BufferedReader
import kotlin.math.*

fun main() {
    val br = System.`in`.bufferedReader()
//    val sb = StringBuilder()
    var t = 1
//    t = br.readInt()
    repeat(t) {
        var n = br.readInt()
        var a = (mutableListOf(0) + MutableList(n) { br.readInt() }).toMutableList()
        val inf = (1 shl 30)
        var dp = MutableList(n + 1) { mutableListOf(-inf, inf) }
        var p = MutableList(n + 1) { mutableListOf(-1, -1) }
        dp[1] = mutableListOf(inf, -inf)
        p[1] = mutableListOf(0, 0)
        fun upd(i: Int, x: Int, now: Int, nxt: Int) {
            if ((nxt == 0 && x > dp[i][0]) || (nxt == 1 && x < dp[i][1])) {
                dp[i][nxt] = x
                p[i][nxt] = now
            }
        }
        for (i in 1 until n) {
            if (p[i][0] != -1) {
                if (a[i] < a[i + 1]) upd(i + 1, dp[i][0], 0, 0)
                if (dp[i][0] > a[i + 1]) upd(i + 1, a[i], 0, 1)
            }
            if (p[i][1] != -1) {
                if (dp[i][1] < a[i + 1]) upd(i + 1, a[i], 1, 0)
                if (a[i] > a[i + 1]) upd(i + 1, dp[i][1], 1, 1)
            }
        }
        if (p[n][0] != -1 || p[n][1] != -1) {
            var t = (if (p[n][0] != -1) 0 else 1)
            var res = MutableList(n + 1) { 0 }
            for (i in n downTo 1) {
                res[i] = t
                t = p[i][t]
            }
            print("YES\n")
            for (i in 1..n) print("${res[i]} ")
            print("\n")
        } else print("NO\n")
    }
//    println(sb)
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

