import java.io.BufferedReader
import kotlin.math.max
import kotlin.math.min
 
fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    var t = 1
    // t = br.readInt()
        val n = br.readInt()
        val a = IntArray(n) { br.readInt() }
        val freq: MutableMap<Int, Int> = HashMap()
        for (x in a) {
            var count = freq[x]
            if (count == null) count = 0
            freq[x] = count + 1
        }
        var ans = true
        for((x, y) in freq){
            if (y > 2){
               ans = false 
            }
        }
        if(!ans) {
            sb.appendLine("NO")
        }else{
        var A = ArrayList<Int>()
        var B = ArrayList<Int>()
        for((x, y) in freq){
            when(y){
                1 -> A.add(x)
                2 ->{ 
                    A.add(x)
                    B.add(x)
                }
            }
        }
        sb.appendLine("YES")
        sb.appendLine(A.size)
        A.sort()
        for(x in A){
            sb.append(x.toString() + " ")    
        }
        sb.appendLine("")
        B.sortDescending()
        sb.appendLine(B.size)
        for(x in B){
            sb.append(x.toString() + " ")    
        }
        sb.appendLine("")
    }
    println(sb)
}
 
private const val SPACE_INT = ' '.toInt()
private const val ZERO_INT = '0'.toInt()
private const val NL_INT = '\n'.toInt()
 
private fun BufferedReader.readInt(): Int {
    var ret = read()
    while (ret <= SPACE_INT) {
        ret = read()
    }
    val neg = ret == '-'.toInt()
    if (neg) {
        ret = read()
    }
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
    if (read > SPACE_INT) {
        reset()
    }
    return if (neg) -ret else ret
}

