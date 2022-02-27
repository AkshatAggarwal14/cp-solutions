#![allow(dead_code, unused_macros, unused_imports)]
import java.io.BufferedReader

fun printMiddleString(S: String, T: String, N: Int) {
    val a1 = IntArray(N + 1)
    for (i in 0 until N) a1[i + 1] = S[i].toInt() - 'a'.toInt() + T[i].toInt() - 'a'.toInt()
    for (i in N downTo 1) {
        a1[i - 1] += a1[i] / 26
        a1[i] %= 26
    }
    for (i in 0..N) {
        if (((a1[i] and 1) != 0) and (i + 1 <= N)) a1[i + 1] += 26
        a1[i] /= 2
    }
    for (i in 1..N) print((a1[i] + 'a'.toInt()).toChar())
}

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    var t = 1
//    t = br.readInt()
    repeat(t) {
        val n = br.readInt()
        val s = br.readLine()
        val t = br.readLine()
        printMiddleString(s, t, n)
        println()
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

