#![allow(dead_code, unused_macros, unused_imports)]
import java.io.BufferedReader
import kotlin.math.*

fun to_binary(n: Int): ArrayDeque<Int> {
    var res = ""
    var x = n
    while (x > 0) {
        res += (x % 2)
        x /= 2
    }
    var ans = ArrayDeque<Int>()
    for (i in res.length - 1 downTo 0) {
        if (res[i] == '0') continue
        ans.add(1 shl i)
    }
    return ans
}

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    var t = 1
//    t = br.readInt()
    repeat(t) {
        var n = br.readInt()
        var k = br.readInt()
        var dq = to_binary(n)
        if (dq.size > k) {
            sb.appendLine("NO")
        } else {
            var left = k - dq.size
            while ((left > 0) and (dq.isEmpty().not()) and (dq.first() != 1)) {
                var top = dq.removeFirst()
                if (top / 2 == 1) {
                    dq.addLast(1);
                    dq.addLast(1);
                } else {
                    dq.addFirst(top / 2);
                    dq.addFirst(top / 2);
                }
                --left
            }
            if (dq.size == k) {
                sb.appendLine("YES")
                sb.appendLine(dq.joinToString(" "))
            } else {
                sb.appendLine("NO")
            }
        }
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

